"""
s = "hello"
     01234
newString = "olleh"

iterate backwards
i=4
    nS = "o"
i=3
    nS = "ol"
i=2
    nS = "oll"
i=1
    nS = "olle"
i=0
    nS = "olleh"
"""

def reverseString(s):
    newStringList = []
    for i in range(len(s) - 1, -1, -1):
        newStringList.append(s[i])
    return "".join(newStringList)

print(reverseString("abcd"))