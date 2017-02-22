"""
[1,2,3,4,4]
 0 1 2 3 4

solution1
    O(N^2) time, where N is length of the list
    O(1) space
    i=0
        compare with indices 1,2,3,4
        (0,1),(0,2)...
    i=1
        compare with indices 2,3,4
    i=2
        compare with indices 3,4
    i=3
        compare with indices 4
        match at 4, return True

solution2
    appeared = {}
    i=0, appeared = {}
        is 1 in appeared? no
    i=1, appeared = {1}
        is 2 in appeared? no
    i=2, appeared = {1,2}
        is 3 in appeared? no
    i=3, appeared = {1,2,3}
        is 4 in appeared? no
    i=4, appeared = {1,2,3,4}
        is 4 in appeared? yes
        return True

    O(N) time, N is length of list
    O(c) space, c is the number of unique characters
"""

def containsDuplicate(aList):
    appeared = set()
    for number in aList:
        if number in appeared: # O(1)
            return True
        appeared.add(number)
    return False

print(containsDuplicate([1,2,3,4,4]))