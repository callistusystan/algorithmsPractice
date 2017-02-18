# List
print("List")
myList = [1,2,3,4,5]
print(myList)

print(myList.pop(0))
print(myList.pop())

# Dictionary
print("\nDictionary")
myDict = { 'a': 1, 'b': 2, 'c': 3, 'd': 4, 'e': 5 }

print(myDict)
print('a' in myDict)
# myDict.keys(), myDict.values()
if 'a' in myDict:
    del myDict['a']
print(myDict)

# Set
print("\nSet")
mySet = {1,2,3}
mySet.add(4)
mySet.discard(3)

# Min Heap
from heapq import heappush, heappop
print("\nMin Heap")

def heappeek(myHeap):
    return myHeap[0]

myHeap = []
for i in [5,4,3,2,1]:
    heappush(myHeap, i)

print(myHeap)

print(heappop(myHeap))

# Max Heap
def maxHeapPush(myHeap, data):
    heappush(myHeap, -data)

def maxHeapPeek(myHeap):
    return -myHeap[0]

def maxHeapPop(myHeap):
    return -heappop(myHeap)

print("\nMax Heap")
myHeap = []
for i in [1,2,3,4,5]:
    maxHeapPush(myHeap, i)

print(myHeap)
print(maxHeapPop(myHeap))