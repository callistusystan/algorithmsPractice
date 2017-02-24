def rob(nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    n = len(nums)
    if n == 0:
        return 0
    elif n == 1:
        return nums[0]

    dP = [0]*(n)
    dP[0] = nums[0]
    dP[1] = max(nums[0], nums[1])
    for i in range(2, n):
        dP[i] = max(dP[i - 2] + nums[i], dP[i - 1])
    return dP[n-1]

print(rob([100, 200,200]))