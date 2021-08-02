import numpy as np
import cv2
img=np.zeros((512,512,4),np.uint8)
#cv2.line(img,(0,0),(511,511),(255,0,0),5)
#cv2.line(img,(427,63),(510,125),(255,0,0),5)
#cv2.rectangle(img,(380,10),(510,125),(220,0,0),5)
#cv2.circle(img,(427,63), 63, (0,0,255), 1)

#cv2.ellipse(img,(256,56),(100,50),0,0,80,255,-1)

#font=cv2.FONT_HERSHEY_SIMPLEX
font=cv2.FONT_HERSHEY_SCRIPT_SIMPLEX
cv2.putText(img,'Sandeep',(10,250),font,0.4,(21,233,123),1,cv2.LINE_AA)
cv2.imshow("img",img)
cv2.waitKey(0)
cv2.destroyAllWindows()
