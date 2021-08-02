#!/usr/bin/python
import os,time,sys
def print_time(processname,delay):
	cnt=0
	while cnt<5:
		time.sleep(delay)
		cnt+=1
		print "%s cnt:%d"%(processname,cnt)
#		print "%s :%s"%(processname,time.ctime(time.time()))
processid=os.fork()
if processid:
	print "parent"
	print_time("parent",2)
	print processid
#	time.sleep(2)
	print "parent exiting"
else:
	print "child"
	print_time("child",2)
	print processid
#	time.sleep(2)
	print "child exiting"
	sys.exit(0)
time.sleep(10)
