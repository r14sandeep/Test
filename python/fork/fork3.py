import os,time
def fun():
	print "fun"
	time.sleep(4)
for i in range(3):
	if(os.fork()):
		fun()
