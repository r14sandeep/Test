import cv2
from matplotlib import pyplot as plt
img=cv2.imread("baby2.jpeg",0)
plt.imshow(img,cmap='gray',interpolation='bicubic')
plt.xticks([20]),plt.yticks([50])
plt.show()
