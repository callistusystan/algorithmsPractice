"""
s = "abc"

gP(s,"")
    gP(s, "a")
        gP(s, "ab")
            gP(s, "abc")
        gP(s, "ac")
            gP(s, "acb")
    gP(s, "b")
        gP(s, "ba")
            gP(s, "bac")
        gP(s, "bc")
            gP(s, "bca")
    gP(s, "c")
        gP(s, "ca")
            gP(s, "cab")
        gP(s, "cb")
            gP(s, "cba")
"""

def stringPermutations(string, curString):
    # 3*2*1 = O(S*N!)
    if len(curString) == len(string):
        print(curString)
    else:
        for c in string: # O(S), where S is the number of characters in string
            if c not in curString: # O(S), where S is the number of characters in string
                stringPermutations(string, curString + c)

def charToIndex(c):
    return ord(c) - ord('a')

def stringPermutationsOptimised(string):
    charFreq = [0]*26
    for c in string:
        charFreq[charToIndex(c)] += 1
    stringPermutationsOptimisedRecursive(charFreq, len(string), "")

def stringPermutationsOptimisedRecursive(charFreq, length, curString):
    # TODO: think of a better name
    if len(curString) == length:
        print(curString)
    else:
        for c in range(26):
            if charFreq[c]:
                charFreq[c] -= 1
                stringPermutationsOptimisedRecursive(charFreq, length, curString + chr(c+97))
                charFreq[c] += 1

# instead of string, use a [0,0,0,0...0], initialised to the frequency count of string
# each time we pass, we decrement the freq of the char we picked
# each time we return from the recursive call, we restore it by incrementing

stringPermutationsOptimised("abcd")