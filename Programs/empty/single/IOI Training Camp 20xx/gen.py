from random import randint, choice

n, m = randint(1, 9990), randint(0, 100)
print(n, m)

for _ in range(n):
    k = randint(-9990, 9990)
    print(k)
