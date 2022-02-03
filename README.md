A simple example to show the different execution times achieved with a
standard matrix multiplication and a version that uses the transpose of one of
the matrices. Transposing the matrix will increase the locality due to the way
2D arrays are stored in memory in C program (row major).

The Makefile will generate both versions. You can play with different matrix
sizes by changing the source code.
