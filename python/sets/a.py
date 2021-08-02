#!/usr/bin/python
#s=set("a python program")
#s=set([1,2,1,3,4,5,2])
#s=set(['perle','pythonp'])
#s=set((('abc','add'),('abc','xyzz')))
#s=set(['hyd','bang','mum'])
s=frozenset(['hyd','bang','mum'])
#s.add('del')
it=iter(s)
for i in range(len(s)):
	print it.next()

print s
