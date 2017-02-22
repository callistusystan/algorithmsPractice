def swap(array, i, j):
    tmp = array[i]
    array[i] = array[j]
    array[j] = tmp

def bubbleSort(array):
    isSorted = False
    n = len(array)
    while not isSorted:
        isSorted = True
        for i in range(n-1):
            if array[i] > array[i+1]:
                swap(array, i, i+1)
                isSorted = False
        n -= 1

aList = [i for i in range(10,0,-1)]
bubbleSort(aList)
print(aList)