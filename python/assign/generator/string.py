#!/usr/bin/python
def fun(string):
	for ele in string:
		yield ele


string=raw_input("enter a string:")

for ele in fun(string):
	print ele,
