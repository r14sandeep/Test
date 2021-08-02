#!/usr/bin/python
class point:
	def __init__(self,x=0,y=0):
		self.x=x;
		self.y=y
	def __del__(self):
		class_name_=self.__class__.__name__
		print class_name,"destroyed"
p1=point
p2=p1
p3=p1
p4=point(10,20)
p5=point(10,20)
#print id(p1),id(p2),id(p3)
#print id(p4),id(p5)
