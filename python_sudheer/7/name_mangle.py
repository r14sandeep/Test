class Student(object):
	def __init__(self, name, course):
		self.__name = name
		self.__course = course

	def getName(self):
		return self.__name

	def getCourse(self):
		return self.__course
