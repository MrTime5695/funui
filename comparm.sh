#!/bin/sh
arm-linux-gnueabi-gcc -static $1.c -l SDL -l SDL_image -o $1arm
