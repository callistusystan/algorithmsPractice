from random import randint

T = 200

with open("generatedInput.txt", "w") as f:
    f.write(str(T) + "\n")
    curN = 100
    curK = 1
    for i in range(T):
        f.write(str(curN))
        f.write(" " + str(curK))
        f.write("\n")
        curK += 1
        if curK > curN:
            curN += 1
            curK = 1

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
