#!/usr/bin/python
class data:
	cnt=1
	def display(self,n):
		data.cnt=n
		print data.cnt
d=data()
#d.cnt=5
d.display(10)
print d.cnt
