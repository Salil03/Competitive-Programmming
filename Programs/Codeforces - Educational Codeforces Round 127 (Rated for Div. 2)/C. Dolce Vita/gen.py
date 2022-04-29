import random


print(10)

for i in range(0, 10):
    n, x = random.randint(1, 100), random.randint(10000, 100000000)
    arr = []
    for j in range(0, n):
        arr.append(random.randint(1, 1000))
    print(n, x, sep=" ")
    for j in arr:
        print(j, end=" ")
    print("")
