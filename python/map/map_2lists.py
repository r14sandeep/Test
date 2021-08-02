#!/usr/bin/pytohn
list1=[1,2,3,5,12]
list2=[5,3,6,9,44]
list3=[44,3,22,11,41]
sumlists=map(lambda v1,v2:v1+v2,list1,list2)
print sumlists
sumlists=map(lambda v1,v2,v3:v1+v2+v3,list1,list2,list3)
print sumlists
