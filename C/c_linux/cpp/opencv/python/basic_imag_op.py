import cv2
import numpy as np
img=cv2.imread("messy.jpg")

#print img[10,10]
#print img.item(10,10,2)
#img.itemset((10,10,2),100)
#print img[10,10]

#print img.shape
#print "pixels:",img.size

#print img.dtype
#ball=img[280:340,330:390]
#print ball
#img[27:33, 10:16] = [10,23,3]

b,g,r=cv2.split(img)
print b,g,r
b,g,r=cv2.split(img[10:20,30:45])
print b,g,r
#img=cv2.merge((b,g,r))
#b=img[:,:,0]
#img[:,:,2]=0
cv2.imshow("basic",img)
cv2.waitKey(0)
cv2.destroyAllWindows()
