def coinChange(coins, amount):
    """
    :type coins: List[int]
    :type amount: int
    :rtype: int
    """
    inf = float('inf')
    m = len(coins)
    n = amount + 1
    dP = [0] + [inf]*amount

    for j in range(coins[0], n):
        dP[j] = dP[j-coins[0]] + 1

    for i in range(1, m):
        for j in range(1, n):
            if j >= coins[i]:
                dP[j] = min(dP[j], dP[j-coins[i]] + 1)

    if dP[n-1] == inf:
        return -1
    return dP[n - 1]


print(coinChange([2,5,10,1], 27))