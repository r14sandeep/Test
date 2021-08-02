#!/usr/bin/python
#sync_threading.py
import threading
import time
exitflag=0
v=0
class mythread(threading.Thread):
	def __init__(self,threadid,name,counter):
		threading.Thread.__init__(self)
		self.threadid=threadid
		self.counter=counter
		self.name=name
	def run(self):
		print "starting"+self.name
		threadLock.acquire()
		print_time(self.name,self.counter,5)
		print "exiting"+self.name
		threadLock.release()
	
def print_time(threadname,delay,cnt):
	while cnt:
		if exitflag:
			thread.exit()
#		print v
#		v+=1
		time.sleep(delay)
		cal_time=time.ctime(time.time())
		print "%s:%s"%(threadname,cal_time)
		cnt-=1
threadLock=threading.Lock()
threads=[]
thread1=mythread(1,"thread1",1)
thread2=mythread(2,"thread2",2)
thread1.start()
thread2.start()
threads.append(thread1)
threads.append(thread2)
#print threads
for t in threads:
	t.join()

print "exiting"


