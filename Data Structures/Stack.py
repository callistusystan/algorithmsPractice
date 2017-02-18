class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

    def __str__(self):
        return str(self.data)

class Stack:
    def __init__(self):
        self.top = None

    def isEmpty(self):
        return self.top is None

    def push(self, data):
        # otherwise, create node that points to current top, set as top
        newNode = Node(data)
        newNode.next = self.top
        self.top = newNode

    def peek(self):
        if self.isEmpty():
            return None
        return self.top.data

    def pop(self):
        # if empty, return None
        if self.isEmpty():
            return None

        # otherwise, return top's data and set top to next
        data = self.top.data
        self.top = self.top.next

        return data

    def __str__(self):
        outputString = "Stack:\n"

        cur = self.top

        if cur is not None:
            while cur is not None:
                outputString += str(cur) + "\n"
                cur = cur.next

        return outputString

myStack = Stack()

print(myStack)
myStack.push(1)
myStack.push(2)
myStack.push(3)
myStack.push(4)
myStack.push(5)
print(myStack)
myStack.pop()
print(myStack)