"""

"""

class Tower:
    def __init__(self, index):
        self.discs = []
        self.index = index

    def getIndex(self):
        return self.index

    def add(self, d):
        if len(self.discs) and d > self.discs[-1]:
            raise Exception("Cannot put a bigger disc on a smaller disc")
        self.discs.append(d)

    def moveTopTo(self, t):
        top = self.discs.pop()
        t.add(top)

    def moveDiscs(self, n, destination, buffer, stacks):
        if n > 0:
            self.moveDiscs(n-1, buffer, destination, stacks)
            self.moveTopTo(destination)
            print([stacks[0].discs, stacks[1].discs, stacks[2].discs])
            buffer.moveDiscs(n-1, destination, self, stacks)

towers = []
for i in range(3):
    towers.append(Tower(i))

n = 4
for i in range(n-1, -1, -1):
    towers[0].add(i)

print("Hey! I'm gna move {} discs from {} to {} using {} as a buffer".format(n, 0, 2, 1))
towers[0].moveDiscs(n, towers[2], towers[1], towers)

print(towers[2].discs)