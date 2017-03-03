"""
dP[i], has the max sum
"""

def maxSubArray(nums):
    maxSum = 0
    sum = 0
    for num in nums:
        sum += num
        if maxSum < sum:
            maxSum = sum
        elif sum < 0:
            sum = 0
    return maxSum

print(maxSubArray([2,-8,3,-2,4,-10]))