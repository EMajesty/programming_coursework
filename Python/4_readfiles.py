def printLargest(filename):
    with open(filename) as file_object:
        lines = file_object.readlines()
    strippedLines = []
    for line in lines:
        line = line.rstrip("\n")
        strippedLines.append(line.split(', '))
    print("The largest population in the list is ")
    print(max(strippedLines))
    file_object.close()
    return

def printPopulation(filename, country):
    with open(filename) as file_object:
        lines = file_object.readlines()
    strippedLines = []
    for line in lines:
        line = line.rstrip("\n")
        strippedLines.append(line.split(', '))
    for line in strippedLines:
        if country in line:
            print(line)
    file_object.close()
    return

def addCountry(filename, country, population):
    with open(filename, 'a') as file_object:
        file_object.write("\n")
        file_object.write(country)
        file_object.write(", ")
        file_object.write(population)
    file_object.close()
    return

printPopulation("countries.txt", "Montserrat")
printLargest("countries.txt")
addCountry("countries.txt", "Tuvalu", "11792")