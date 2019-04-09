import cv2

cam = cv2.VideoCapture(0)
ret, image = cam.read()

if ret:
    cv2.imshow('SnapchotTest', image)
    cv2.waitKey(0)
    cv2.destroyWindow('SnapchotTest')
    cv2.imwrite('/home/pi/book/output/SnapchotTest.jpg', image)
cam.release()