def swap(array, i, j):
    tmp = array[i]
    array[i] = array[j]
    array[j] = tmp

def insertionSort(array):
    for i in range(len(array)):
        item = array[i]

        j = i
        while j > 0 and array[j-1] > item:
            array[j] = array[j-1]
            j -= 1
        array[j] = item

aList = [i for i in range(10,0,-1)]
insertionSort(aList)
print(aList)