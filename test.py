file = open("input.txt", "r")

length = 0
n = 0
for line in file:
    if n == 1:
        print(line[:-1], len(line) - 1)
    length += len(str(int(line[:-1])))
    n += 1

print(length)
print(length/n)