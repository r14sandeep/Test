import cv2
img=cv2.imread("baby2.jpeg",1)
if(img is None):
	print "image is not read"
else:
	cv2.namedWindow('read', cv2.WINDOW_NORMAL)
	cv2.imshow("read",img)
	cv2.waitKey(0)
	cv2.destroyAllWindows()

