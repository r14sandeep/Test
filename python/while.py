#!/usr/bin/python
num=22
run=True
while(run==True):
	guess=input("guess the num:");
	if(guess==num):
		print "guessed correctly"
		run=False
	else:
		print "wrong guess"
else:
	print "out of whilie"
