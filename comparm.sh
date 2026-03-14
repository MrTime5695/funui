#!/bin/sh
arm-linux-gnueabi-gcc -static $1.c -l SDL -l SDL_image -l m -l webp -l jpeg -o $1arm
