#!usr/bin/python
import socket,sys
sock=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
#host=socket.gethostname()
host='192.168.1.172'
#print type(host)
#host='192.168.1.171'
#port=int(sys.argv[1])
port=10105
sock.connect((host,port))
print "connected"
#string=raw_input("enter string:")
#sock.send(string)
#print "data sent"
#f=open("tutorial.pdf","w")
f=open("tut.pdf","w")
print "fetching data from server"
#lenth=sock.recv()
string=sock.recv(200)
#print len(string)
#print string,type(string)

while True:
	list1=list(string)
#	print list1
	str1=list1[-1:-6:-1]
	str1=''.join(str1)
#	print str1
	if(str1=="FOE%%")or(str1=="FOE%%^M")or(str1=="FOE"):
		break	
	#print string
	#break
	f.write(string)

	string=sock.recv(200)
#	print len(string)
#	print string
#print "end"
#f.write(string)
#string=sock.recv(200)
#print "client recvd:",string

f.close()
#print "reading done from server"
print "writing done to tutorial.pdf"
