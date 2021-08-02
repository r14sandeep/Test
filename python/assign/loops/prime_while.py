#!/usr/bin/python
#program to print whether user entered number is prime or not?(using while loop
num=input("enter a num:")
mid=num/2
i=2
while(i<=mid):
	if(num%i==0):
		print num,"is not a prime"
		break;
	i+=1
if(i==mid+1):
	print num,"is a prime"
