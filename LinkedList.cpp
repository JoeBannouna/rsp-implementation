#include "LinkedList.hpp"

LinkedList::LinkedList(int item) {
  this->item = item;
  this->next = NULL;
}

LinkedList::~LinkedList() {};

int LinkedList::getItem() { return this->item; }

LinkedList* LinkedList::listAhead(int item) {
  if (this->next != NULL && item != this->next->getItem()) {
    if (this->next->next != NULL) {
      return this->next->listAhead(item);
    }
    return NULL;
  }

  return this;
}

LinkedList* LinkedList::listAhead(int item, bool (*comp_func)(int search_item, int list_item)) {
  if (!comp_func(item, this->next->getItem())) {
    if (this->next->next != NULL) {
      return this->next->listAhead(item, comp_func);
    }
    return NULL;
  }

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
  LinkedList* temp = this->next;
  this->next = new LinkedList(this->getItem());
  this->next->next = temp;
  this->item = item;
}

// O(n)
bool LinkedList::del(int item) {
  LinkedList* list_ahead = this->listAhead(item);
  if (list_ahead != NULL) {
    LinkedList* temp = list_ahead->next;
    if (list_ahead->next->next != NULL) list_ahead->next = list_ahead->next->next;
    delete temp;
  }

  return false;
}

void LinkedList::printList() {
  LinkedList* curr = this;
  cout << "{" << curr->getItem();
  curr = curr->next;

  while (curr != NULL) {
    cout << ", " << curr->getItem();
    curr = curr->next;
  }

  cout << "}" << endl;
}