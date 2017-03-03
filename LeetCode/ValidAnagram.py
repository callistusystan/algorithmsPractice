"""
solution1
    sort s and t
    compare them

    O(S log S + T log T)

solution2
    [0,0,0,0...0]
    count characters in s
    count characters in t

    compare the frequency of all characters

    O(S + T)

optimisations
1. check len(s) == len(t)
"""

def charToIndex(c):
    return ord(c) - ord('a')

def isAnagram(s, t):
    if len(s) != len(t):
        return False

    freqCount = [0]*26

    for c in s:
        freqCount[charToIndex(c)] += 1

    for c in t:
        freqCount[charToIndex(c)] -= 1
        if freqCount[charToIndex(c)] < 0:
            return False

    return True

print(isAnagram("anagram", "nagaram"))
print(isAnagram("rat", "car"))