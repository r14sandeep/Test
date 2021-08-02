#!/usr/bin/python
def linear_search(list1,data):
	list_len=len(list1)
	for index in range(list_len):
		if(list1[index]==data):
			return index
	if(index==list_len):
		return -1
list1=[3,2,4,5,7,8,9,34]
data=0
flag=linear_search(list1,data)

if(flag==None):
	print "data not found"
else:
	print "found at ",flag
	
