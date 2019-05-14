from PIL.Image import *
import cv2
import time
import RPi.GPIO as GPIO
#GPIO.setmode(GPIO.BOARD)
#GPIO.setup(11, GPIO.OUT) #Avance
#GPIO.setup(13, GPIO.OUT) #Recule
#GPIO.setup(15, GPIO.IN) #CAPTEUR GOCH
#GPIO.setup(16, GPIO.IN) #CAPTEUR pas a goch
#GPIO.output(11, GPIO.LOW)
#GPIO.output(13, GPIO.LOW)
ecarteur=0
alter=0

cam = cv2.VideoCapture(0)
ret, image = cam.read()
if ret:
    gray=cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    cv2.imwrite('/home/pi/Documents/Test/ASSASSIN.jpg',image)
    img=open('/home/pi/Documents/Test/ASSASSIN.jpg')
    img.crop((320,210,420,310)).save('/home/pi/Documents/Test/ASSASSIN.jpg')
print("photo init")
cam.release()

def photo(ecarteur,alter):
    t=time.time()    
    if alter==0:
        alter=1
        t=time.time()
        cam = cv2.VideoCapture(0)
        ret, image = cam.read()
        if ret:
            gray=cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
            cv2.imwrite('/home/pi/Documents/Test/ASSASSIN.jpg',image)
            img=open('/home/pi/Documents/Test/ASSASSIN.jpg')
            img.crop((320,210,420,310)).save('/home/pi/Documents/Test/ASSASSIN.jpg')  
        cam.release()
        print("photo")
    elif alter==1:
        alter=0    
        t=time.time()
        cam = cv2.VideoCapture(0)
        ret, image = cam.read()
        if ret:
            gray=cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
            cv2.imwrite('/home/pi/Documents/Test/ouai.jpg',image)
            img=open('/home/pi/Documents/Test/ouai.jpg')
            img.crop((320,210,420,310)).save('/home/pi/Documents/Test/ouai.jpg')  
        cam.release()
        print("photo")
    Voiture(ecarteur,t,alter)

def Voiture(ecarteur,t,alter):
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
            if ( Rtotal < -50 or Rtotal > 50) or (Gtotal < -50 or Gtotal > 50) or (Btotal <-50 or Btotal > 50 ): 
                j+=1
    print(j,"Pixels ont changés")
    NIV_GRIS(img2,j,ecarteur,t,alter)

def NIV_GRIS(i,j,ecarteur,t,alter):
    (l, h) = i.size
    z=0
    for y in range(h):
        for x in range(l):
            r, g, b = Image.getpixel(i, (x, y))
            moy = (r+g+b)//3
            Image.putpixel(i, (x, y), (moy,moy,moy))
            if moy >=200:
                z+=1
    if (j>1000 and ecarteur == 0) or (z>= 10000 and ecarteur == 0):
        print("ATTENTION A LA VOITURE", i)
        ecarteur = 1
        if z>= 10000:
            print("ça pique les yeux")
        #while GPIO.input(16) != 1:
            #GPIO.output(11, GPIO.HIGH)
            #GPIO.output(13, GPIO.LOW)
        #GPIO.output(11, GPIO.LOW)
        #GPIO.output(13, GPIO.LOW)
        t2=time.time()
        tf=t2-t
        print(tf, "ohbgrbgyue")
        photo(ecarteur,alter)
    if (j>1000 and ecarteur ==1) or (z>= 10000 and ecarteur ==1):
        print("Y A TOUJOURS UNE VOITURE !!! ALED", i)
        #GPIO.output(11, GPIO.LOW)
        #GPIO.output(13, GPIO.LOW)
        photo(ecarteur,alter)
    if (j<1000 and ecarteur == 1) or (z<= 10000 and ecarteur == 0):
        print("Y A PLUS DE VOITURE ",i)
        time.sleep(10)
        #while GPIO.input(15) != 1:
            #GPIO.output(11, GPIO.LOW)
            #GPIO.output(13, GPIO.HIGH)
        #GPIO.output(11, GPIO.LOW)
        #GPIO.output(13, GPIO.LOW)
        ecarteur=0
        photo(ecarteur,alter)
    if (j<1000 and ecarteur == 0)or (z<= 10000 and ecarteur ==0):
        print("Y A PAS DE VOITURE",i)
        #GPIO.output(11, GPIO.LOW)
        #GPIO.output(13, GPIO.LOW)
        photo(ecarteur,alter)
photo(ecarteur,alter)