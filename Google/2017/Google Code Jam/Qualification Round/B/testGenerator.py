from random import randint

with open("generatedInput.txt", "w") as f:
    f.write("100\n")
    for i in range(100):
        f.write(str(randint(1,9)))
        for i in range(17):
            f.write(str(randint(0,9)))
        f.write("\n")
