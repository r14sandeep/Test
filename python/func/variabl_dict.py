#!/usr/bin/python
def fun(init=5,*number,**keywords):
	cnt=init #cnt=10
	print number #(1,2,3)
	#print cnt
	for num in number:
		cnt+=num #10+1+2+3=16
	print keywords	#{'veg'=33,'fruits'=22}	
	for key in keywords:
		print key	#veg,fruits
		cnt+=keywords[key]#16+33+22
	return cnt
print fun(10,1,2,3,veg=33,fruits=22)
