#include <iostream>

#include "LinkedList.hpp"

using std::cout;
using std::endl;

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
  cout << (element == NULL ? "Element '10' not found" : "Element '10' found") << endl;
  
  element = test->search(11);
  cout << (element == NULL ? "Element '11' not found" : "Element '11' found") << endl;
}