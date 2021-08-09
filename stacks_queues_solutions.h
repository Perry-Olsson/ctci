class Stack {
  public:
    int * array;
    int size;
    int top;
    Stack(int * array, int size, int top = 0) : array(array), size(size) , top(top) {
    }
};