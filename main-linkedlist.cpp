#include <iostream>

#include "LinkedList.hpp"

using std::cout;
using std::endl;

bool compare(int item1, int item2) { return item1 > item2; }

int main() {
  LinkedList* test = new LinkedList();
  test->printList();

  test->insert(10);
  test->insert(11);
  test->insert(12);
  test->insert(13);
  test->printList();

  cout << "Deletion was " << (test->del(10) ? "successful" : "unsuccessful") << endl;
  test->printList();

  LinkedList* element;

  element = test->search(10);
  cout << "Element " << (element == NULL ? "not" : std::to_string(element->getItem())) << " found" << endl;

  element = test->search(13, compare);
  cout << "Element " << (element == NULL ? "not" : std::to_string(element->getItem())) << " found" << endl;
}