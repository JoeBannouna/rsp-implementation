#pragma once

#include <iostream>
#include <stack>
#include <vector>

using std::cout;
using std::endl;
using std::stack;
using std::vector;

class Node {
 private:
  int item;
  Node* left;
  Node* right;

 public:
  Node(int item);
  Node* parent_search(int item);
  Node* search(int item);
  Node* findMin();
  Node* findMax();
  void traverse(void (*process)(Node* node));
  int getItem();
  Node* getLeft();
  Node* getRight();

  void setItem(int item);
  void setLeft(Node* left);
  void setRight(Node* right);
};

class BinaryTree {
 private:
  Node* head_node;
  int nodes_num;

 public:
  BinaryTree();
  ~BinaryTree();
  Node* search(int item);
  Node* findMin();
  Node* findMax();
  void traverse(void (*process)(Node* node));
  Node* insert(int item);
  void del(Node* node);
  void bfs();
};