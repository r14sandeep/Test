#!/sur/bin/python
import sys
print "cmd line sum"
sumcmd=lambda v1,v2:v1+v2

total_sum=reduce(sumcmd,sys.argv)

print total_sum



"""total_sum=0
total_num=len(sys.argv)
for index in range(1,total_num):
	num=int(sys.argv[index])
	total_sum+=num
print total_sum



"""
