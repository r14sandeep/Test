#!/usr/bin/python
from ctypes import *

cfun=CDLL("./test_pitch_rate.so")
rate=cfun.start()

if rate==1:
	print "Pass"
else:
	print "Fail"
