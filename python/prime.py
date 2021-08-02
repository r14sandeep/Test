#!/usr/bin/python
print "prime numbers b/w 10 to 20 are:",
for num in range(10,20):
	mid=num/2
	for val in range(2,mid+1):
		if(num%val==0):
			break
	else:
		print num,
