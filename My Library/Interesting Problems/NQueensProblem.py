"""
[] <- [a,b,c,d,e,f,g,h], where index i is the ith column and
            a,b,c... is the row corresponding to the column

rec(curSolution, N)

rec([], 4)
    rec([0], 4)
        rec([0,2], 4)
            stuck
        rec([0,3], 4)
            rec([0,3,1], 4)
                stuck
            stuck
        stuck
    rec([1], 4)
        rec([1,3], 4)
            rec([1,3,0], 4)
                rec([1,3,0,2, 4)
                    true!
        rec([1,4], 4)
    rec([2], 4)
    rec([3], 4)
"""

def conflictRow(curSolution, toAddRow):
    for row in curSolution:
        if row == toAddRow:
            return True
    return False

def conflictDiagonal(curSolution, toAddRow):
    toAddCol = len(curSolution)
    for col, row in enumerate(curSolution):
        if abs(col-toAddCol) == abs(row-toAddRow):
            return True
    return False

def nQueens(curSolution, N):
    if len(curSolution) == N:
        return curSolution
    else:
        for i in range(N):
            # check valid
            if not conflictRow(curSolution, i) and not conflictDiagonal(curSolution, i):
                curSolution.append(i)
                if nQueens(curSolution, N):
                    return curSolution
                curSolution.pop()
    return None

print(nQueens([], 8))