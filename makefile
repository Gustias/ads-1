main.exe: main.o stack.o
	gcc -std=c99 main.o stack.o -o main.exe

main.o: main.c stack.h
	gcc -std=c99 -c main.c

stack.o: stack.c stack.h
	gcc -std=c99 -c stack.c