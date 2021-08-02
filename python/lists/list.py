#!/usr/bin/python
list1=["abc",123,"xyz"]
print list1
list1.append(10)
list2=[1,2,3]
list1.extend(list2)
print list1
list1.pop()
#list1.pop()
print list1
print list2
list1.insert(1,"deepu")
print list1
print list1.index("deepu")
list1.reverse()
print list1
