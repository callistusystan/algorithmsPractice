def charToIndex(char):
    return ord(char) - ord('a')

class Node:
    def __init__(self, data):
        self.data = data
        self.children = [None]*26
        self.noOfChildren = 0

    def getNode(self, char):
        return self.children[charToIndex(char)]

    def setNode(self, char, node):
        self.children[charToIndex(char)] = node

    def add(self, string, index):

class Trie:
    def __init__(self):
        
