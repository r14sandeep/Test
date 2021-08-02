import sys,threading
from PyQt4.QtCore import *
from PyQt4.QtGui import *
list_win=[]
parent_flag=0
def window():
	global list_win
	app = QApplication(sys.argv)
	win = QDialog()
	list_win.append(win)
	b1 = QPushButton(win)
	b1.setText("close")
	b1.move(50,20)
	#b1.clicked.connect(b1_clicked)
	b1.clicked.connect(win.close)
	'''b2 = QPushButton(win)
	b2.setText("Button2")
	b2.move(50,50)
	#QObject.connect(b2,SIGNAL("clicked()"),b2_clicked)
	QObject.connect(b2,SIGNAL("clicked()"),win.close)
	#   win.reject() #closes window on pressing esc'''
	win.setGeometry(100,100,200,100)
	win.setWindowTitle("child")
	win.show()
	sys.exit(app.exec_())

def b1_clicked():
	global list_win
	print "Button 1 clicked"
	for i in list_win:
		i.close()	

def b2_clicked():
	print "Button 2 clicked"
def parent():
	app = QApplication(sys.argv)
	win = QDialog()
	list_win.append(win)
	b1 = QPushButton(win)
	b1.setText("close")
	b1.move(50,20)
	b1.clicked.connect(b1_clicked)

	'''b2 = QPushButton(win)
	b2.setText("Button2")
	b2.move(50,50)
	#QObject.connect(b2,SIGNAL("clicked()"),b2_clicked)
	QObject.connect(b2,SIGNAL("clicked()"),win.close)
	#   win.reject() #closes window on pressing esc'''
	win.setGeometry(100,100,1000,800)
	win.setWindowTitle("Parent")
	win.show()
	sys.exit(app.exec_())
for i in range(4):
	#		thread.start_new_thread(window,())
	th=threading.Thread(target=window,args=())
	th.start()
	th.join()
'''for i in range(5):
	if(i==0):
		#thread.start_new_thread(parent,())
		thr=threading.Thread(target=parent,args=())
		thr.start()	
	else:
		#for i in range(4):
	#		thread.start_new_thread(window,())
		th=threading.Thread(target=window,args=())
		th.start()'''



#if __name__ == '__main__':
#   window()





