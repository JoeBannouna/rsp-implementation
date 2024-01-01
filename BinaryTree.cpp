#include "BinaryTree.hpp"

Node::Node(int item) {
  this->left = NULL;
  this->right = NULL;
  this->item = item;
}

Node* Node::search(int item) {
  if (item < this->item && this->left != NULL)
    return this->left->search(item);

  else if (item > this->item && this->right != NULL)
    return this->right->search(item);

  else if (item == this->item)
    return this;

  return NULL;
}

// Internal search function for tracking the last 'valid' node before finding no results
// (used in insertion function)
Node* Node::parent_search(int item) {
  if (item < this->item && this->left != NULL && item != this->left->item)
    return this->left->parent_search(item);

  else if (item > this->item && this->right != NULL && item != this->right->item)
    return this->right->parent_search(item);

  return this;
}

Node* Node::findMin() {
  if (this->left == NULL) return this;
  return this->left->findMin();
}

Node* Node::findMax() {
  if (this->right == NULL) return this;
  return this->right->findMax();
}

// Can pass in function 'process' to process every node traversed as desired
void Node::traverse(void (*process)(Node* node)) {
  if (this->left != NULL) this->left->traverse(process);
  process(this);
  if (this->right != NULL) this->right->traverse(process);
}

int Node::getItem() { return this->item; }
Node* Node::getLeft() { return this->left; }
Node* Node::getRight() { return this->right; }

void Node::setItem(int item) { this->item = item; }
void Node::setLeft(Node* left) { this->left = left; }
void Node::setRight(Node* right) { this->right = right; }

BinaryTree::BinaryTree() {
  this->head_node = NULL;
  this->nodes_num = 0;
}

void deleteTreeProcess(Node* node) { delete node; }

BinaryTree::~BinaryTree() {
  if (this->head_node != NULL) this->head_node->traverse(deleteTreeProcess);
}

Node* BinaryTree::search(int item) { return this->head_node == NULL ? NULL : this->head_node->search(item); }

Node* BinaryTree::findMin() { return this->head_node == NULL ? NULL : this->head_node->findMin(); }
Node* BinaryTree::findMax() { return this->head_node == NULL ? NULL : this->head_node->findMax(); }

void BinaryTree::traverse(void (*process)(Node* node)) {
  if (this->head_node != NULL) this->head_node->traverse(process);
}

Node* BinaryTree::insert(int item) {
  // New tree instance
  Node* new_node = new Node(item);

  if (this->head_node == NULL) {
    this->head_node = new_node;
    return new_node;
  }

  // This is the parent of the item we're about to insert
  Node* last_valid_node = this->head_node->parent_search(item);

  if (item < last_valid_node->getItem()) last_valid_node->setLeft(new_node);
  if (item > last_valid_node->getItem()) last_valid_node->setRight(new_node);

  this->nodes_num += 1;
  return new_node;
}

// Could implement parent-pointers to perform only one search operation instead of two
// However time complexity would stay O(h) either way, h = height of the tree
void BinaryTree::del(Node* node) {
  // This is the parent of the item we're about to delete
  Node* parent_node = this->head_node->parent_search(node->getItem());

  // No children for the to-be-deleted node
  if (node->getLeft() == NULL && node->getRight() == NULL) {
    if (node->getItem() < parent_node->getItem()) parent_node->setLeft(NULL);
    if (node->getItem() > parent_node->getItem()) parent_node->setRight(NULL);

    delete node;
  }

  // Two children for the to-be-deleted node
  else if (!(node->getLeft() == NULL || node->getRight() == NULL)) {
    cout << "Two children" << endl;
    Node* parent_of_deletion_replacement;
    bool one_node_right_subtree = false;

    if (node->getRight()->getLeft() == NULL) {
      one_node_right_subtree = true;
      parent_of_deletion_replacement = node;
    } else {
      parent_of_deletion_replacement = node->getRight();

      // get the parent node for the node that will replace the to-be-deleted node
      if (parent_of_deletion_replacement->getLeft() != NULL)
        while (parent_of_deletion_replacement->getLeft()->getLeft() != NULL) {
          parent_of_deletion_replacement = parent_of_deletion_replacement->getLeft();
        }
    }

    cout << "parent_of_deletion_replacement: " << parent_of_deletion_replacement->getItem() << endl;

    Node* replacement_node =
        one_node_right_subtree ? parent_of_deletion_replacement->getRight() : parent_of_deletion_replacement->getLeft();

    // Set the parent node to link to the new replacement
    if (this->head_node == node) {
      this->head_node = replacement_node;
    } else {
      if (node->getItem() < parent_node->getItem()) parent_node->setLeft(replacement_node);
      if (node->getItem() > parent_node->getItem()) parent_node->setRight(replacement_node);
    }

    // Make replacement node link to the nodes that the old node linked to
    if (node->getRight() == replacement_node) {
    } else {
      replacement_node->setLeft(node->getLeft());
      replacement_node->setRight(node->getRight());
    }

    // Delete replacement link to itself to prevent infinite loops
    // Delete the link of the replacement-node parent to its child to prevent inifinite loops
    if (one_node_right_subtree)
      replacement_node->setLeft(parent_of_deletion_replacement->getLeft());
    else
      parent_of_deletion_replacement->setLeft(NULL);

    delete node;
  }

  // Only one child for the to-be-deleted node
  else {
    if (node->getLeft() != NULL) {
      if (node->getItem() < parent_node->getItem()) parent_node->setLeft(node->getLeft());
      if (node->getItem() > parent_node->getItem()) parent_node->setRight(node->getLeft());

      delete node;
    }
    if (node->getRight() != NULL) {
      if (node->getItem() < parent_node->getItem()) parent_node->setLeft(node->getRight());
      if (node->getItem() > parent_node->getItem()) parent_node->setRight(node->getRight());

      delete node;
    }
  }
}


// FOR TESTING
void printSpaces(int length) {
  if (length != 0) {
    cout << " ";
    printSpaces(length - 1);
  }
}

void BinaryTree::bfs() {
  int level = 1;
  vector<Node*> vec;
  stack<Node*> stk;
  vec.push_back(this->head_node);
  bool can_print_more = true;
  while (can_print_more) {
    for (auto&& i : vec) {
      printSpaces(this->nodes_num * level / 4);
      cout << i->getItem();
      printSpaces(this->nodes_num * level / 4);

      if (i->getLeft() != NULL) stk.push(i->getLeft());
      if (i->getRight() != NULL) stk.push(i->getRight());
    }
    cout << endl;

    if (stk.empty())
      can_print_more = false;
    else {
      vec.clear();
      while (!stk.empty()) {
        vec.push_back(stk.top());
        stk.pop();
      }
    }
    level++;
  }
}