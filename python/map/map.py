#!/usr/bin/python
def cal_sqr(num):
	sqr=num*num
	return sqr
numbers=[1,2,3,4,5]
res=map(cal_sqr,numbers)
print res
print map(lambda val:val*val,numbers)
