#include <iostream>

class Node {
  public:
    int value;
    Node *next;
    Node(int value, Node * next = nullptr) {
      this->value = value;
      this->next = next;
    }
};

class LinkedList {
  public:
    Node* head;
    Node* end;
    LinkedList(int val) {
      Node* node = new Node(val);
      head = node;
      end = node;
    }

    void add(int val) {
      end->next = new Node(val);
      end = end->next;
    }

    int remove() {
      int val = head->value;
      Node * temp = head;
      head = head->next;
      delete temp;
      return val;
    }

   ~LinkedList() {
     Node* current = head;
     while(current != nullptr) {
       Node* temp = current->next;
       delete current;
       current = temp;
     }
     delete current;
   } 
};
