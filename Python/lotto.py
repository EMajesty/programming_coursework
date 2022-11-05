import random
rivi = []

for i in range(1,8):
    while True:
        num = random.randint(1,40)
        if num not in rivi:
            rivi.append(num)
            break

print(rivi)