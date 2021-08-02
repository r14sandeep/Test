#!/usr/bin/python
import thread
import time
def print_time(task,delay):
	cnt=0
	while cnt<5:
#		print "in print"
		time.sleep(delay)
		cnt+=1
		secs=time.time()
		print secs
		cal_time=time.ctime(secs)
		print "%s:%s"%(task,cal_time)
	print "%s exited"%(task)
try:
	thread.start_new_thread(print_time,('thread1',5,))
	thread.start_new_thread(print_time,('thread2',10,))
except:
	print "error"
while True:
	pass
