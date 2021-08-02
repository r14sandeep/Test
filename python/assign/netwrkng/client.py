#!/usr/bin/python
import socket,sys
sock=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
print "socket created"
host=socket.gethostname()
port=int(sys.argv[1])
sock.connect((host,port))
string="hello"
sock.send(string)
print "string sent"
st=sock.recv(100)
#print sock.recv(100)
print "string recived"
print st
