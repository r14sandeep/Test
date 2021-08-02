#!/usr/bin/python
def fib(num):
	v1,v2=0,1
#num=input("enter a num:")
	while v1<=num:
		print v1,
		v1,v2=v2,v1+v2
def series(num):
	for val in range(num):
		print val,
