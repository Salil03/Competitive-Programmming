import random

t = random.randint(1, 10)
print(t)
for i in range(0,t):
    l, s =  random.randint(1, 6), random.randint(1, 50)
    print(str(l) + " " +str(s) + "\n")
