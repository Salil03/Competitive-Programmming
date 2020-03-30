from random import randint, choice

n = randint(3, 3)
print(n)

for _ in range(n):
    m, k, a = randint(1, 7), randint(2, 8), randint(3, 9)
    print(m, k, a)
