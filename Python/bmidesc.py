height = float(input("Enter height in meters: "))
weight = float(input("Enter weight in kgs: "))
bmi = weight / (height ** 2)

print("BMI is:",bmi)

if bmi < 15:
    print("Very severely underweight")
elif 15 <= bmi < 16:
    print("Severely underweight")
elif 16 <= bmi < 18.5:
    print("Underweight")
elif 18.5 <= bmi < 25:
    print("Normal")
elif 25 <= bmi < 30:
    print("Overweight")
elif 30 <= bmi < 35:
    print("Moderately obese")
elif 35 <= bmi < 40:
    print("Severely obese")
elif 40 <= bmi:
    print("Very severely obese")
