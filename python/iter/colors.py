#!/usr/bin/python
col=['black','blue','green']
cntr=0
tot_cols=len(col)
itr=iter(col)
while True:
	try:
		index=itr.next()
		print index
	except StopIteration:
		break
