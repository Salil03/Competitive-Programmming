from random import randint, choice

n = randint(2, 20)
print(n)

for _ in range(n):
    s = ''.join([choice("ACGU") for _ in range(randint(2, 20))])
    print(s)
