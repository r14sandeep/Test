#!/usr/bin/python
val="123A"
val = val+"1"
print val,type(val)
num = int(val,16)
print num,type(num)


hexnum=str(num)
num = int(hexnum,10)
print "num:",num,type(num)
print "hexnum:",hexnum,type(hexnum)


val = 67
char = chr(val)
print "char:",char,type(char)


char = 'a'
val=ord(char)
print "char in int is:",val,type(val)
print "eval:",eval("5+6*8")


val="111"
binval=int(val,2)
print "bin:",binval


val=10
print "bin val:",bin(val)

val = "12"
num = int(val,8)
print num,type(num)

val="123"
num = repr(val)
print num
