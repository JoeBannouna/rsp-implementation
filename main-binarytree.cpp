#include <iostream>

#include "BinaryTree.hpp"

using std::cout;
using std::endl;

bool compare(int item1, int item2) { return item1 > item2; }
void printTreeNode(Node* node) { cout << node->getItem() << " "; }

void printTree(BinaryTree* tree) {
  cout << "{ ";
  tree->traverse(printTreeNode);
  cout << "}" << endl;
}

int main() {
  BinaryTree* tree = new BinaryTree();
  printTree(tree);

  Node* node1 = tree->insert(10);
  Node* node2 = tree->insert(12);
  Node* node3 = tree->insert(9);
  Node* node4 = tree->insert(15);
  Node* node5 = tree->insert(7);
  Node* node6 = tree->insert(4);
  Node* node7 = tree->insert(13);
  Node* node8 = tree->insert(29);
  Node* node9 = tree->insert(18);
  Node* node10 = tree->insert(31);
  Node* node11 = tree->insert(19);
  Node* node12 = tree->insert(16);
  Node* node13 = tree->insert(20);
  Node* node14 = tree->insert(11);
  Node* node15 = tree->insert(33);

  printTree(tree);

  cout << "Tree min: " << (tree->findMin() == NULL ? INT32_MIN : tree->findMin()->getItem()) << endl;
  cout << "Tree min: " << (tree->findMax() == NULL ? INT32_MAX : tree->findMax()->getItem()) << endl;

  tree->del(node1);
  printTree(tree);
 
  tree->del(node6);
  printTree(tree);

  Node* search_node;

  search_node = tree->search(10);
  cout << "Node " << (search_node == NULL ? "not" : std::to_string(search_node->getItem())) << " found" << endl;

  search_node = tree->search(11);
  cout << "Node " << (search_node == NULL ? "not" : std::to_string(search_node->getItem())) << " found" << endl;
}