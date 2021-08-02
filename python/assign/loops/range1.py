#!/usr/bin/python
start=input("enter start value:");
stop=input("enter stop value:");
inc=input("enter inc value:");
if(start>stop):
	print "invalid data:"
else:
	for val in range(start,stop,inc):
		print val,
