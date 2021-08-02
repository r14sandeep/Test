#!/usr/bin/python

##generate random num
from random import randrange
num = randrange(10,20)
list1=[]
for index in range(num):
	list1.append(randrange(-10,20))
print "list1:",list1

pos_list=[]
'''for val in list1:
'''
def fun(num):
	if(num>0):
		return True
pos_list+=filter(fun,list1)
print "pos_list:",pos_list

####square of pos_list
sqr_list=[]
def sqr(val):
	return val**2
sqr_list=map(sqr,pos_list)
print "sqr_list:",sqr_list

		
#### sum of sqr_list

sum_sqr=lambda v1,v2:v1+v2

tot_sum=reduce(sum_sqr,sqr_list)
print "sum of sqr_list:",tot_sum

#### 
