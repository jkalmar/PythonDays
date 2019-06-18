#!/usr/bin/python3

import pygame
from pygame.locals import *


if __name__ == "__main__" :
    pygame.init()

    clock = pygame.time.Clock()

    width = 800
    height = 640

    window = pygame.display.set_mode((width,height))

    color = (255,255,255)
    color2 = (0, 0, 0)

    block_size = 40

    window.fill(color)

    gameExit = False

    while not gameExit:
        print("game")
        window.fill(color)


        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()

            if event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
                pygame.quit()
                quit()

        for y in range(0, height, block_size):
            for x in range(0, width, block_size):
                rect = pygame.Rect(x, y, block_size, block_size)
                print(rect)
                pygame.draw.rect(window, color2, rect, 5)


        pygame.display.update()

        clock.tick(60)
