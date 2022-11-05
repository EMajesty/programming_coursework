from tkinter import *
from random import randint

class Game:
    def __init__(self, parent):
        self.num1 = IntVar()
        self.num2 = IntVar()

        self.newNumbers()

        self.l_num1 = Label(textvariable=self.num1, height=2, width=2)
        self.l_num1.grid(column=0, row=0)

        self.l_plus = Label(text="+", height=2, width=2)
        self.l_plus.grid(column=1, row=0)

        self.l_num2 = Label(textvariable=self.num2, height=2, width=2)
        self.l_num2.grid(column=2, row=0)

        self.l_equ = Label(text="=", height=2, width=2)
        self.l_equ.grid(column=3, row=0)

        self.entry = Entry()
        self.entry.grid(column=4, row=0)

        self.l_check = Label(height=2, width=16)
        self.l_check.grid(row=1, columnspan=5)

        self.b_check = Button(text="Check answer", height=2, width=16, command=self.checkAnswer)
        self.b_check.grid(row=2, columnspan=5)

    def newNumbers(self):
        self.num1.set(randint(1,99))
        self.num2.set(randint(1,99))
    
    def checkAnswer(self):
        #print("checkanswer")
        #print("correct:", self.num1.get() + self.num2.get())
        #print("answer:", self.entry.get())

        if int(self.entry.get()) == self.num1.get() + self.num2.get():
            self.correctAnswer()            
        else:
            self.wrongAnswer()
            
    def correctAnswer(self):
        #print("correct")
        self.l_check.config(text="Correct")

        self.newNumbers()
        self.entry.delete(0, 'end')

    def wrongAnswer(self):
        #print("wrong")
        self.l_check.config(text="Wrong")

        self.entry.delete(0, 'end')

root = Tk()
myapp = Game(root)
root.mainloop()