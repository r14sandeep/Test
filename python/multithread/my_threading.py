#!/usr/bin/python
import threading
import time
exitflag=0
class mythread(threading.Thread):
	def __init__(self,threadid,name,counter):
		threading.Thread.__init__(self)
		self.threadid=threadid
		self.counter=counter
		self.name=name
	def run(self):
		print "starting"+self.name
		print_time(self.name,self.counter,5)
		print "exiting"+self.name
	
def print_time(threadname,delay,cnt):
	while cnt:
		if exitflag:
			thread.exit()
		time.sleep(delay)
		cal_time=time.ctime(time.time())
		print "%s:%s"%(threadname,cal_time)
		cnt-=1
thread1=mythread(1,"thread1",1)
thread2=mythread(2,"thread2",2)
thread1.start()
thread2.start()
thread1.join()
thread2.join()
print "exiting"


