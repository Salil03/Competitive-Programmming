from random import randint, choice

n, m = randint(1, 1), randint(3, 3)
print(n, m)

for _ in range(m):
    k, a = randint(2, 10), randint(1, 2)
    print(k, a)

for _ in range(n):
    c, d = randint(3, 3), randint(1, 1)
    print(c, d)
