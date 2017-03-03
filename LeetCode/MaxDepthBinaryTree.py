"""
           a  1
       b  2     c  2
   d  3       f   3
e  4

rec(node, depth)

begin program
rec(a, 1)
    max = 4
    return 4
    rec(b,2)
        max = 4
        rec(d,3)
            max = 4
            rec(e,4)
                return 4
    rec(c,2)
        max = 3
        return 3
        rec(f,3)
            return 3
"""

def getMaxDepth(root):
    if root is None:
        return 0
    return getMaxDepthRec(node, 1)

def getMaxDepthRec(node, depth):
    maxDepth = depth
    if node.left:
        maxDepth = max(maxDepth, getMaxDepthRec(node.left, depth + 1))
    if node.right:
        maxDepth = max(maxDepth, getMaxDepthRec(node.right, depth + 1))
    return maxDepth