from random import randint

L = 1000

with open("generatedTest.txt", "w") as f:
    f.write("100\n")
    for _ in range(100):
        for _ in range(L):
            if randint(0,1) == 0:
                f.write("+")
            else:
                f.write("-")
        f.write(" " + str(randint(2,L//3)) +"\n");
