from random import randint, choice

n = randint(4, 4)
print(n)

for _ in range(n):
    m, k = randint(2, 8), randint(1, 8)
    print(m, k)
