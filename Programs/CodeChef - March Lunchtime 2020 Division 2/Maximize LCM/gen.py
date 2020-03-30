from random import randint, choice

n, m = randint(2, 2), randint(3, 3)
print(n, m)

for _ in range(n):
    k, a, b, c, d = randint(2, 7), randint(2, 2), randint(1, 5), randint(2, 6), randint(3, 4)
    print(k, a, b, c, d)
