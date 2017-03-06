class Heap:
    def __init__(self):
        self.capacity = 1
        self.size = 0
        self.items = [None]*100

    def __len__(self):
        return self.size

    def increaseCapacity(self):
        if self.size == self.capacity:
            self.items += [None]*self.capacity
            self.capacity *= 2

    def isEmpty(self):
        return len(self) == 0

    def getLeftChildIndex(self, index):
        return index*2 + 1

    def getRightChildIndex(self, index):
        return index * 2 + 2

    def getParentIndex(self, index):
        return (index-1)//2

    def getLeftChild(self, index):
        return self.items[self.getLeftChildIndex(index)]

    def getRightChild(self, index):
        return self.items[self.getRightChildIndex(index)]

    def getParent(self, index):
        return self.items[self.getParentIndex(index)]

    def hasLeftChild(self, index):
        return self.getLeftChildIndex(index) <= len(self)

    def hasRightChild(self, index):
        return self.getRightChildIndex(index) <= len(self)

    def hasParent(self, index):
        return self.getParentIndex(index) >= 0

    def swap(self, i, j):
        tmp = self.items[i]
        self.items[i] = self.items[j]
        self.items[j] = tmp

    def put(self, data):
        self.increaseCapacity()
        self.items[self.size] = data
        self.size += 1
        self.rise(self.size-1)

    def peek(self):
        assert not self.isEmpty(), "Heap is empty"
        return self.items[0]

    def poll(self):
        assert not self.isEmpty(), "Heap is empty"
        item = self.items[0]
        self.items[0] = self.items[self.size-1]
        self.size -= 1
        self.sink(0)
        return item

    def rise(self, index):
        while self.hasParent(index) and self.getParent(index) > self.items[index]:
            self.swap(index, self.getParentIndex(index))
            index = self.getParentIndex(index)

    def sink(self, index):
        while self.hasLeftChild(index):
            smallerChildIndex = self.getLeftChildIndex(index)

            if self.hasRightChild(index) and self.getRightChild(index) < self.getLeftChildIndex(index):
                smallerChildIndex = self.getRightChildIndex(index)

            if self.items[index] <= self.items[smallerChildIndex]:
                break
            else:
                self.swap(index, smallerChildIndex)
            index = smallerChildIndex

myHeap = Heap()
myHeap.put(5)
myHeap.put(4)
myHeap.put(3)
myHeap.put(2)
myHeap.put(1)
print(myHeap.poll())
print(myHeap.poll())
print(myHeap.poll())
print(myHeap.poll())
print(myHeap.poll())