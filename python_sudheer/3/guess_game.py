import random
comp_gen = random.randint(1,100)
count = 0
def get_input():
	global count
	count = count+1
	user_input = eval(input("Enter a number from 1 to 100"))
	return user_input

user_input = get_input()

while user_input != comp_gen:
	if user_input > comp_gen:
		print("Enter a lower number")
		user_input = get_input()
	else:
		print("Enter a higher number")
		user_input = get_input()


print("You won! and the number of guesses made:", count)
	
	