#!/usr/bin/python
from ctypes import *
cfun=CDLL("./test_pitch_tempo.so")
tempo=cfun.start()

if tempo==1:
	print "Pass"
else:
	print "Fail"
