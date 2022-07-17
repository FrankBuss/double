#!/bin/bash

./convert.py > font.c
./charmap.py > charmap.h

export CC65_INC=/home/frank/bin/cc65/include/
cl65 -t vic20 -o double.prg -C ld.cfg double.c font.c
