#!/user/bin/python
class base:
	__cnt=0
	def fun(self):
#		cnt+=1
		self.__cnt+=1
		print self.__cnt
c=base()
c.fun()
#print c.__cnt  #cant access outside
#print base.__cnt
