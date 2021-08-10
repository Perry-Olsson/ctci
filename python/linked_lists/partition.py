from Node import *

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

print(sample_list)

print(partitionList(sample_list, 5))