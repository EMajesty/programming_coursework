from tkinter import *

class Feedback:

    def __init__(self, parent):
        self.v_name = StringVar()
        self.l_name = Label(text="Name")
        self.l_name.grid(column=0, row=0)
        self.e_name = Entry(textvariable=self.v_name)
        self.e_name.grid(column=1, row=0)

        self.v_num = StringVar()
        self.l_num = Label(text="Tel")
        self.l_num.grid(column=0, row=1)
        self.e_num = Entry(textvariable=self.v_num)
        self.e_num.grid(column=1, row=1)

        self.v_url = StringVar()
        self.l_url = Label(text="Url")
        self.l_url.grid(column=0, row=2)
        self.e_url = Entry(textvariable=self.v_url)
        self.e_url.grid(column=1, row=2)

        self.v_mail = StringVar()
        self.l_mail = Label(text="Email")
        self.l_mail.grid(column=0, row=3)
        self.e_mail = Entry(textvariable=self.v_mail)
        self.e_mail.grid(column=1, row=3)

        self.b_send = Button(text="Send", command=self.evalSend)
        self.b_send.grid(row=4, columnspan=2)

        self.bgc = self.e_name.cget('bg')

    def evalSend(self):
        
        if self.v_name.get() == "":
            self.e_name.configure(bg='red')
        else:
            self.e_name.configure(bg=self.bgc)

        if self.v_num.get() == "":
            self.e_num.configure(bg='red')
        else:
            self.e_num.configure(bg=self.bgc)

        if self.v_url.get() == "":
            self.e_url.configure(bg='red')
        else:
            self.e_url.configure(bg=self.bgc)

        if self.v_mail.get() == "":
            self.e_mail.configure(bg='red')
        else:
            self.e_mail.configure(bg=self.bgc)
        
        if self.v_name.get() != "":
            if self.v_num.get() != "":
                if self.v_url.get() != "":
                    if self.v_mail.get() != "":
                        root.destroy()


root = Tk()
myapp = Feedback(root)
root.mainloop()