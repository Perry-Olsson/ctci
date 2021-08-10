from linked_lists.Node import Node

class AnimalShelter:
  def __init__(self):
    self.__head = None
    self.__end = self.__head

  def output(self):
    print(self.__head)

  def enqueue(self, animal):
    if animal != "d" and animal != "c":
      raise Exception("This shelter only takes dogs and cats")
    if self.__head is None:
      self.__head = Node(animal)
      self.__end = self.__head
    else:
      self.__end.next = Node(animal)
      self.__end = self.__end.next
    pass
  
  def dequeueAny(self):
    if self.__head is None:
      raise Exception("Out of animals!")
    data = self.__head.value
    if self.__head == self.__end:
      self.__end = self.__head.next

    self.__head = self.__head.next    

    return data

  def dequeueDog(self):
    current = self.__head
    parent = None
    while current is not None and current.value == "c":
      parent = current
      current = current.next
    
    if current is None:
      raise Exception("No dogs!")

    if self.__head.value == "d":
      return self.dequeueAny()

    parent.next = current.next
    return "d"

  def dequeueCat(self):
    current = self.__head
    parent = None
    while current is not None and current.value == "d":
      parent = current
      current = current.next
    
    if current is None:
      raise Exception("No Cats!")

    if self.__head.value == "c":
      return self.dequeueAny()
    
    parent.next = current.next
    return "c"
  
  



