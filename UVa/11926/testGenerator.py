from random import randint

T = 30

with open("generatedInput.txt", "w") as f:
    for i in range(T):
        f.write("100 100\n")
        for j in range(100):
            a = randint(0,1000000)
            b = min(1000000, a + randint(0, 1000000))
            f.write("{} {}\n".format(a, b))
        for j in range(100):
            a = randint(0,1000000)
            b = min(1000000, a + randint(0, 1000000))
            c = randint(0,1000000)
            f.write("{} {} {}\n".format(a, b, c))
    f.write("0 0\n")


# N = 10**18
#
# with open("generatedInput.txt", "w") as f:
#     f.write("100\n")
#     for i in range(100):
#         curN = 10**18 #randint(1,N)
#         curK = randint(1,curN)
#         f.write(str(curN))
#         f.write(" " + str(curK))
#         f.write("\n")
