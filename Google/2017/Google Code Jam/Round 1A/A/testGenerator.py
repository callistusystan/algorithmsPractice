from random import randint

T = 100

with open("generatedTest.txt", "w") as f:
    f.write("100\n")
    for _ in range(100):
        f.write("12 12\n")
        n = 0
        for _ in range(12):
            for _ in range(12):
                if (n < 26 and randint(0,100) < 30):
                    f.write(chr(n+97))
                    n += 1
                else:
                    f.write("?")
            f.write("\n")
