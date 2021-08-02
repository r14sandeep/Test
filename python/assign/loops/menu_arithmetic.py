#!/usr/bin/python
num1=input("enter num1:")
num2=input("enter num2:")
while(1):
	print "****MENU****"
	print "1.sum\n2.sub\n3.mul\n4.div\n5.exit"
	choice=input("enter your choice:")
	if(choice==1):
		print "sum is:",num1+num2
	elif(choice==2):
		print "sub is:",num1-num2
	elif(choice==3):
		print "mul is:",num1*num2
	elif(choice==4):
		print "div is:",num1/num2
	elif(choice==5):
		print "Exiting"
		break
	else:
		print "wrong choice"
