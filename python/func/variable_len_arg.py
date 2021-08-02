#!/usr/bin/python
def fun(var,*vartuple):
	print var
	#for val in vartuple:
		#print val
	print vartuple
#fun(11)
fun(1,2,3,4,5)
list1=[1,2,3]
tup=(4,5,6,7,8)
fun(11,list1)
fun(22,tup)
