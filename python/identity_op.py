#!/usr/bin/python
"""val1=20
val2=20
res=id(val1)
print res
res=id(val2)
print res
res=(val1 is val2)
print res
id1=id(val1)
id2=id(val2)
print "id:",id(id1),id(id2)
print id1,id2,type(id1),type(id2)
print (id1 is id2)
res=(id(val1) is id(val2))
print res
val1+=1
print id(val1),id(val2)
val2+=1
print id(val1),id(val2)
v3=21
print id(v3)"""


"""str1="abc";str2="abc"
print str1 is str2
print id(str1),id(str2)
str1+="abc"
print str1 is str2
print id(str1),id(str2)
str2+="abc"
print str1 is str2
print id(str1),id(str2)"""


v1=10
v2='10'
print v1 is v2
print id(v1),id(v2)
v1=str(v1)
print type(v1),type(v2)
print v1 is v2
print v1,v2,id(v1),id(v2)


"""list1=[1,2,3,4,5]
list2=[1,2,3,4,5]
print id(list1),id(list2)"""
