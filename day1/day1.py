from itertools import product

input = set()

with open("./day1.txt") as f:
    for line in f.readlines():
        input.add(int(line.strip()))

# Part 1
for a in input:
    if 2020 - a in input:
        print(a *  (2020 - a))
        break

# Part 2
for a, b in product(input, input):
    if 2020 - a - b in input:
        print(a * b * (2020 - a - b))
        break
