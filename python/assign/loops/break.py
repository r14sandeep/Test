#!/usr/bin/python
#program to demonstate break?Ex:Take a list of 20 elements (user input) and ask user to enter range to break
list1=[]
list_range=input("enter size of list:")
print "enter values into list1"
cnt=0
while(1):
	val=input()
	list1.append(val)
	cnt+=1
	if(cnt>list_range-1):
		break
print list1
	
