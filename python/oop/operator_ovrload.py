#!/usr/bin/python
class vector:
	def __init__(self,val1,val2):
		self.val1=val1
		self.val2=val2
#	def __str__(self):
	def __repr__(self):
		return "vector(%d %d)"%(self.val1,self.val2)
	def __add__(self,other):
		res=vector(self.val1+other.val1,self.val2+other.val2)
		return res
	def __sub__(self,other):	
		res=vector(self.val1-other.val1,self.val2-other.val2)
		return res
	def __mul__(self,other):	
		res=vector(self.val1*other.val1,self.val2*other.val2)
		return res
		
	

obj1=vector(10,20)
obj2=vector(1,2)
res = obj1+obj2
print res
print obj1-obj2
print obj1*obj2

