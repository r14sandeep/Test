#!/usr/bin/python
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
		time.sleep(delay)
		cnt+=1
		secs=time.time()
		print secs
		cal_time=time.ctime(secs)
		print "%s:%s"%(task,cal_time)
delay_loop('task1',5)
print_time('task2',2)
