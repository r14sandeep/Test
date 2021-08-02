#!/usr/bin/python
import subprocess,os
#print os.chdir('/')
print subprocess.call(['ls','-l'])
#print os.system('ls -l')
#print subprocess.call('echo $HOME')
print subprocess.call('echo $HOME',shell=True)
#print subprocess.check_call(['false']) #returns exception if failes
#buf=subprocess.call(['ls','-l'])
buf=subprocess.check_output(['ls','-l'])
print buf

