#!/usr/bin/python
#string=input("enter a string:")
import sys
try:
	string=input("enter a string:")
	print string
except:
	print "exception raised ",sys.exc_type
print 'hello'
