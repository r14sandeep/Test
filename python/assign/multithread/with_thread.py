#!/usr/bin/python
import thread
import time
def delay_loop(task,secs):
	print "in delay loop"
	print "%s:sleep %d secs"%(task,secs)
	for counter in range(secs):
		time.sleep(counter)
	print "ending delay loop"
def print_time(task,delay):
	cnt=0
	while cnt<5:
		print "in print"
		time.sleep(delay)
		cnt+=1
		secs=time.time()
		print secs
		cal_time=time.ctime(secs)
		print "%s:%s"%(task,cal_time)
try:
	thread.start_new_thread(delay_loop,('thread1',5,))
	thread.start_new_thread(print_time,('thread2',10,))
except:
	print "error"
while True:
	pass
