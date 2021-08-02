#!/usr/bin/python
list1=[]
list_range=input("enter range of list:")
print "enter elements into list:"
for i in range(list_range):
	#list1[i]=input()
	list1.append(input())
while(1):
	print "1.delete element\n2.replace\n3.display\n"
	print "enter your choice:"
	choice=input()
	if(choice==1):
		ele=input("enter the element to be deleted:")
		del(list1[list1.index(ele)])
		list_range-=1
		#print list1
	elif(choice==2):
		rep_ele=input("enter element to be replaced:")
		ele=input("enter element:(which is replaced):")
		ind=list1.index(rep_ele)
		
		list1[ind]=ele
		
	elif(choice==3):
		print list1
	else:
		break
		
