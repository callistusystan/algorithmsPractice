"""
solution1
iterate everything, stop after realising an element appeared more than
N//2 times
O(N), N is length of list
O(c), c is number of unique characters

[1,1,2]
 0 1 2
from collections import defaultdict

freqCount = defaultdict(int)
freqCount['a'] += 1 => freqCount['a'] = 1

i=0
    freqCount[1] += 1 = 1
    is freqCount[1] more than 1?
i=1
    freqCount[1] += 1 = 2
    yes! return 1

[1,1,1,2]

i=1
    freqCount > 2?
i=2
    freqCount > 3? yes, return 1
"""

from collections import defaultdict

def majorityElement(nums):
    freqCount = defaultdict(int)
    for c in nums:
        freqCount[c] += 1
        if freqCount[c] > len(nums)//2:
            return c
    raise Exception("Hey! There isn't any majority element :(")

print(majorityElement([1,1,2]))