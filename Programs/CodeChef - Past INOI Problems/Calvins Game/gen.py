from random import randint, choice

n, m = randint(5, 3000), randint(1, 3000)
print(n, m)

for _ in range(n):
    k = randint(-1000, 1000)
    print(k)