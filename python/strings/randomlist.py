#!/usr/bin/python
from random import randrange
def random_list():
	result=[]
	count=randrange(1,20)
	print count
	for index in range(count):
		result+=[randrange(-100,100)]
	return result
list1=random_list()
print list1

