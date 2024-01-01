#pragma once

#include <iostream>

using std::cout;
using std::endl;

class LinkedList {
 private:
  bool is_head;
  LinkedList* next;
  int item;

 protected:
  LinkedList* listAhead(int item);
  LinkedList* listAhead(int item, bool (*comp_func)(int search_item, int list_item));
  LinkedList(int item);

 public:
  LinkedList();
  ~LinkedList();

  // O(n)
  LinkedList* search(int item, bool (*comp_func)(int search_item, int list_item));
  LinkedList* search(int item);

  // O(1)
  void insert(int item);

  // O(n)
  bool del(int item);

  int getItem();
  void printList();

  int length();
  
  LinkedList* getNext();
};
