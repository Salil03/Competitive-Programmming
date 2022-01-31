import random

t = random.randint(1, 100)
for i in range(0, t):
    l = random.randint(1, 10000)
    r = random.randint(l, 1000000000)
    print(str(l) + ' ' + str(r))
