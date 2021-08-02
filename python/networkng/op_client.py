#!usr/bin/python
import socket,sys
sock=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
host=socket.gethostname()
#print type(host)
#host='192.168.1.171'
port=int(sys.argv[1])
sock.connect((host,port))
print "connected"
#string=raw_input("enter string:")
#sock.send(string)
#print "data sent"

while True:
	print "1.fact\n2.pallindrom\n3.exit"
	choice =raw_input("enter your choice:")
	sock.send(choice)	
	string=sock.recv(1000)
	print string
	if(choice=='1'):
		num=raw_input("enter num:")
		sock.send(num)
		string=sock.recv(100)
		print "fact is",string
#		print "fact of",num,"is",string
	elif(choice=='2'):
		num=raw_input("enter num:")
		sock.send(num)
		string=sock.recv(100)	
		print string	
		
print "client exited"
