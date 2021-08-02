import cv2 
import numpy as np
img1=cv2.imread("messy.jpg")
img2=cv2.imread("baby2.jpeg")
rows,col,ch=img2.shape
print rows,col,ch
roi=img1[0:rows,0:col]
print roi
img2gray = cv2.cvtColor(img2,cv2.COLOR_BGR2GRAY)
ret,mask=cv2.threshold(img2gray,10,255,cv2.THRESH_BINARY)
mask_inv=cv2.bitwise_not(mask)
img1_bg=cv2.bitwise_and(roi,roi,mask=mask_inv)
img2_fg=cv2.bitwise_and(img2,img2,mask=mask)
dst=cv2.add(img1_bg,img2_fg)
img1[0:rows,0:col]=dst

#cv2.imshow("row",rows)
cv2.imshow("dst",img1)
#cv2.imshow("roi",roi)
#cv2.imshow("ro",img1)
cv2.waitKey(0)
cv2.destroyAllWindows()
