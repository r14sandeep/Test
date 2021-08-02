#!/usr/bin/python
dict1={}
dict1['name']='abc'
dict1['class']='last'
print dict1
print dict1.keys()
print dict1.values()
print dict1.items()
#dict2={'key1':123,'abc','key2':44}
#print dict2
dict2={('key1'):123,'key2':44}
print dict2['key1']
dict2={('key1'):(123,33),'key2':[44,12]}
print dict2['key1'],dict2['key2']
