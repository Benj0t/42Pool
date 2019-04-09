import RPi.GPIO as GPIO
from time import *
GPIO.setmode(GPIO.BOARD)
GPIO.setup(11, GPIO.OUT)
GPIO.setup(13, GPIO.OUT)
while True :
    GPIO.output(11, GPIO.LOW)
    GPIO.output(13, GPIO.HIGH)
