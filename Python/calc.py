from tkinter import *


class Calc:
    def __init__(self, parent):
        self.screenVal = StringVar()


        self.screen = Label(textvariable=self.screenVal, height=2, width=10)
        self.screen.grid(column=0, row=0, columnspan=4)


        self.bseven = Button(text="7", height=1, width=2, command=lambda: self.press("7"))
        self.bseven.grid(column=0, row=1)

        self.beight = Button(text="8", height=1, width=2, command=lambda: self.press("8"))
        self.beight.grid(column=1, row=1)

        self.bnine = Button(text="9", height=1, width=2, command=lambda: self.press("9"))
        self.bnine.grid(column=2, row=1)

        self.bdiv = Button(text="/", height=1, width=2, command=lambda: self.press("/"))
        self.bdiv.grid(column=3, row=1)


        self.bfour = Button(text="4", height=1, width=2, command=lambda: self.press("4"))
        self.bfour.grid(column=0, row=2)

        self.bfive = Button(text="5", height=1, width=2, command=lambda: self.press("5"))
        self.bfive.grid(column=1, row=2)

        self.bsix = Button(text="6", height=1, width=2, command=lambda: self.press("6"))
        self.bsix.grid(column=2, row=2)

        self.bmult = Button(text="*", height=1, width=2, command=lambda: self.press("*"))
        self.bmult.grid(column=3, row=2)


        self.bone = Button(text="1", height=1, width=2, command=lambda: self.press("1"))
        self.bone.grid(column=0, row=3)

        self.btwo = Button(text="2", height=1, width=2, command=lambda: self.press("2"))
        self.btwo.grid(column=1, row=3)

        self.bthree = Button(text="3", height=1, width=2, command=lambda: self.press("3"))
        self.bthree.grid(column=2, row=3)

        self.bsub = Button(text="-", height=1, width=2, command=lambda: self.press("-"))
        self.bsub.grid(column=3, row=3)


        self.bzero = Button(text="0", height=1, width=2, command=lambda: self.press("0"))
        self.bzero.grid(column=0, row=4)

        self.bclear = Button(text="C", height=1, width=2, command=lambda: self.press("C"))
        self.bclear.grid(column=1, row=4)

        self.bequ = Button(text="=", height=1, width=2, command=lambda: self.press("="))
        self.bequ.grid(column=2, row=4)

        self.badd = Button(text="+", height=1, width=2, command=lambda: self.press("+"))
        self.badd.grid(column=3, row=4)

    def press(self, a):
        if a == "C":
            self.screenVal.set("")
        elif a == "=":
            self.screenVal.set(eval(self.screenVal.get()))
        else:
            self.screenVal.set(self.screenVal.get() + str(a))


root = Tk()
myapp = Calc(root)
root.mainloop()