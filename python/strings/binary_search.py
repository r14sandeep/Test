#!/usr/bin/python
def binary_search(list1,data):
	low=0
	high=len(list1)-1
	while(low<=high):
		mid=(low+high)//2
		if(list1[mid]==data):
			return mid
		elif(list1[mid]>data):
			high=mid-1
		else:
			low=mid+1
	return None
list1=[1,4,6,8,12,23,55,65,69]
#num=input
print binary_search(list1,69)
