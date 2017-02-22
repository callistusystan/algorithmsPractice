def swap(array, i, j):
    tmp = array[i]
    array[i] = array[j]
    array[j] = tmp

def selectionSort(array):
    for i in range(len(array)):
        minItemIndex = i
        for j in range(i, len(array)):
            if array[j] < array[minItemIndex]:
                minItemIndex = j
        swap(array, i, minItemIndex)

aList = [i for i in range(10,0,-1)]
selectionSort(aList)
print(aList)