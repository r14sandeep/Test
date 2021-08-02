#!/usr/bin/python
list1=[1,2,34,4]
for index in range(len(list1)):
	list1[index]+=3
print list1


list1=[val+3 for val in list1]
print list1


list1=map(lambda v1:v1+3,list1)
print list1
