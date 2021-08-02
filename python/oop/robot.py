#!/user/bin/python
class robot:
	population=0
	def __init__(self,name):
		self.name=name
		print "intialising {}",self.name
		robot.population+=1
	def die(self):
		print "{} is destroyed",(self.name)
		robot.population-=1
		if(robot.population==0):
			print "{} was last one",self.name
		else:
			print "remaining {} ",robot.population

	def say_hi(self):
		print "greeting",self.name
#	def how_many(cls):
#		print "we have {} robots",cls.population
	def how_many():
		print "we have {} robots",robot.population
	how_many=staticmethod(how_many)

obj1=robot("Ri2-D2")
obj1.say_hi()
#robot.how_many(obj1)
robot.how_many()

obj2=robot("abc")
obj2.say_hi()
#robot.how_many(obj1)
robot.how_many()

obj1.die()
obj2.die()
#robot.how_many(obj1)
robot.how_many()
