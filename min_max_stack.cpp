#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct MinMax {
  int min;
  int max;
};

class MinMaxStack {
  vector<int> stack = {}; 
  vector<MinMax> min_max_stack = {};
  int top = -1;
  public:
    void push(int val) {
      if (min_max_stack.size()) {
        min_max_stack.push_back({ min: min(min_max_stack.at(top).min, val), max: max(min_max_stack.at(top).max, val)});
      } else {
        min_max_stack.push_back({ min: val, max: val});
      }
      stack.push_back(val);
      top++;
    }

    int pop() {
      if (isEmpty()) throw "Stack is empty";
      min_max_stack.pop_back();
      int data = stack.at(top);
      stack.pop_back();
      top--;
      return data;
    }

    int peek() {
      if (isEmpty()) throw "Stack is empty";
      return stack.at(top);
    }

    bool isEmpty() {
      if (top == -1) return true;
      return false;
    }

    int get_min() {
      if (isEmpty()) throw "Stack is empty";
      return min_max_stack.at(top).min;
    }

    int get_max() {
      if (isEmpty()) throw "Stack is empty";
      return min_max_stack.at(top).max;
    }
};

int main() {
  try {
  MinMaxStack* stack = new MinMaxStack();
  stack->push(4);
  stack->push(5);
  stack->pop();
  stack->push(2);
  cout << "min: " << stack->get_min() << endl;
  cout << "max: "<< stack->get_max() << endl;
  cout << "top: " << stack->peek() << endl;
  return 0;
  } catch(const char* msg) {
    cout << msg << endl;
  }
}

