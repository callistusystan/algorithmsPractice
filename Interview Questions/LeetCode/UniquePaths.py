def uniquePaths(m, n):
    """
    :type m: int
    :type n: int
    :rtype: int
    """
    if m == 1 and n == 1:
        return 1

    dP = [1]*n

    for i in range(1, m):
        for j in range(1,n):
            dP[j] = dP[j] + dP[j-1]
    return dP[n-1]

print(uniquePaths(2,2))