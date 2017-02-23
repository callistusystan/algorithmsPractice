"""
1 -> 2 -> 3 -> 4

node3
    node3.val = node4.val
    node3.nex = node4.next
"""

def deleteNode(node):
    node.val = node.next.val
    node.next = node.next.next