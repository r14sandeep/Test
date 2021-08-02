#!/usr/bin/python
#enter string ,sub string and display substr is present in str or not

str1=raw_input("enter a string:")
sub_str=raw_input("enter sub string:")
res=sub_str in str1
if(res==True):
	print "present"
else:
	print "not present"
