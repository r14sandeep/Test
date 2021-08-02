#!/usr/bin/python
import socket,sys
def fact(number):
	res=1
	while(number>0):
		res*=number
		number-=1
	return res
def pallindrom(number):
	temp=number
	res=0
	while(temp>0):
		remainder=temp%10
		res=res*10+remainder
		temp/=10
	if(res==number):
		return True
	else:
		return False
			
sock=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
print "socket is created"
host=socket.gethostname()
port=int(sys.argv[1])
sock.bind((host,port))
print "binding done"
sock.listen(5)
print "listening done"

print "waiting for client"
client,addr=sock.accept()
print "accepted"
operation=client.recv(100)
if(operation=='1'):
	client.send("send the num to calculate fact")
	num=int(client.recv(10))
	num=fact(num)
	num=str(num)
	client.send(num)
elif(operation=='2'):
	client.send("send the num to calculate pallindrom")
	num=int(client.recv(10))
	num=pallindrom(num)
	if(num==True):
		client.send("pallindrom")
	else:
		client.send("not a pallindrom")
		
