#https://www.youtube.com/watch?v=1XTqE7LFQjI
#6:19/8:09

import cv2, time, pygame

pygame.init()

video=cv2.VideoCapture(0)

def quit_app():
    cv.DestroyWindow('frame')
    pygame.quit()
    print("La video s'est correctement arrêtee.")
    sys.exit(0)

while True:
    check, frame = video.read()

    print(check)
    print(frame)

    cv2.imshow("Capturing", frame)
    cv2.waitKey(0)

    video.release()
    
    for event in pygame.event.get():
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_ESCAPE:
                quit_app()
                