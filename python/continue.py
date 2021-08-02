#!/usr/bin/python
while True:
	string=raw_input("enter a string:")
	if(string=="quit"):
		break
	if(len(string)<3):
		print "string is too small"
		continue
	print "efficient length"
