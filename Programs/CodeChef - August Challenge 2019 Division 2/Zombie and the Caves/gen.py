from random import randint, choice

n, m, k = randint(2, 2), randint(5, 5), randint(1, 1)
print(n, m, k)

for _ in range(m):
    a, b, c, d = randint(1, 5), randint(2, 5), randint(1, 5), randint(2, 5)
    print(a, b, c, d)
