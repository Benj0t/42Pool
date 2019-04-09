from PIL.Image import *
import cv2
import RPi.GPIO as GPIO
from time import *
#13 = retour
#11 = aller
GPIO.setmode(GPIO.BOARD)
GPIO.setup(11, GPIO.OUT)
GPIO.setup(13, GPIO.OUT)
ecarteur=0
GPIO.output(11, GPIO.LOW)
GPIO.output(13, GPIO.LOW)
def photo(ecarteur):    
    cam = cv2.VideoCapture(0)
    ret, image = cam.read()
    if ret:
        gray=cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
        cv2.imwrite('/home/pi/Documents/Test/oui.jpg',image)
        img=open('/home/pi/Documents/Test/oui.jpg')
        img.crop((300,120,460,280)).save('/home/pi/Documents/Test/oui.jpg')    #Penser a crop avec une taille prédéfinie.
    cam.release()
    img=open('/home/pi/Documents/Test/oui.jpg')
    NIV_GRIS(img, ecarteur)

def NIV_GRIS(i, ecarteur):
    (l, h) = i.size
    for y in range(h):
        for x in range(l):
            r, g, b = Image.getpixel(i, (x, y))
            moy = (r+g+b)//3
            Image.putpixel(i, (x, y), (moy,moy,moy))
    i.save('/home/pi/Documents/Test/oui.jpg')
    Image.show(i)
    Voiture(ecarteur)

def Voiture(ecarteur):
    img=open('/home/pi/Documents/Test/oui.jpg')
    (l, h)=img.size
    i=0
    for y in range(h):
        for x in range(l):
            r, g, b = Image.getpixel(img, (x, y))
            moy = (r+g+b)//3
            if 215 < moy < 256:
                i+=1
    print(r,g,b)
    if i > 2142 and ecarteur == 0:
        print("ATTENTION A LA VOITURE", i)
        ecarteur = 1
        #then DEPLOYER L ECARTEUR
        GPIO.output(11, GPIO.HIGH)
        sleep(3)
        GPIO.output(11, GPIO.LOW)
        photo(ecarteur)
        
    if i > 2142 and ecarteur ==1:
        print("Y A TOUJOURS UNE VOITURE !!! ALED", i)
        photo(ecarteur)
    if i < 2142 and ecarteur == 1:
        print("Y A PLUS DE VOITURE JE RE")
        sleep(0.5)
        ecarteur=0
        #Rentrer l'écarteur
        GPIO.output(13, GPIO.HIGH)
        sleep(3)
        GPIO.output(13, GPIO.LOW)
        photo(ecarteur)
    if i < 2142 and ecarteur == 0:   
        print("Y A PAS DE VOITURE",i)
        photo(ecarteur)
photo(ecarteur)
