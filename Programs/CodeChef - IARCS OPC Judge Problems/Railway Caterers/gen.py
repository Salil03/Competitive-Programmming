from random import randint, choice

n, m = randint(2, 20), randint(1, n-1)
print(n, m)

for _ in range(n):
    k = randint(-1000, 1000)
    print(k)
