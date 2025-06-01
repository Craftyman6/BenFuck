all: interpretter
interpretter: interpretter.c benfuck.o
	gcc -Wall -g benfuck.o $< -o $@
benfuck.o: benfuck.c benfuck.h
	gcc -Wall -g -c $< -o $@