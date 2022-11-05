speed = int(input("Give speed in km/h: "))
distance = int(input("Give distance in km: "))

time = distance / speed
hours = int(time)
minutes = int((time*60) % 60)

print("Time in hours:", time)

print("Time in whole hours and minutes:",hours,":",minutes)
