def numSquares(n):
    """
    :type n: int
    :rtype: int
    """
    perfectSquares = [1]
    p = 2
    dp = [0]

    for i in range(1, n+1):
        if i >= p*p:
            perfectSquares.append(p*p)
            p += 1
        minNumber = dp[i-perfectSquares[0]] + 1
        for square in perfectSquares:
            minNumber = min(minNumber, dp[i-square] + 1)
        dp.append(minNumber)
    return dp[n]

print(numSquares(10))