class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    def insert(self, newData):
        if newData <= self.data:
            if self.left is None:
                self.left = Node(newData)
            else:
                self.left.insert(newData)
        else:
            if self.right is None:
                self.right = Node(newData)
            else:
                self.right.insert(newData)

    def contains(self, target):
        if target == self.data:
            return True
        elif target < self.data:
            if self.left is None:
                return False
            else:
                return self.left.contains(target)
        else:
            if self.right is None:
                return False
            else:
                return self.right.contains(target)

    def printInOrder(self):
        if self.left:
            self.left.printInOrder()
        print(self.data)
        if self.right:
            self.right.printInOrder()

class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, data):
        if self.root is None:
            self.root = Node(data)
        else:
            self.root.insert(data)

    def contains(self, target):
        if self.root is None:
            return False
        return self.root.contains(target)

    def print(self):
        if self.root is None:
            return
        self.root.printInOrder()

myBinarySearchTree = BinarySearchTree()

print(myBinarySearchTree.contains(1))
myBinarySearchTree.insert(20)
myBinarySearchTree.insert(2)
myBinarySearchTree.insert(3)
myBinarySearchTree.insert(40)
myBinarySearchTree.insert(5)
print(myBinarySearchTree.contains(1))
print(myBinarySearchTree.contains(5))
print(myBinarySearchTree.contains(2))
print(myBinarySearchTree.contains(10))
print(myBinarySearchTree.print())