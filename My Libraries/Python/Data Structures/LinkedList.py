class SinglyNode:
    def __init__(self, data):
        self.data = data
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None
        self.size = 0

    def append(self, data):
        newNode = SinglyNode(data)
        cur = self.head

        self.size += 1

        if not cur:
            self.head = newNode
            return

        while cur.next != None:
            cur = cur.next

        cur.next = newNode

    def prepend(self, data):
        newNode = SinglyNode(data)
        cur = self.head

        self.size += 1

        if not cur:
            self.head = newNode
            return

        newNode.next = self.head
        self.head = newNode

    def __str__(self):
        outputString = "["

        cur = self.head

        if cur:
            outputString += str(cur.data)
            cur = cur.next
            while cur != None:
                outputString += ", " + str(cur.data)
                cur = cur.next

        outputString += "]"
        return outputString

myList = SinglyLinkedList()

print(myList)
myList.append(1)
myList.append(2)
myList.append(3)
myList.append(4)
myList.prepend(5)
myList.prepend(6)
myList.prepend(7)
myList.prepend(8)
print(myList)