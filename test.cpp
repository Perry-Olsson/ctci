#include <iostream>
#include "string_array_solutions.h"
#include "linked_lists-solutions.h"

using namespace std;

int main() {
  int nums[10] = {3, 5, 4, 3, 2, 1, 5, 6, 3 , 4};
  LinkedList *  myList = new LinkedList(nums[0]);


  for (int i = 1; i < sizeof(nums)/sizeof(nums[0]); i++) {
    myList->add(nums[i]);
  }

  cout << myList->remove() << endl;
  printf("\n");
  Node* current = myList->head;
  while (current != nullptr) {
    printf("%i\n", current->value);
    current = current->next;
  }

  delete myList;
  return 0;
}
