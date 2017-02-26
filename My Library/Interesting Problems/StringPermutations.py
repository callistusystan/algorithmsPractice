"""
abcd

rec(s, 0)
    [a]
    rec(s, 1)
        [ab, ba]
        rec(s, 2)
            [

"""

def getPerms(string):
    if string is None:
        return None

    permutations = []
    if len(string) == 0:
        permutations.append("")
        return permutations

    first = string[0]
    remainder = string[1:]

    words = getPerms(remainder)
    for word in words:
        for j in range(len(word)+1):
            s = insertCharAt(word, first, j)
            permutations.append(s)

    return permutations

def insertCharAt(word, c, i):
    start = word[0:i]
    end = word[i:]
    return start + c + end

print(getPerms("abcd"))