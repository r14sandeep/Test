#!/usr/bin/python
tup=[12,22,33,(1,2,3)]
list1=list(tup)
list1[1]=[1,2]
list1[1][0]=33
tup=tuple(list1)
print tup
