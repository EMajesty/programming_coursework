inputSeconds = int(input("Give amount of seconds: "))

hours = int((inputSeconds / 60) / 60)
minutes = int((inputSeconds / 60) % 60)
seconds = int(inputSeconds % 60)

print(hours,"h",minutes,"m",seconds,"s")
