import Tkinter as tk


root = tk.Tk() # create a Tk root window

w = 800 # width for the Tk root
h = 650 # height for the Tk root
#print w,h
# get screen width and height
ws = root.winfo_screenwidth() # width of the screen
hs = root.winfo_screenheight() # height of the screen
print ws,hs
# calculate x and y coordinates for the Tk root window
x = (ws/2) - (w/2)
y = (hs/2) - (h/2)

# set the dimensions of the screen 
# and where it is placed
if()
root.geometry('%dx%d+%d+%d' % (645, 300, 63, 81))

#root.geometry('%dx%d+%d+%d' % (500, 500, 0, 800))

root.mainloop() # starts the mainloop                                                  
