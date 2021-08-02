#!/usr/bin/python
dict1={'name':'deepu','roll':444}
itr=iter(dict1)
for index in range(len(dict1)):
	#print itr.next()
	key=itr.next()
	print dict1[key]
