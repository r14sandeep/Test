#!/usr/bin/python
string=raw_input("enter a string:")
print string.center(10,'a')
print string.capitalize()
#print string.find("de",5)
#print string.index("de")
#print "isalnum:",string.isalnum()
str1=u"0123"
print "numeric:",str1.isnumeric()
print "isdec:",str1.isdecimal()
#print string.replace("dee","abcd",2)
print string,string[::2]
print string,string[1::2]
