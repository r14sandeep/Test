#!/usr/bin/python
list1=(123,23,"abc");list2=(2,99,"Abc")
print cmp(list1,list2)
print cmp(list2,list1)
print max(list1)
print min(list1)
print max(list2)
print min(list2)
print list(list1),list1
tup1=list(list1)
tup1.append(25)
tup1=tuple(tup1)
print tup1
"""print list1
list1.extend(list2)
print list1
print list1.index(23)
print list1
list2.insert(1,"51")
print list1
print list1.pop(1)
print list1
print list1.pop()
print list1
list1.reverse()
print list1
list1.sort()
"""
l=[1,2,3]
print tuple(l)
