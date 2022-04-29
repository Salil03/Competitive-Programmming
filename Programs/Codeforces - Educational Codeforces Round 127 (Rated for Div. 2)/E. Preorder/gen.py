import random
import numpy

n = random.randint(10, 18)

s = [str(random.randrange(2)) for _ in range(2**n - 1)]
print(n)
print(''.join(s).replace("1", "A").replace("0", "B"))
