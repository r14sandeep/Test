import telnetlib

tn = telnetlib.Telnet("linuxzoo.net")
tn.read_until("login: ")
tn.write("root"+"\n")
tn.read_until("Password: ")
tn.write("secure"+"\n")
tn.read_until("# ")
tn.write("df -h"+"\n")
op = tn.read_until("# ")

for line in op.split("\r\n"):
	print line
