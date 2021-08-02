#!/usr/bin/python
import socket,sys
sock=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
print "socket created"
host=socket.gethostname()
port=int(sys.argv[1])
sock.bind((host,port))
print "binding done"
sock.listen(2)
print "listenind done"
print "waiting for client"
#while True:
client,addr=sock.accept()
print "connceted to client"
string=client.recv(100)
print "string recieved"
length=len(string)
stri=string[length-1:-1:1]
#print string
#print string[length-1:-1:1]

client.send(stri)
print "string sent",stri
