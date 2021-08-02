#!/usr/bin/python
def fun(v1,v2=5,v3=11):
	print v1,v2,v3
fun(1,2)
fun(111)
#fun(v3=21,v2=23)#error
fun(v3=41,v1=2)
fun(v2=31,v1=2)
fun()
