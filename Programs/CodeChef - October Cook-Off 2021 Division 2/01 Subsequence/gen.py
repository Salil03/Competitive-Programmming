import random
import numpy as np
import sys
t = 1
print(t)
for i in range(0, t):
    n = random.randint(1, 100)
    print(n)
    arr = np.random.randint(1, 1000, (1, n))
    np.savetxt(sys.stdout, arr, newline=' ', fmt="%i")
    print("")
