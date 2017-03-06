"""
[1,2,3]

rec(set, 0)
    rec(set, 1)
        rec(set, 2)
            rec(set, 3) = [[]]
        [[], [2]]
    [[],[3],[2],[2,3]]
[[],[3],[2],[2,3],[1],[1,3],[1,2],[1,2,3]]
"""

def getSubsetsRecursive(mySet, index):
    if index < 0:
        return [[]]
    allSubsets = getSubsetsRecursive(mySet, index-1)

    subsetsFromHere = []
    for set in allSubsets:
        subsetsFromHere.append(set + [mySet[index]])

    allSubsets += subsetsFromHere
    return allSubsets

def getSubsets(mySet):
    return getSubsetsRecursive(mySet, len(mySet) - 1)


def bitsToSet(mySet, bits):
    thisSet = []

    index = 0
    while bits > 0:
        if bits & 1:
            thisSet.append(mySet[index])
        bits >>= 1
        index += 1

    return thisSet

def getSubsetsIterative(mySet):
    allSubsets = []

    noOfSubsets = 1 << len(mySet) # 2**n

    for bits in range(noOfSubsets):
        allSubsets.append(bitsToSet(mySet, bits))

    return allSubsets


print(getSubsets([1,2,3]))
print(getSubsetsIterative([1,2,3]))