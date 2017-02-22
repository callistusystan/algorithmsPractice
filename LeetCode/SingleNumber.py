"""
solution1
O(N) time
O(N) space

[1,1,2]
 0 1 2
appeared = {}
i=0, appeared = {}
    did 1 appear? no
i=1, appeared = {1}
    did 1 appear? yes
i=2, appeared = {}
    did 2 appear? no

appeared = {2}
return whats left in appeared

solution2
appeared = 0
i=0, a= 0
    a = 0^1
i=1,
    a = 0^1^1
i=2,
    a = 0^1^1^2

a=0^1^1^2
1^1 cancels out

a = 0^2 = 2
"""

def solution1(nums):
    appeared = set()
    for i in nums:
        if i in appeared:
            appeared.discard(i)
        else:
            appeared.add(i)
    return appeared.pop()

def solution2(nums):
    appeared = 0
    for i in nums:
        appeared ^= i
    return i

print(solution1([1,1,2]))
print(solution2([1,1,2]))