import io
import time
import os
import sys
import picamera
import pygame

import warnings
warnings.filterwarnings('default', category=DeprecationWarning)

pics_taken = 0
vid_taken = 0


pygame.init()
width,height = 1280, 720
print("Screen resolution:", width, "x", height)
screen = pygame.display.set_mode([width, height])
pygame.display.toggle_fullscreen()
pygame.mouse.set_visible = False


camera = picamera.PiCamera()
camera.framerate = float(8)



def take_pic():
    global pics_taken
    pics_taken += 1
    camera.capture('image_'+ str(vid_taken)+'.jpg')
    

def take_video():
    global vid_taken
    vid_taken += 1
    camera.start_recording('video_'+ str(vid_taken)+ '.h264')
    
    camera.wait_recording(15)
    camera.stop_recording()


def quit_app():
    camera.close()
    pygame.quit()
    print("You've taken", pics_taken, " pictures", vid_taken," videos. Don't forget to back them up (or they'll overwritten next time)")
    sys.exit(0)
    

camera.start_preview()


while(True):
    pygame.display.update()
    for event in pygame.event.get():
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_ESCAPE:
                quit_app()
            elif event.key == pygame.K_SPACE:
                take_pics()
            elif event.key == pygame.K_RETURN:
                take_video()
            elif event.key == pygame.K_TAB:
                camera.start_preview()
