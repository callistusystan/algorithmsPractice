"""
1,2,3,4,5

count all subarrays that are arithmetic slices

length 3
1,2,3 <-- if we know this is an arithmetic slice, we can use this in length 4
2,3,4 <-- ***
3,4,5 <-- ***

length 4
1,2,3,4 <-- ***
2,3,4,5 <-- ***

length 5
1,2,3,4,5

to check array of size 3, it takes 2 comparisons
to check array of size 4, it takes 3 comparisons
to check array of size N, it takes N-1 comparisons O(N)

all pairs of i,j N^2
	for each pair, check if nums[i..j] is an arithmetic slice O(N)

O(N^3)

[1,2,3,4,5]
	check if [3,4,5] is an arithmetic slice

	0..2 diff is 1

[1,2,3,4,5]
	check if [2,3,4], [3,4,5], [2,3,4,5] are arithmetic slices

	i = 0
	j = 3

	0..2 diff is 1

	nums[1] - nums[0], diff = 1
	check if 1..3 has diff of 1
	if the diff matches,
		increase totalNumber by what 1..3 returns

	return totalNumbers

if [a,b,c] is an arithmetic slice
	i can prepend all arithmetic slices starting from b with a
	[b,c,d]
	c-b == b-a


[1,2,3,4,5]
	i = 0
	j = 4

	0..2
		return 1

	if i..i+2 returns 1
		noOfWays += 1
		noOfWay += all the arithmetic slices starting from i+1
"""

def countArithmeticSlices(nums):
	n = len(nums)
	if n <= 2:
		return 0

	total = 0

	for i in range(n-2):
		total += countArSlicesStartingAtI(nums, i, {})

	return total

def countArSlicesStartingAtI(nums, i, memo):
	# [0,1,2,3,4,5]
	if len(nums) - i < 3:
		return 0

	# 3 elements or more
	if i in memo:
		return memo[i]

	startWithArithmeticSlice = nums[i+1] - nums[i] == nums[i+2] - nums[i+1]

	if startWithArithmeticSlice:
		memo[i] = 1 + countArSlicesStartingAtI(nums, i+1, memo)
		return memo[i]
	else:
		memo[i] = 0
		return 0

print(countArithmeticSlices([1,3,3,4,5]))