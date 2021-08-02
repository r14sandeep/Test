#!/usr/bin/python
queue_max=5
rear=front=-1
list1=[]
def isfull():
	if rear==queue_max-1:
		return True
	else:
		return False
def isempty():
	if front==-1:
		return True
	else:
		return False
print "1.enq\n2.deq\n3.display\n4.exit"
choice=input("enter choice:")
while choice!=4:
	if choice==1:
		if isfull():
			print "queue is full"
		else:
			if(front==-1):
				front+=1
			rear+=1
			num = input("enter val into queue:")
			list1.append(num)
	elif choice==2:
		if isempty():
			print "queue is empty"
		else:
			del(list1[front])
			rear-=1
#			front+=1
			if front-1==rear:
				front=rear=-1
	elif choice==3:
		print list1
	print "1.enq\n2.deq\n3.display\n4.exit"
	choice=input("enter choice:")


