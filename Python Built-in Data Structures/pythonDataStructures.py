from random import randint
aList = [1,2,3,4]
nElements = 20

# List
print("List")
myList = [1,2,3,4]
print(myList)

print("\nAdding 5 to list")
myList.append(5)
print(myList)

print("\nRemoving 5 from list")
myList.remove(5)
print(myList)

# Stack
print("\nStack")
myStack = []
for i in aList:
    myStack.append(i)
print(myStack)

print("\nAdding 5 to stack")
myStack.append(5)
print(myStack)

print("\nPopping all from stack")
for i in range(5):
    print(myStack.pop())

# Queue
print("\nQueue")
from collections import deque
myQueue = deque(aList)
print(myQueue)

print("\nAdding 5 to queue")
myQueue.append(5)
print(myQueue)

print("\nServing all from queue")
for i in range(5):
    print(myQueue.popleft())

# Dictionary
print("\nDictionary")
myDict = { 'a': 1, 'b': 2, 'c': 3, 'd': 4, 'e': 5 }
print(myDict)

print("\nIs 'a' in dictionary?")
print('a' in myDict)

print("\nDeleting 'a' from dictionary")
if 'a' in myDict:
    del myDict['a']
print(myDict)

print("\nSetting value of 'a' to 10")
myDict['a'] = 10
print(myDict)
# myDict.keys(), myDict.values()

# Set
print("\nSet")
mySet = {1, 2, 3, 4}
print(mySet)

print("\nAdding 5 to set")
mySet.add(5)
print(mySet)

print("\nDiscard 5 from set")
mySet.discard(5)
print(mySet)

# Min Heap
from heapq import heappush, heappop
print("\nMin Heap")

def heappeek(myHeap):
    return myHeap[0]

myMinHeap = []
for i in [randint(1,100) for _ in range(nElements)]:
    heappush(myMinHeap, i)
print(myMinHeap)

print("\nPopping all from min heap")
for i in range(len(myMinHeap)):
    print(heappop(myMinHeap))

# Max Heap
def maxHeapPush(myHeap, data):
    heappush(myHeap, -data)

def maxHeapPeek(myHeap):
    return -myHeap[0]

def maxHeapPop(myHeap):
    return -heappop(myHeap)

print("\nMax Heap")
myMaxHeap = []
for i in [randint(1,100) for _ in range(nElements)]:
    maxHeapPush(myMaxHeap, i)
print([-i for i in myMaxHeap])

print("\nPopping all from max heap")
for i in range(len(myMaxHeap)):
    print(maxHeapPop(myMaxHeap))