import random
import numpy as np

t = random.randint(1, 1000)
print(t)
for i in range(t):
    n = random.randint(1, 50)
    print(n)
    perm = np.random.permutation(n) + 1
    print(' '.join(map(str, perm)))
