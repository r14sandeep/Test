#!/usr/bin/python
import socket,sys
sock=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
print sock
print "socket is created"
host=socket.gethostname()
print "host:",host
port=int(sys.argv[1])
sock.bind((host,port))
print "binding done"
sock.listen(5)
print "listening done"
f=open("data.txt","a+")
#print "waiting for client"
#client,addr=sock.accept()
#print "accepted"

while True:
	print "waiting for client"
	client,addr=sock.accept()
	print "accepted"
#	f.seek(0,0)
	print "waiting for input from client:"
	
	#print "client:",client
	choice=client.recv(100)
	if(choice=='1'):
		client.send("ok got the task to do,enter the data to be inserted:")
		data=client.recv(100)
		f.write(data)
		client.send("successfully data is entered into server")
	elif(choice=='2'):
		f.seek(0,0)
		buff=f.read()
		client.send(buff)
	elif(choice=='4'):
		break
	#print "recved"
	#res=mystr*2
#	buf=f.read(10000)
#	client.send(buf)
#	print "sent"
print "server is exited"
f.close()


