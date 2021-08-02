import cv2
cap=cv2.VideoCapture('vid.webm')
#cap=cv2.VideoCapture()
#print cap
#print cap.get(3),cap.get(4)
cap.set(3,320);cap.set(4,240)
print cap.isOpened()
while(cap.isOpened()):
	ret,frame=cap.read() #reads frame by frame
	gray=cv2.cvtColor(frame,cv2.COLOR_BGR2RGB)
	#cv2.imshow('frame',frame)
	cv2.imshow('frame',gray)
	if cv2.waitKey(20) & 0xFF == ord('q'):
	        break
cap.release()
cv2.destroyAllWindows()
