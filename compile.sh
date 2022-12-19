#!/bin/sh
gcc -O2 main.c MatrixVector.c vorrueckwaertsub.c lrmp.c functions.c -o br -lm
