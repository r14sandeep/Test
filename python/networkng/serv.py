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
client,addr=sock.accept()
while True:
	buf=raw_input()
	#client.send(buf+str(1))
	client.send(buf+str(1))


