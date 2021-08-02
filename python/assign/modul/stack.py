#!/usr/bin/python
stack_max=5
top=-1
list1=[]
def isfull():
	if (stack_max-1)==top:
		return True
	else:
		return False
def isempty():
	if top==-1:
		return True
	else:
		return False	
print "1.push\n2.pop\n3.display\n4.exit"
choice=input("enter ur choice:")
while choice!=4:
	if choice==1:
		if isfull():
			print "stack is full"
		else:
			top+=1
			num = input("enter val to be inserted:")
			list1.append(num)
#			list1[top]=num
	elif choice==2:
		if isempty():
			print "stack is empty"
		else:
			del(list1[top])
			top-=1
	elif choice==3:
		for index in range(top+1):
			print list1[index]
	
	print "1.push\n2.pop\n3.display\n4.exit"
	choice=input("enter ur choice:")
