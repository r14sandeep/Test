#!/usr/bin/python
def even(num):
	rem=(num%2)
	if(rem==0):
		return True
	return False
nums=range(1,20)
list1=filter(even,nums)
print list1
