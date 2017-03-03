"""
[7,1,5,3,6,4]
 0 1 2 3 4 5

profit = 0, where i'th item is the max profit of day i

min = inf
i=0
    min = 7
    profit = 0
i=1
    min = 1
    profit = 0
i=2
    min = 1
    5 - 1
    profit = 4
i=3
    min = 1
    profit = 4
i=4
    min = 1
    6 - 1
    profit = 5
i=5
    min = 1
    profit = 5
profit[i] = max(profit[i-1], price[i] - min(price[0..i-1])

notice profit[i] only cares about profit[i-1]
    we can just use one variable for profit and update it each time
notice min(price[0..i-1]), we can simplify it
    we can just use one variable to keep the min price
"""

def bestTime(prices):
    profit = 0
    minPrice = float('inf')
    for price in prices:
        # minPrice right now is min(price[0..i-1])
        # profit[i] = max(profit[i-1], price[i] - minPrice)
        profit = max(profit, price-minPrice)

        # set minPrice to min(price[0..i])
        minPrice = min(minPrice, price)
    return profit

print(bestTime([7,1,5,3,6,4]))
print(bestTime([7,6,4,3,1]))