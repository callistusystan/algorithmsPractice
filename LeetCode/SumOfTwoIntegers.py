"""
a = 01
b = 10
    11

a = 11
b = 11
   110

First add the numbers, then add the carry
Keep doing it until carry = 0, then u have ur number!

Adding with bitwise
  0 1
0 0 1
1 1 0

0^0 = 0
0^1 = 1
1^0 = 1
1^1 = 0

Carry with bitwise
  0 1
0 0 0
1 0 1

0&0=0
0&1=0
1&0=0
1&1=1

===

a = 4
b = 6
    2
"""

def getSum(a, b):
    if b == 0:
        return a
    else:
        return getSum(a^b, (a&b)<<1)

print(getSum(-1,-3))