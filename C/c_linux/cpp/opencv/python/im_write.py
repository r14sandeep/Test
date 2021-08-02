import cv2
img=cv2.imread("baby2.jpeg",1)
cv2.imshow("write",img)
k=cv2.waitKey(0)
print k
if(k==27):
	cv2.destroyAllWindows()
elif k==ord('s'):
	cv2.imwrite("write.png",img)
	cv2.destroyAllWindows()
