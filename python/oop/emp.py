#!/usr/bin/python
class emp:
	'class'
	empcnt=0
#	nam=''
	def __init__(self,name,salary):
		self.name=name
		self.salary=salary
#		nam=name
		emp.empcnt+=1
	def displaycnt(self):
		print "total emp:",emp.empcnt
	def displayemp(self):
		print "emp:",self.name
#		print "emp:",emp.nam
obj1 = emp("deepu",213000)
obj1.displaycnt()
obj1.displayemp()
obj2 = emp("sandeep",1111111)
obj2.displaycnt()
obj2.displayemp()
#obj1.displayemp()
obj1.age=33 #creates attribute age
print obj1.age

obj1.age=21
print obj1.age

print hasattr(obj1,'empcnt')
print hasattr(obj1,'age')
print getattr(obj1,'age')
setattr(obj1,'age',88)
print obj1.age
del obj1.age
print hasattr(obj1,'age')



print "emp.__doc__:",emp.__doc__
print "emp.__name__:",emp.__name__
print "module:",emp.__module__
print "base:",emp.__bases__
print "dict:",emp.__dict__



