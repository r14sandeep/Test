#!/usr/bin/python
#Wapto print series of user entered range numbers using generators
def fun(mi,ma):
	for ele in range(mi,ma):
		yield ele

min1=input("enter min value:")
max1=input("enter max val:");
for ele in fun(min1,max1):
	print ele,
