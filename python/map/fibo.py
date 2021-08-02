#!/usr/bin/python
#if __name__=='__main__':
#	pass
#else:

def fib(totalnum):
	v1,v2=0,1
	while(v2<totalnum):
		print v2
		v1,v2=v2,v1+v2
	return
def fib2(totalnum):
	res=[]
	v1,v2=0,1
	while(v2<totalnum):
		res.append(v2)
		v1,v2=v2,v1+v2

	return res

__version__=2.7
