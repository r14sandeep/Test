import cv2
import numpy as np
img=cv2.imread("chess.jpeg")
gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
gray=np.float32(gray)
#print gray[10,100]
dst=cv2.cornerHarris(gray,2,3,0.04)
dst=cv2.dilate(dst,None)

print "max:",0.01*dst.max()
print dst
img[dst>0.01*dst.max()]=[0,0,255]


print dst>0.01*dst.max()

cv2.imshow('dst',img)
cv2.waitKey(0)
cv2.destroyAllWindows()
