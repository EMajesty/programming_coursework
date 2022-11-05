euros = int(input("Give amount of euros: "))

fivehundreds = int(euros / 500)
twohundreds = int((euros % 500) / 200)
hundreds = int(((euros % 500) % 200) / 100)
fifties = int((((euros % 500) % 200) % 100) / 50)
twenties = int(((((euros % 500) % 200) % 100) % 50) / 20)
tenners = int((((((euros % 500) % 200) % 100) % 50) % 20) / 10)
fivers = int(((((((euros % 500) % 200) % 100) % 50) % 20) % 10) / 5)
rest = ((((((euros % 500) % 200) % 100) % 50) % 20) % 10) % 50

print(fivehundreds,"x 500 €")
print(twohundreds,"x 200 €")
print(hundreds,"x 100 €")
print(fifties,"x 50 €")
print(twenties,"x 20 €")
print(tenners,"x 10 €")
print(fivers,"x 5 €")
print(rest,"€ in coins")
