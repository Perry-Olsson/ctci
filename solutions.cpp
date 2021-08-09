#include <iostream>
#include "string_array_solutions.h"
#include "linked_lists-solutions.h"

using namespace std;

class Stack {
  int *array;
  int top;
  public:
    int capacity;
    Stack(int capacity) : capacity(capacity), top(-1) {
      int arr[capacity];
      array = arr;
    }

    int push(int val) {
      if (top == capacity - 1) {
        throw "Stack overflow";
      }

      array[++top] = val;
      return top;
    }

    int peek() {
      if (isEmpty())
        throw "Stack is empty";
      return array[top];
    }

    int pop() {
      if (isEmpty()) 
        throw "Stack is empty";
      int data = array[top];
      return --top;
    }

    bool isEmpty() {
      return top == -1;
    }
};

int main() {

  Stack* myStack = new Stack(10);

  myStack->push(4);
  myStack->push(5);
  myStack->push(10);
  myStack->pop();
  myStack->pop();



  cout << myStack->peek() << endl;
  return 0;
}
