"""
O(N) time
O(1) space, N is length of the list
[0,1,0,3,12]
 0 1 2 3 4

front=0
i=0
    same
i=1
    [1,0,0,3,12]
    front = 1
i=2
    same
i=3
    [1,3,0,0,12]
    front = 2
i=4
    [1,3,12,0,0]
    front = 3
"""

def swap(aList, i, j):
    tmp = aList[i]
    aList[i] = aList[j]
    aList[j] = tmp

def moveZeroes(nums):
    front = 0
    for i in range(len(nums)):
        if nums[i]: # non zero
            swap(nums, i, front)
            front += 1

aList = [0,1,0,3,12]
moveZeroes(aList)
print(aList)