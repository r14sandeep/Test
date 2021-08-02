#!/usr/bin/python
"""def fun(string):
	for ele in string:
		yield (string.count(ele))
		yield ele
			
"""
string=raw_input("enter a num:")
for ele2 in string:
	cnt=string.count(ele2)
	while(cnt>1):
		print ele2,
		cnt-=1
