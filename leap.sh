#!/bin/sh
arm-linux-gnueabi-gcc -static $1.c -l SDL -l m -o $1
