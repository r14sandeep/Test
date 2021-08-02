#!/usr/bin/python
import sys
'''list1=input("enter a list:")
tup=input("enter a tuple:")
list2=[val**2 for val in list1]
tup1=tuple([val**2 for val in tup])
print list2,tup1

s=set(list2)
'''
list3=[]
print len(sys.argv)
if (len(sys.argv)==2)and(int(sys.argv[1]>0)):
	stop=int(sys.argv[1])
	for val in range(stop):
		list3.append(val)
elif (len(sys.argv)==3)and(int(sys.argv[1])<int(sys.argv[2])):
	start=int(sys.argv[1])
	stop=int(sys.argv[2])
	for val in range(start,stop):
		list3.append(val)
elif (len(sys.argv)==4):
	if(int(sys.argv[3])>0 and (int(sys.argv[1])<int(sys.argv[2]))):
		start=int(sys.argv[1])
		stop=int(sys.argv[2])
		step=int(sys.argv[3])
		for val in range(start,stop,step):
			list3.append(val)	
	elif(int(sys.argv[3])<0 and (int(sys.argv[1])>int(sys.argv[2]))):
		start=int(sys.argv[1])
		stop=int(sys.argv[2])
		step=int(sys.argv[3])
		for val in range(start,stop,step):
			list3.append(val)	
	else:
		for val in range(10):
			list3.append(val)	
			
else:
		for val in range(10):
			list3.append(val)	
print "list3:",list3


####nested comprehension

list4=[val2 for val1 in list3 for val2 in range(val1)]

print "list4:",list4


##
sum_num=lambda v1,v2,v3:v1+v2+v3

v1,v2,v3=map(int,raw_input("enter 3 nums:").split())
#print v1,v2,v3

print (sum_num(v1,v2,v3))
