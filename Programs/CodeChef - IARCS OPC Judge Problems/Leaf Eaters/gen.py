from random import randint, choice

n, k = randint(10, 5000000), randint(1,19)
print(n,k)
for i in range(1,k+1):
    print(randint(1,n))
