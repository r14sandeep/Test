#!/usr/bin/python
#program to demostrate while loop ex:Ask user to enter the number until user enters the guess number
num = 15
guess=input("guess a number:")
while(num!=guess):
	print "wrong guess"
	guess=input("guess a number:")
print "guess is correct:",guess
