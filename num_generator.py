import random

f = open("nums.txt", "w")
for i in range(15*10**4):
    amount = random.randint(1, 9)
    for j in range(amount):
        print(str(random.randint(0, 9)), file=f, end="")
    print(file=f)
f.close()