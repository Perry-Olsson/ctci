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

head = Node(3)

restNums = [5, 8, 5, 10, 2, 1]

current = head
for num in restNums:
  current.next = Node(num)
  current = current.next

def swapNodeValues(one, two):
  temp = one.value
  one.value = two.value
  two.value = temp

def partitionList(head, pVal):
  current, swap = head, head
  while current is not None:
    if current.value <= pVal:
      swapNodeValues(current, swap)
      swap = swap.next
    current = current.next
  return head




def checkForLoop(head):
  current = head 
  nodeMap = {current: True}

  current = current.next
  while current is not None:
    if current in nodeMap:
      return current
    nodeMap[current] = True
    current = current.next

  return None #no loop

#add loop

index = 0
loopNode = None
current = head
while current.next is not None:
  if index == 3:
    loopNode = current
  index += 1
  current = current.next

current.next = loopNode



print(head)