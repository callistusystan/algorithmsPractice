"""
A = 1
B = 2
Z = 26

AA = 27 = 1*26 + 1
AZ = 52 = 1*26 + 26 = 52

BA = 53 = 2*26 + 1 = 53
BZ = 2*26 + 26 = 78

s = "AA"

number = 0
multiplier = 1
i=1
    number += 1*1 = 1
    i *= 26 = 26
i=0
    number +1 1*26 = 27
    i *= 26 =26^2 // BigInteger
return number
"""

def letterToVal(c):
    return ord(c) - ord("A") + 1

def titleToNumber(s):
    number = 0
    base = 1
    # TODO: find the proper name
    for i in range(len(s)-1, -1, -1):
        c = s[i]
        number += letterToVal(c)*base
        base *= 26

    return number

print(titleToNumber("BA"))