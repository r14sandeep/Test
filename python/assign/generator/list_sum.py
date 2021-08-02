#!/usr/bin/python
#wap to sum of list elements(user input) using generators?
def fun(list1):
	for ele in list1:
		yield ele
list1=[1,2,3,4,5,6]
list_sum=0
for ele in fun(list1):
	list_sum+=ele
print "sum is:",list_sum
