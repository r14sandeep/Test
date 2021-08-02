#!/usr/bin/python
import sys
v1,v2=0,1
while v1<=int(sys.argv[1]):
	print v1,
	v1,v2=v2,v1+v2
