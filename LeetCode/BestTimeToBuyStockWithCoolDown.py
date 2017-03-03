def maxProfit(prices):
    n = len(prices)

    if n == 0 or n == 1:
        return 0
    elif n == 2:
        return prices[1] - prices[0] if prices[1] > prices[0] else 0

    buy = [0] * (n)
    sell = [0] * (n)

    # base case
    buy[0] = -prices[0]
    buy[1] = max(-prices[1], -prices[0])

    sell[0] = 0

    for i in range(1, n):
        sell[i] = max(sell[i - 1], buy[i - 1] + prices[i])
        if i >= 2:
            buy[i] = max(buy[i - 1], sell[i - 2] - prices[i])
    return sell[n - 1]

print(maxProfit([2,1,4,5,2,9,7]))