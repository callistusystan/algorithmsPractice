import sys
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
"""

from math import inf

def bestTime(prices):
    profit = 0
    minPrice = sys.maxsize
    for price in prices:
        minPrice = min(minPrice, price)
        profit = max(profit, price-minPrice)
    return profit

print(bestTime([7,1,5,3,6,4]))
print(bestTime([7,6,4,3,1]))