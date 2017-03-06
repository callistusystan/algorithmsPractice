"""
A * B + C

A B * C +

Code follows http://csis.pace.edu/~wolf/CS122/infix-postfix.htm
"""

def isOperator(op):
    return op in "+-*/"

def getOpRank(op):
    if op in "()":
        return 0
    elif op in "+-":
        return 1
    return 2

def inFixToPostFix(inFix):
    postFix = ""
    opStack = []
    for c in inFix:
        if c.isalnum():
            postFix += c
        elif isOperator(c): # is operand
            # if stack is empty, append
            # elif c has lower or equal precedence to stack's top, pop
            # else append
            if len(opStack) and getOpRank(c) <= getOpRank(opStack[-1]):
                postFix += opStack.pop()
            opStack.append(c)
        else: # is ( or )
            # if c is a ), pop all ops until (
            if c == "(":
                opStack.append(c)
            else:
                while opStack[-1] != "(":
                    postFix += opStack.pop()
                opStack.pop()

    while len(opStack):
        postFix += opStack.pop()

    return postFix

print(inFixToPostFix("(A+D)*(B+C*F)"))