input = set()

with open("./day1.txt") as f:
    for line in f.readlines():
        input.add(int(line.strip()))

# Part 1
for a in input:
    if 2020 - a in input:
        print(a *  (2020 - a))
        break

