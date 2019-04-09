import cv2
from PIL import *
from time import *


voiture=0
while voiture!=1:
    cam = cv2.VideoCapture(0)
    ret, image = cam.read()
    
    if ret:
        gray=cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
        cv2.imwrite('/home/pi/Documents/Test/SnapshotTest.jpg',image)
        img = Image.open('lena.png').convert('LA')
        img.save('greyscale.png')
    cam.release()
    voiture=1
    