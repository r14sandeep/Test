#!.usr/bin/python
mylist=range(10)
myset=[val**2 for val in mylist]
print myset
#myset=[]
#for val in mylist:
#	myset.append(val**2)

#print myset

#even_mul=[]
#for val in myset:
#	if(val%2==0):
#		even_mul.append(val) 
#print even_mul

even_mul=[val for val in myset if val%2==0]
print even_mul
