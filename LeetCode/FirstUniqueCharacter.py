"""
unique character appears only once
first unique character

s = "leetcode"
     01234567

defaultdict(int) -> 0

freqCount = {}
i=0
    {l: 1}
i=1
    {l:1, e:1}
i=2
    {l:1,e:2}
i=3
    {l:1,e:2,t:1}
...

i=0
    is freqCount[l] == 1? Yes
        return 0
..
i=7
return -1
"""

from collections import defaultdict

def firstUniqueChar(s):
    freqCount = defaultdict(int)
    for c in s:
        freqCount[c] += 1
    for i, c in enumerate(s):
        if freqCount[c] == 1:
            return i
    return -1

print(firstUniqueChar("leetcode"))
print(firstUniqueChar("loveleetcode"))