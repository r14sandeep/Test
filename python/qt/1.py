import sys,time,thread,threading
from PyQt4 import QtGui,QtCore
list_root=[]
def flash(w,app):
   p=w.palette()
   p.setColor(w.backgroundRole(),QtCore.Qt.red)
   w.setPalette(p)
   time.sleep(1)
   print "flash w:",w
   w.show()
   flash(w,app)
   sys.exit(app.exec_())

def window():
	global list_root

 	print "sys:",sys.argv
	for i in range(4):
		app = QtGui.QApplication(sys.argv)
		list_root.append(app)
		w = QtGui.QWidget()
		
		b = QtGui.QLabel(w)
		b.setText("Hello World!")
		w.setGeometry(400,400,500,300)
		b.move(50,20)
		w.setWindowTitle("Example")
	#   while True:
	#   flash(w,app)
		p=w.palette()
		p.setColor(w.backgroundRole(),QtCore.Qt.red)
		w.setPalette(p)
	#   time.sleep(1)
		print "flash"
		print "w:",w	
		w.show()
	   #flash(w,app)
		sys.exit(app.exec_())
		
   #print "flash"
   #w.show()
   #app.exec_()
   #sys.exit(app.exec_())
	print "exiting"	
#if __name__ == '__main__':
window()
#for i in range(4):
	
#			thread.start_new_thread(window,())
	
	#th=threading.Thread(window,)
	#th.start()
#window()'''
