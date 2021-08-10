from Node import *

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

def checkForLoopRunner(head):
  if head.next is None:
    return None
  slow, fast = head.next, head.next.next
  while slow != fast:
    if fast is None or fast.next is None:
      return None
    slow = slow.next
    fast = fast.next.next
  slow = head
  while slow != fast:
    slow = slow.next
    fast = fast.next
  return slow

#add loop

index = 0
loopNode = None
current = sample_list
while current.next is not None:
  if index == 3:
    loopNode = current
  index += 1
  current = current.next

current.next = loopNode

print(sample_list)


val = checkForLoopRunner(sample_list)
if val is not None:
  print(val.value)
else:
  print(val)