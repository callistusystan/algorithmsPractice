class DisjointSet:
    def __init__(self, items):
        self.items = items
        self.parent = [i for i in range(len(items))]
        self.rank = [0]*len(self.items)

    def findRoot(self, i):
        if self.parent[i] != i:
            self.parent[i] = self.findRoot(self.parent[i])
        return self.parent[i]

    def union(self, i, j):
        iRoot = self.findRoot(i)
        jRoot = self.findRoot(j)

        if iRoot == jRoot:
            return

        if self.rank[iRoot] < self.rank[jRoot]:
            self.parent[iRoot] = jRoot
        elif self.rank[iRoot] > self.rank[jRoot]:
            self.parent[jRoot] = iRoot
        else:
            self.parent[jRoot] = iRoot
            self.rank[iRoot] += 1


myDisjointSet = DisjointSet([1,2,3,4])
myDisjointSet.union(0,1)

for i in range(4):
    print(myDisjointSet.findRoot(i))