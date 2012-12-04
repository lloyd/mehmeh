foo: sha256.c sha256.h main.c sysendian.h
	gcc -O3 -o doit sha256.c main.c
