#1/usr/bin/python
#fibo
def fib(num):
	v1,v2=0,1
	while(v2<num):
		print v2
		v1,v2=v2,v1+v2
version=132
def fib2(num):
	res=[]
	v1,v2=0,1
	while v2<num:
		res.append(v2)
		v1,v2=v2,v1+v2
	return res
