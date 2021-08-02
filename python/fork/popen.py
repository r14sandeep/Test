#!/usr/bin/python
import os,subprocess
print os.popen("print 'hello'").read()
#print subprocess.Popen("echo hello",stdout=subprocess.PIPE,shell=True).stdout.read()
proc= subprocess.Popen(["echo"," hello","world"],stdout=subprocess.PIPE)
stddata=proc.communicate()
print stddata
print proc

