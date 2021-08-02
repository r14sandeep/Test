#!/usr/bin/python
import threading
import time,sys
class global_value(threading.Thread):
	globval=0
	def __init__(self,threadid,name,loopcnt):
		threading.Thread.__init__(self)
		self.threadid=threadid
		self.loopcnt=loopcnt
		self.name=name
	def run(self):
		print "starting"+self.name
#		threadLock.acquire()
#		print_time(self.name,self.counter,5)
#		print "exiting"+self.name
		for counter in range(self.loopcnt):
			global_value.globval+=1	
#			print "name:",self.name
#			print global_value.globval
		print "exiting"+self.name
#		threadLock.release()
	def loop_cnt(self):
		print "global value is:",self.globval
"""def print_time(threadname,delay,cnt):
	while cnt:
		if exitflag:
			thread.exit()
#		print v
#		v+=1
		time.sleep(delay)
		cal_time=time.ctime(time.time())
		print "%s:%s"%(threadname,cal_time)
		cnt-=1
"""
#threadLock=threading.Lock()
#threads=[]
if(len(sys.argv)==2):
	loop=int(sys.argv[1])
else:
	loop=1000
print "loop=",loop
thread1=global_value(1,"thread1",loop)
thread2=global_value(2,"thread2",loop)
#thread2=mythread(2,"thread2",2)
thread1.start()
thread2.start()
thread1.join()
thread2.join()
thread1.loop_cnt()
#for t in threads:
#	t.join()
print "glob val:",global_value.globval
print "exiting"


