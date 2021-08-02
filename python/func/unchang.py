#!/usr/bin/python
def fun(list1,list2):
	newlist1=list1
	newlist2=list2[:]#here list2 won't be changed even newlist2 changes
	newlist1.append(22)
	newlist2.append(11)
	print newlist1,newlist2,list2
list1=[1,2,3]
list2=[45,5,6]
fun(list1,list2)
print list1,list2
