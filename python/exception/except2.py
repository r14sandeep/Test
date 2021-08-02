#!/usr/bin/python
import math,sys
num=int(input("enter a num:"))
try:
	print math.sqrt(num)
except:
	print "exception is:",sys.exc_type
	print "cant give -ve num"
	print math.sqrt(abs(num))

print "end"
