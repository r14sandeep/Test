x = 100

def modify_x():
	global x
	x = x+10
	print("Inside:", x)

modify_x()
print("Outside:", x)