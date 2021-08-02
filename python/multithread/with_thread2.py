#!/usr/bin/python
import thread
import time
#v=0
def print_time(task,delay):
	cnt=0
#	global v
	while cnt<5:
		time.sleep(delay)
		cnt+=1
		secs=time.time()
		cal_time=time.ctime(secs)
		print "%s:%s"%(task,cal_time)
#		print "v=",v
#		v+=1
	print "%s exited"%(task)
try:
	thread.start_new_thread(print_time,('thread1',5,))
	thread.start_new_thread(print_time,('thread2',10,))
except:
	print "error"
while True:
	pass
