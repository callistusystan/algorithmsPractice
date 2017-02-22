from heapq import heappush, heappop
from random import randint

def maxheappush(maxHeap, number):
    heappush(maxHeap, -number)

def maxheappop(maxHeap):
    if len(maxHeap):
        return -heappop(maxHeap)
    return None

def maxheappeak(maxHeap):
    return -maxHeap[0]

def maxheaplist(maxHeap):
    return [-i for i in maxHeap]

class MedianContainer:
    def __init__(self):
        self.minHeap = []
        self.maxHeap = []

    def addNumber(self, number):
        if len(self.minHeap) == len(self.maxHeap):
            if len(self.minHeap) and number > self.minHeap[0]:
                maxheappush(self.maxHeap, heappop(self.minHeap))
                heappush(self.minHeap, number)
            else:
                maxheappush(self.maxHeap, number)
        else:
            if number < self.maxHeap[0]:
                heappush(self.minHeap, heappop(self.maxHeap))
                maxheappush(self.maxHeap, number)
            else:
                heappush(self.minHeap, number)

    def getMedian(self):
        if len(self.maxHeap) == 0:
            return self.minHeap[0]
        elif len(self.minHeap) == 0:
            return maxheappeak(self.maxHeap)

        if len(self.maxHeap) == len(self.minHeap):
            return (self.minHeap[0] + maxheappeak(self.maxHeap))/2
        elif len(self.maxHeap) > len(self.minHeap):
            return maxheappeak(self.maxHeap)
        else:
            return self.minHeap[0]

    def getNumbers(self):
        return self.minHeap + maxheaplist(self.maxHeap)

myMedianContainer = MedianContainer()
for _ in range(10):
    number = randint(1,100)
    myMedianContainer.addNumber(number)
    print(myMedianContainer.getNumbers())
    print(myMedianContainer.getMedian())
    print()