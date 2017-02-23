def binarySearch(array, target):
    lo = 0
    hi = len(array)-1

    while lo <= hi:
        mid = (lo+hi)//2
        if array[mid] == target:
            return mid
        elif target < array[mid]:
            hi = mid - 1
        else: # target > array[mid]
            lo = mid + 1
    return -1

aList = [i for i in range(100)]
print(binarySearch(aList, 5))
print(binarySearch(aList, 100))