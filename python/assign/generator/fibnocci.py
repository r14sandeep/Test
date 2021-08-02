#!/usr/bin/python
def fun(mi,ma):
	temp1=0;temp2=1;temp3=0
	while(temp1<=ma):
		if(temp1>=mi)and(temp1<=ma):
			yield temp1
		
#		elif(temp3>=mi)and(temp3<=ma):
#			yield temp3
		temp3=temp1+temp2
		temp1=temp2;temp2=temp3;

min1,max1=map(int,raw_input("enter min,max values:").split())
#print min1,max1
for fib in fun(min1,max1):
	print fib,

