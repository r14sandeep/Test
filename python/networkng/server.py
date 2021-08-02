#!/usr/bin/python
import socket,sys
sock=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
print sock
print "socket is created"
host=socket.gethostname()
print "host:",host
port=int(sys.argv[1])
sock.bind(('',port))
print "binding done"
sock.listen(5)
print "listening done"
f=open("python_tutorial.pdf","r")
#print "waiting for client"
#client,addr=sock.accept()
#print "accepted"
#buf=f.read(10000)

while True:
	print "waiting for client"
	client,addr=sock.accept()
	print "accepted"
	print addr
	f.seek(0,0)
	#print "client:",client
	#mystr=client.recv(100)
	#print "recved"
	#res=mystr*2
	buf=f.read()
	print len(buf)
	client.send(buf+1)
	#print buf
	#print "sent"
client.send(buf)
f.close()
