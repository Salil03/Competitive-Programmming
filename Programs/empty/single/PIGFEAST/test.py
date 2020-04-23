import os
from random import seed
from random import randint
from random import random
seed(112)
for i in range(15, 16):
    value = random()
    value = randint(-123124, 2897491) + (value * (randint(-123124, 2897491) - randint(-123124, 2897491)))
    os.system("gen " + str(value) + " > " + str(i) + ".in")
    os.system("sol < " + str(i) + ".in" + " >" + str(i) + ".out")