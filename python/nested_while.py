#!/usr/bin/python
v1_start=1;v1_end=2;v2_start=2;v2_end=11;
while(v1_start<v1_end):
	while(v2_start<v2_end):
		print "%d:%d"%(v2_start,v2_end)
		v2_start+=2
	else:
		print "end of inner while"
	v1_start+=1
else:
	print "end of outer while"
