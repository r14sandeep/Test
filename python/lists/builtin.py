#!/usr/bin/python
list1=[1,23,"abc"];list2=[2,3,"abc"]
"""print cmp(list1,list2)
print max(list1)
print min(list2)
print tuple(list1),list1"""
list1.append(list2)
print list1
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
print list1
