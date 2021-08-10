class Node:
  def __init__(self, value, next = None):
    self.value = value
    self.next = next
  
  def __repr__(self):
    current = self
    string = ""
    nodeMap = {}
    idx = 0
    while current is not None:
      if current in nodeMap:
        string += "loop({0}) at index: {1}".format(current.value, nodeMap[current])
        return string
      string += str(current.value)
      string += "->"
      nodeMap[current] = idx
      current = current.next
      idx += 1
    string += "None"
    return string

sample_list = Node(3)

restNums = [5, 8, 5, 10, 2, 1, 3]

current = sample_list
for num in restNums:
  current.next = Node(num)
  current = current.next