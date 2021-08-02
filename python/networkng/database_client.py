#!usr/bin/python
import socket,sys
sock=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
host=socket.gethostname()
#print type(host)
#host='192.168.1.171'
port=int(sys.argv[1])
#f=open("file.pdf","w")
sock.connect((host,port))
print "connected"
while True:
#	sock.connect((host,port))
#	print "connected"
	print "1.write\n2.read\n4.exit"	
	choice=raw_input( "enter your choice:")
	if(choice=='1'):	
		print "writing to server"
		sock.send(choice)
		print sock.recv(100)
		string=raw_input("enter string to be inserted into server:")
		sock.send(string)
		print sock.recv(100)
	elif(choice=='2'):
		sock.send(choice)
		print "data in server is:",sock.recv(100)
	elif(choice=='4'):
		sock.send(choice)
		
		break
		
#string=sock.recv(1000)
#print string

#f.close()
#print "writing done to file.txt"
#sock.send("exit")

print "client is exited"
