#!/usr/bin/python
sumf=lambda v1,v2:v1+v2
#def sumf(v1,v2):
#	print v1,v2
#	res = v1+v2
#	return res
list1=range(1,10)
sum1=reduce(sumf,list1)
print sum1


maxval=lambda v1,v2:v1 if(v1>v2) else v2
#def maxval(v1,v2):
#	if(v1>v2):
#		print v1
#		return v1
#	else:
#		print v2
#		return v2
list1=[22,33,1,44,2,234]
max1=reduce(maxval,list1)
print max1


