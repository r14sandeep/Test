#!/usr/bin/python
#program to take a list or tuple or any datatype and travel into that datatype for searching particular value or string
list1=["abc","123","456","xyz"]
string=raw_input("enter a string:")
val=string in list1
if(val==True):
	print "found"
else:
	print "not found"

