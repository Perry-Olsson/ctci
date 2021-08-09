class LinkedList {
  constructor(value = null) {
    this.head = new Node(value);
    this.end = this.head;
  }

  add(value) {
    this.end.next = new Node(value);
    this.end = this.end.next;
  }

  shift() {
    this.head = this.head.next;
    return this.head;
  }
}

class Node {
  constructor(value = null, next = null) {
    this.value = value;
    this.next = next;
  }
}

const nums = [3, 5, 2, 4, 6, 4, 3, 2, 1];

const myList = new LinkedList(nums[0]);
myList.add(nums[1]);
for (let i = 2; i < nums.length; i++) {
  myList.add(nums[i]);
}

myList.shift();
let current = myList.head;
while (current !== null) {
  console.log(current.value);
  current = current.next;
}
