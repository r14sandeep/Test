#!/usr/bin/python
list1=[22,11,2,3,4,123]
res=[]
for val in list1:
	if(val>4):
		res.append(val)
print res



res = [val for val in list1 if(val>4)]
print res

res = filter(lambda val:val>4,list1)
print res
