#!/usr/bin/python
list1=[1,2,3,4,5]
length=len(list1)
for index in range(length):
	print list1[index],
itr=iter(list1)
for index in range(length):
	print itr.next()

####tuple
tup=(1,2,3,4,5)
length=len(tup)
for index in range(length):
	print tup[index],
itr=iter(tup)
for index in range(length):
	print itr.next()


###string
string="votary"
for ele in string:
	print ele,
itr=iter(string)
for index in range(len(string)):
	print itr.next()


###dictionary
dict1={'name':'deepu','roll':123}
for key in dict1:
	print dict1[key],
itr=iter(dict1)
for index in range(len(dict1)):
	key=itr.next()
	print dict1[key]


####set
s=set('12311331456')
for ele in s:
	print ele,
itr=iter(s)
for i in range(len(s)):
	print itr.next()

print s

####fibnocci series
def fib(num):
	v1,v2=0,1
	yield v1
	while v2<=num:
		yield v2
		v1,v2=v2,v1+v2
num=input("enter num for fibnocci series:")
for ele in fib(num):
	print ele,

#####factorial

def fact(num):
	while num>0:
		yield num
		num-=1
val=input("enter num for fact:")
res=1
for ele in fact(val):
	res*=ele
print res
