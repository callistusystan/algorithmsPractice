def addParen(list, leftRem, rightRem, str, index):
    if leftRem < 0 or rightRem < leftRem:
        return

    if leftRem == 0 and rightRem == 0:
        list.append(''.join(str))
    else:
        str[index] = '('
        addParen(list, leftRem - 1, rightRem, str, index + 1)

        str[index] = ')'
        addParen(list, leftRem, rightRem - 1, str, index + 1)

def generateParents(count):
    str = [None]*(count*2)
    list = []
    addParen(list, count, count, str, 0)
    return list

print(generateParents(5))