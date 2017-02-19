# print
print("Printing with formatting")
print("{} has {} apples.".format("John", 2))

from collections import Counter
print("\nCounter (Frequency Dictionary)")
print(Counter("ABCDE"))

# enumerate
print("\nEnumeration")
for i, item in enumerate(["First", "Second", "Third", "Fourth"]):
    print(i, item)

# combinations
from itertools import combinations
print("\nCombinations")
for c in combinations([1,2,3,4,5], 3):
    print(''.join([str(i) for i in c]))

# permutations
from itertools import permutations
print("\nPermutations")
for p in permutations([1,2,3,4]):
    print(''.join(str(i) for i in p))