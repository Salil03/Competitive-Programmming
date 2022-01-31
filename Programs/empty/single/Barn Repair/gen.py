import random

m = random.randint(2, 20)
print(m)

s = random.randint(20, 50)
print(s)

c = random.randint(2, s-2)
print(c)
arr = random.sample(range(1,s), c)
for num in arr:
    print(num)

