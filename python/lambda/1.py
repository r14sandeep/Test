import time,signal
val=3
def fun1(*args):
	global val
	print "fin1"
	val=15
print "main"
signal.alarm(5)
signal.signal(signal.SIGALRM,fun1)
for i in range(10):
#	global val
	print val
	time.sleep(1)
