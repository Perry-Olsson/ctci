#include <iostream>

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