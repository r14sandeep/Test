#!/usr/bin/python
#string="abcdef"
#itr=iter(string)
list1=['abc',123,'zxcv']
itr=iter(list1)
#len1=len(string)
len1=len(list1)
for index in range(len1):
	print itr.next()
