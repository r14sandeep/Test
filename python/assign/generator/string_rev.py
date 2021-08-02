#!/usr/bin/python
def fun(string):
	length=len(string)
	for ele in range(length-1,-1,-1):
		yield string[ele]

stri =raw_input("enter a string:")
for ele in fun(stri):
	print ele,
