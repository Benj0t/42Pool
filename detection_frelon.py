import cv2
import numpy as np
from time import *

def rgb2gray(rgb):
    r, g, b = rgb[:,:,0], rgb[:,:,1], rgb[:,:,2]
    gray = 0.2989 * r + 0.5870 * g + 0.1140 * b
    
    return gray

frelon = 0
while frelon != 1:
    cam = cv2.VideoCapture(0)
    ret, image = cam.read()
    
    if ret:
        cv2.imwrite('/home/pi/Documents/Test/SnapchotTest.jpg', image)
        cv2.open('/home/pi/Documents/Test/SnapchotTest.jpg')
        
        frelon = 1
        
    cam.release()
    fichier = open('/home/pi/Documents/Test/SnapchotTest.jpg')
    