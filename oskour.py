import time
import cv2

frames = 60
i = 0

cap = cv2.VideoCapture('test.png')

debut = time.time()

while(i != frames):
    ret, img = cap.read()
    i += 1
cap.release()
fin = time.time()

print("Capture de ", frames, "frames a",(frames / (fin - debut)), "fps")