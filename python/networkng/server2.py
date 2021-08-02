#!/usr/bin/python
import socket,sys
sock=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
print sock
print "socket is created"
host=''
#host=socket.gethostname()
print "host:",host
port=10105

#port=int(sys.argv[1])
sock.bind((host,port))
print "binding done"
sock.listen(5)
print "listening done"
f=open("python_tutorial.pdf","r")
#f=open("file.pdf","r")

#print "waiting for client"
#client,addr=sock.accept()
#print "accepted"
#buf=f.read(10000)
cnt=0
while True:
	print "waiting for client"
	client,addr=sock.accept()
	print "accepted"
	f.seek(0,0)
	#print "client:",client
	#mystr=client.recv(100)
	#print "recved"
	#res=mystr*2
	buf=f.readline(200)
#	print len(buf)
#	print buf
	while buf!='':
	#print len(buf)
#	client.send(len(buf))
		client.send(buf)
		buf=f.readline(200)
	#print buf
	print len(buf),buf
	client.send(buf)
	#print "sent"
	cnt+=1
#client.send(buf)
print "server exited"
f.close()
