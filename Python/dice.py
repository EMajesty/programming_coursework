from random import randint

i = 0
j = 1

heitot = [0,0,0,0,0,0]

while i <= 100:
    value = randint(1,6)
    heitot[value-1] += 1
    i += 1

print(heitot)