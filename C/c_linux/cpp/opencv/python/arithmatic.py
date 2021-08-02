import cv2
import numpy as np
'''x= np.uint8([210])
y= np.uint8([50])
print cv2.add(x,y)
print x+y
cv2.imshow("im",x)
cv2.waitKey(0)
cv2.destroyAllWindows()
'''
img1=cv2.imread("baby2.jpeg")
img2=cv2.imread("mini.jpg")
dst=cv2.addWeighted(img1,0.7,img2,0.3,0)
cv2.imhshow("dst",dst)
cv2.waitKey(0)
cv2.destroyAllWindows()
