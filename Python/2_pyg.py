import pygame, sys
from pygame.locals import *

pygame.init()

FPS = 60
fpsClock = pygame.time.Clock()

sWidth = 800
sHeight = 600

DISPLAYSURF = pygame.display.set_mode((sWidth, sHeight), 0, 32)
pygame.display.set_caption('You can has cheezburger')

cheez = pygame.image.load('cheez.png')
burger = pygame.image.load('burger.png')
space = pygame.image.load('space.png')
cheezx = 20
cheezy = 20

pygame.key.set_repeat(10,10)

while True:
    DISPLAYSURF.fill((255, 255, 255))
    DISPLAYSURF.blit(space, (0,0))
    DISPLAYSURF.blit(burger, (500, 400))
    DISPLAYSURF.blit(cheez, (cheezx, cheezy))

    for event in pygame.event.get(): # Event handler
        keys_pressed = pygame.key.get_pressed()
        
        if keys_pressed[pygame.K_LEFT]:
            if cheezx >= 0:
                cheezx -= 5
        if keys_pressed[pygame.K_RIGHT]:
            if cheezx <= sWidth:
                cheezx += 5
        if keys_pressed[pygame.K_UP]:
            if cheezy >= 0:
                cheezy -= 5
        if keys_pressed[pygame.K_DOWN]:
            if cheezy <= sHeight:
                cheezy += 5
        
        if cheezx >= 500 & cheezy >= 300:
            sys.exit()

        if event.type == QUIT:
            pygame.quit()
            sys.exit()

    pygame.display.update() # Draw screen
    fpsClock.tick(FPS)
