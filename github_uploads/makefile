histogram: histogram.o jpeg64.o
	gcc -o histogram histogram.o jpeg64.o -ljpeg -lm

histogram.o: histogram.c jpeg.h
	gcc -c histogram.c
