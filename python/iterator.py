#!/usr/bin/python
mylist=range(5)
print mylist
for index in mylist:
	print index
itr=iter(mylist)
while True:
	try:
		index=itr.next()
		print index
	except StopIteration:
		break
