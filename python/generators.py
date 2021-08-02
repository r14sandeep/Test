#!/usr/bin/python
def rev(data):
	for index in range(len(data)-1,-1,-1):
		yield data[index]
#list1=[1,2,3,4]
list1="sandeep"
print list1[::-1] #prints reverse
for char in rev(list1):
	print char,
