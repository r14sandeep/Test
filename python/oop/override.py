#!/user/bin/pytohn
class parent:
	def method(self):
		print "in parent class"
class child(parent):
	def method(self):
		print "in child class"
obj1=child()
obj1.method()
obj2=parent()
obj2.method()
