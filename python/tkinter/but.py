from Tkinter import *
Root=Tk()
WindowSpec = Canvas(Root,bg="red",height=150,width=400)
print "child"
WindowSpec.pack(side="top", fill="both", expand=True)
#TextSpec = WindowSpec.create_text(250,250,anchor="center",font=("TimesNewRoman",15))
#WindowSpec.itemconfig(TextSpec,text="Do You Really want to close?")
Root.geometry('%dx%d+%d+%d' % (363, 172,515,315))
YesButton = Button(Root, text="Yes", command=sys.exit(1))
#NoButton = Button(Root, text="No", command=Root.destroy)
#YesButton.grid(row=2,column=2)
#NoButton.grid(row=2,column=2)
YesButton.pack()
#NoButton.pack()

WindowSpec.pack()
print "in"
Root.mainloop()
print "exit"
