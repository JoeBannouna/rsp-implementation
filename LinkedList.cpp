#include "LinkedList.hpp"

// Constructor for creating a new linked list head
LinkedList::LinkedList() {
  this->item = 999;
  this->next = NULL;
  this->is_head = true;
}

// Protected constructor only used when inserting
LinkedList::LinkedList(int item) {
  this->item = item;
  this->next = NULL;
  this->is_head = false;
}

LinkedList::~LinkedList() {
  // If the linked list instance being deleted is the head,
  // recursively delete the entire linked list
  if (this->is_head && this->next != NULL) {
    this->next->is_head = true;
    delete this->next;
  }
};

// Get the item in the current instance
int LinkedList::getItem() { return this->item; }

LinkedList* LinkedList::listAhead(int item) {
  // If item ahead is NULL, return Null pointer
  if (this->next == NULL) return NULL;

  // If item ahead is not the item we're looking for, check the next item
  if (item != this->next->getItem()) return this->next->listAhead(item);

  // If item matches out search, return the LinkedList pointer to it
  return this;
}

LinkedList* LinkedList::listAhead(int item, bool (*comp_func)(int search_item, int list_item)) {
  // If item ahead is NULL, return Null pointer
  if (this->next == NULL) return NULL;

  // If item ahead is not the item we're looking for, check the next item
  if (!comp_func(item, this->next->getItem())) return this->next->listAhead(item, comp_func);

  // If item matches out search, return the LinkedList pointer to it
  return this;
}

LinkedList* LinkedList::search(int item, bool (*comp_func)(int search_item, int list_item)) {
  LinkedList* list = this->listAhead(item, comp_func);
  if (list != NULL) return list->next;

  return NULL;
}

LinkedList* LinkedList::search(int item) {
  LinkedList* list = this->listAhead(item);
  if (list != NULL) return list->next;

  return NULL;
}

// Order not specified, so insert at start of list
void LinkedList::insert(int item) {
  LinkedList* new_list = new LinkedList(item);
  LinkedList* temp = this->next;

  // Make the head point to the new linkedList
  this->next = new_list;

  // Make the new LinkedList point to the former 'first' linkedList
  this->next->next = temp;
}

// O(n)
bool LinkedList::del(int item) {
  LinkedList* list_ahead = this->listAhead(item);
  if (list_ahead != NULL) {
    // Store the to-be-deleted linkedList in a temp variable
    LinkedList* temp = list_ahead->next;
    // Link the linkedList that appears before the to-be-deleted linkedlist
    // to the one that appears after
    if (list_ahead->next->next != NULL)
      list_ahead->next = list_ahead->next->next;
    else
      list_ahead->next = NULL;
    // Free the to-be-deleted list from memory
    delete temp;

    return true;
  }

  return false;
}

void LinkedList::printList() {
  LinkedList* curr = this->next;

  cout << "{";
  if (curr != NULL) {
    cout << curr->item;
    curr = curr->next;
  }

  while (curr != NULL) {
    cout << ", " << curr->getItem();
    curr = curr->next;
  }

  cout << "}" << endl;
}

int LinkedList::length() {
  int i = 0;
  LinkedList* curr;
  
  while (curr != NULL) {
    curr = curr->next;
    i++;
  }

  return i;
}

LinkedList* LinkedList::getNext() {
  // cout << (this->next == NULL) << endl;
  return this->next;
}