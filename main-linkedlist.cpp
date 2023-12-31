#include <iostream>

#include "LinkedList.hpp"

using std::cout;
using std::endl;

int main() {
  int num = 19;
  LinkedList* test = new LinkedList(num);
  // for (int i = 0; i < 12; i++) {
  //   test->insert(i);
  // }

  // test->printList();

  test->del(10);
  test->printList();

  LinkedList* element = test->search(19);

  cout << (element == NULL ? "Element not found" : "Element found") << endl;

  cout << endl;
}