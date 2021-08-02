import signal
def fun(*args):
	print "in fun"
print "main"
signal.alarm(4)
signal.signal(signal.SIGALRM,fun)
while(1):
	pass
