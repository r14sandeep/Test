#!/usr/bin/python
import randomlist
def selection_sort(list1):
	nitems=len(list1)
	for index1 in range(nitems-1):
		small=index1
		for index2 in range(index1+1,nitems):
			if(list1[index2]<list1[small]):
				small=index2
		if(index1!=small):
			list1[index1],list1[small]=list1[small],list1[index1]
	return
#list1=[5,2,1,6,3,4,0]
list1=randomlist.random_list()
print "befor sort:",list1
selection_sort(list1)
print "after sort:",list1
