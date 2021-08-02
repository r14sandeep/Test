#!/usr/bin/python
#program to demonstate continue?Ex:Take a list of 20 elements (user input) and ask user to enter elements and skip that elements and display
list1=[]
list_range=input("enter size of list:")
print "enter values into list1"
cnt=0
while(cnt<list_range):
	val=input()
	if(val<5):
		continue
	list1.append(val)
	cnt+=1
	
print list1
	
