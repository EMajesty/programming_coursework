from math import acos, degrees

print("Give the lengths of a triangle's sides:")
A = float(input("a: "))
B = float(input("b: "))
C = float(input("c: "))

aA = degrees(acos((B*B + C*C - A*A) / (2.0 * B * C)))
aB = degrees(acos((C*C + A*A - B*B) / (2.0 * C * A)))
aC = 180 - aA - aB

print(aA,aB,aC)
if aA == 90 or aB == 90 or aC == 90:
    print("The triangle is right-angled")
if A == B and A == C:
    print("The triangle is equilateral")
elif A == B or A == C or B == C:
    print("The triangle is isosceles")
elif A != B or A != C:
    print("The triangle is scalene")