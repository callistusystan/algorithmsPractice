"""
Iterative solution
1 -> 2 -> 3 -> 4 -> None

newList = None
node1
    cur = node1.next = node2
    newList = node1 -> None
node2
    cur = node2.next = node3
    newList = node2 -> node1 -> None
node3
    cur = node3.next = node4
    newList = node3 -> node2 -> node1 -> None
node4
    cur = node4.next = None
    newList = node4 -> node3 -> node2 -> node1 -> None
cur is None
stop!!

O(N) time
O(1) space, N is length

Recursive
1 -> 2 -> 3 -> 4 -> None

4-> None
    return 4 -> None

3 -> 4 -> None
    return 4 -> 3 -> None


rec(
"""

def reverseList(cur):
    newListHead = None
    while cur is not None:
        next = cur.next
        cur.next = newListHead
        newListHead = cur
        cur = next
    return newListHead
