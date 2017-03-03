# returns the number of  possible ways to
def rec(nums, i, curVal, target, memo):
	if i == len(nums):
		if curVal == target:
			return True
		else:
			return False

	if (i, curVal) in memo:
		return memo[(i, curVal)]

	noOfWays = rec(nums, i + 1, curVal + nums[i], target, memo)
	noOfWays += rec(nums, i + 1, curVal - nums[i], target, memo)

	memo[(i, curVal)] = noOfWays

	return noOfWays

print(rec([1,1,1,1,1], 0, 0, 3, {}))