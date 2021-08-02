#!/usr/bin/python
#program to print whether user entered number is prime or not?(using for loop)

num=input("enter num to be check:")
mid=num/2
for val in range(2,mid+1):
	if(num%val==0):
		print num,"is not a prime:"
		break
else:
	print num,"is prime"
