import tkinter
top = tkinter.Tk()

def handleClick(event):
        print("The button was clicked")

welcomeText = tkinter.Label(text="Hello satan")
welcomeText.pack()

label = tkinter.Label(
    text="Hello satan",
    foreground = "white",
    background = "black"
)
label.pack()

button = tkinter.Button(
    text = "Nappi",
    width = 25,
    height = 5,
    bg = "white",
    fg = "black"
)
button.bind("<Button-1>", handleClick)
button.pack()

comments = tkinter.Text()
comments.pack()

frame1 = tkinter.Frame()
frame2 = tkinter.Frame()

label1 = tkinter.Label(master=frame1, text="Frame 1")
label1.pack()

label2 = tkinter.Label(master=frame2, text="Frame 2")
label2.pack()

frame1.pack()
frame2.pack()

top.mainloop()