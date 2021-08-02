#!/usr/bin/python
colors=["black","blue","green","wight"]
cntr=0
totalclrs=len(colors)
"""while cntr<totalclrs:
	print colors[cntr]
	cntr+=1
"""
for index in colors:
	print index,
print 
itr=iter(colors)
while True:
	try:
		index=itr.next()
		print index,
	except StopIteration:
		print "\nstop iter"
		break
