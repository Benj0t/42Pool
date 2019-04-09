from PIL.Image import *
import cv2
from time import *
import RPi.GPIO as GPIO
#GPIO.setmode(GPIO.BOARD)
#GPIO.setup(11, GPIO.OUT) #Avance
#GPIO.setup(13, GPIO.OUT) #Recule
#GPIO.output(11, GPIO.LOW)
#GPIO.output(13, GPIO.LOW)
ecarteur=0
def photo(ecarteur):    
    cam = cv2.VideoCapture(0)
    ret, image = cam.read()
    if ret:
        gray=cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
        cv2.imwrite('/home/pi/Documents/Test/ASSASSIN.jpg',image)
        img=open('/home/pi/Documents/Test/ASSASSIN.jpg')
        img.save('/home/pi/Documents/Test/ASSASSIN.jpg')    #Penser a crop avec une taille prédéfinie.
    cam.release()
    print("FIRST")
    sleep(2)
    photo2(ecarteur)
    
def photo2(ecarteur):    
    cam = cv2.VideoCapture(0)
    ret, image = cam.read()
    if ret:
        gray=cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
        cv2.imwrite('/home/pi/Documents/Test/ouai.jpg',image)
        img=open('/home/pi/Documents/Test/ouai.jpg')
        img.save('/home/pi/Documents/Test/ouai.jpg')    #Penser a crop avec une taille prédéfinie.
    cam.release()
    img2=open('/home/pi/Documents/Test/ouai.jpg')
    print("SECOND")
    Voiture(ecarteur)

def Voiture(ecarteur):
    img=open('/home/pi/Documents/Test/ASSASSIN.jpg')
    img2=open('/home/pi/Documents/Test/ouai.jpg')
    (l, h)=img.size
    i=0
    j=0
    for y in range(h):
        for x in range(l):
            r, g, b = Image.getpixel(img, (x, y))
            r2, g2, b2 = Image.getpixel(img2, (x, y))
            Rtotal=r-r2
            Gtotal=g-g2
            Btotal=b-b2
            if h==5 and l == 3:
                print(Rtotal,Gtotal,Btotal)
            if ( Rtotal < -100 or Rtotal > 100) or (Gtotal < -100 or Gtotal > 100) or (Btotal <-100 or Btotal > 100 ): 
                j+=1
    print(j,"Pixels ont changés")
    NIV_GRIS(img2,j,ecarteur)

def NIV_GRIS(i,j,ecarteur):
    (l, h) = i.size
    z=0
    for y in range(h):
        for x in range(l):
            r, g, b = Image.getpixel(i, (x, y))
            moy = (r+g+b)//3
            Image.putpixel(i, (x, y), (moy,moy,moy))
            if moy >=200:
                z+=1
    if j>34200 and ecarteur == 0 or z>= 10000:
        print("ATTENTION A LA VOITURE", i)
        ecarteur = 1
        #GPIO.output(11, GPIO.HIGH)
        #GPIO.output(13, GPIO.LOW)
        sleep(0.5)
        #then DEPLOYER L ECARTEUR
        photo(ecarteur)
    if j>342 and ecarteur ==1 or z>= 10000:
        print("Y A TOUJOURS UNE VOITURE !!! ALED", i)
        #GPIO.output(11, GPIO.LOW)
        #GPIO.output(13, GPIO.LOW)
        photo(ecarteur)
    if j<342 and ecarteur == 1 or z<= 10000:
        print("Y A PLUS DE VOITURE JE RE")
        sleep(0.5)
        #GPIO.output(11, GPIO.LOW)
        #GPIO.output(13, GPIO.HIGH)
        ecarteur=0
        #Rentrer l'écarteur
        photo(ecarteur)
    if j<342 and ecarteur == 0 or z<= 10000:   
        print("Y A PAS DE VOITURE",i)
        #GPIO.output(11, GPIO.LOW)
        #GPIO.output(13, GPIO.LOW)
        photo(ecarteur)
photo(ecarteur)
