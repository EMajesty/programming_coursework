from tkinter import *

class Laskin:
    #screenVal = 0
    def __init__(self, parent):
        self.calcFrame = Frame(parent, width=300, height=300)
        calcFrame.pack()

        self.screen = tkinter.Label(self.calcFrame, text=screenVal, fg="white", bg="black")
        self.screen.grid(columnspan=4)

        self.button = Button(self.calcFrame)
        self.button

    @staticmethod
    def add(a,b): return a+b
    @staticmethod
    def sub(a,b): return a-b
    @staticmethod
    def mult(a,b): return a*b
    @staticmethod
    def div(a,b): return a/b

root = Tk()
laskin = Laskin(root)
root.mainloop()