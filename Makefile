BINS = matrix matrix-transpose
CC = gcc
LD = ld

CFLAGS = -o3

.PHONY:	all clean

all:	$(BINS)

matrix:	matrix.c
	$(CC) $(CFLAGS) -o $@ $<

matrix-transpose: matrix.c
	$(CC) $(CFLAGS) -DUSE_TRANSPOSE -o $@ $<


clean:
	rm -f $(BINS) *.o
