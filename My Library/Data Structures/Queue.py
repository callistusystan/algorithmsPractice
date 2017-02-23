class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

    def __str__(self):
        return str(self.data)

class Queue:
    def __init__(self):
        self.front = None
        self.back = None

    def isEmpty(self):
        return self.front is None

    def append(self, data):
        newNode = Node(data)
        if self.front is None:
            self.front = newNode
            self.back = newNode
            return

        # otherwise, append to the back, and set the new node as the back
        self.back.next = newNode
        self.back = newNode

    def peek(self):
        return self.front

    def serve(self):
        if self.isEmpty():
            return None
        data = self.front.data
        self.front = self.front.next
        if self.front is None:
            self.back = None
        return data

    def __str__(self):
        outputString = "["
        cur = self.front

        if cur is not None:
            outputString += str(cur)
            cur = cur.next
            while cur != None:
                outputString += ", " +str(cur)
                cur = cur.next

        outputString += "]"
        return outputString

myQueue = Queue()

print(myQueue)
myQueue.append(1)
myQueue.append(2)
myQueue.append(3)
myQueue.append(4)
myQueue.append(5)
print(myQueue)
myQueue.serve()
print(myQueue)