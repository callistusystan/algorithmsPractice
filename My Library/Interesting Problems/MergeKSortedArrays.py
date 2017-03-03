from heapq import heappush, heappop
from math import inf

def merge(listOfLists):
    output = []
    outputLen = 0

    minHeap = []
    for i, list in enumerate(listOfLists):
        outputLen += len(list)
        heappush(minHeap, (list[0], i, 0))

    while len(output) < outputLen:
        smallest = heappop(minHeap)
        # smallest is a tuple of the format (value, listIndex, pointer)

        value, listIndex, pointer = smallest
        listToLookAt = listOfLists[listIndex]

        # append value to the newList
        output.append(value)

        # check if there is any more items in listToLookAt
        if pointer+1 < len(listToLookAt):
            heappush(minHeap, (listToLookAt[pointer+1], listIndex, pointer + 1))
        else:
            heappush(minHeap, (inf, listIndex, pointer + 1))

    return output

listOfLists = [[1,4,7], [2,5,8], [3,6,9]]
print(merge(listOfLists))