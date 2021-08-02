from Tkinter import *
def window1():
    window = Tk()
    b=Button(window, text = "Next", command = window2).pack()
    window.mainloop()
def window2(win):
    win.destroy() #This is where the error is
    menu = Tk()
window1()
