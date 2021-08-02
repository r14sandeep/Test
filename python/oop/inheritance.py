#!/usr/bin/python
class parent:
	parentattr=10
	def __init__(self):
		print "in parent constructor"
	def parentmethod(self):
		print "in parent method"
	def setAttr(self,attr):
		parent.parentattr=attr
	def getAttr(self):
		print "parent attr:",parent.parentattr
class child(parent):
	def __init__(self):
		print "in child constructor"
	def childmethod(self):
		print "in child method"
obj=child()

#obj.childmethod()
#obj.parentmethod()
#obj.setAttr(125)
#obj.getAttr()

#print issubclass(child,parent)
#print isinstance(attr,parent)
#print isinstance(obj2,parent)
