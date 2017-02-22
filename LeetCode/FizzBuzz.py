"""
n=15, results = []
i=1
    results = ["1"]
i=2
    results = ["1", "2"]
i=3
    results = ["1", "2", "Fizz"]
...
i=5 results = ["1", "2", "Fizz", "4", "Buzz"]
"""

def divisibleBy(a,b):
    return a%b == 0

FIZZ = "Fizz"
BUZZ = "Buzz"

def fizzBuzz(n):
    results = []

    for number in range(1,n+1):
        if divisibleBy(number,3) and divisibleBy(number, 5):
            results.append(FIZZ+BUZZ)
        elif divisibleBy(number, 3):
            results.append(FIZZ)
        elif divisibleBy(number, 5):
            results.append(BUZZ)
        else:
            results.append(str(number))

    return results

print(fizzBuzz(15))