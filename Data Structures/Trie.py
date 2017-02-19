def charToIndex(char):
    return ord(char) - ord('a')

class Node:
    def __init__(self):
        self.children = [None]*26
        self.noOfChildren = 0

    def getNode(self, char):
        return self.children[charToIndex(char)]

    def setNode(self, char, node):
        self.children[charToIndex(char)] = node

    def add(self, string, index):
        self.noOfChildren += 1
        if index == len(string):
            return
        curChar = string[index]
        child = self.getNode(curChar)

        if child is None:
            self.setNode(curChar, Node())
            child = self.getNode(curChar)
        child.add(string, index+1)

    def getNoOfAppearances(self, string, index):
        if (index == len(string)):
            return self.noOfChildren
        curChar = string[index]
        child = self.getNode(curChar)

        if child is None:
            return 0
        return child.getNoOfAppearances(string, index+1)

    def __str__(self):
        return "A WILD NODE APPEARS"

class Trie:
    def __init__(self):
        self.root = Node()

    def add(self, string):
        self.root.add(string,0)

    def getNoOfAppearances(self, prefix):
        return self.root.getNoOfAppearances(prefix, 0)

myTrie = Trie()
myTrie.add("abcde")
myTrie.add("apple")
print(myTrie.getNoOfAppearances("a"))
print(myTrie.getNoOfAppearances("ab"))