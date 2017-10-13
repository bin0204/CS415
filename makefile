#build an executable named binShell from binShell.c
#-g adds debugging information to the executable file
#-Wall turns on most, but not all, compiler warnings


all: binShell.c
	gcc -g -Wall -o binShell binShell.c
clean:
	rm -f *.c
