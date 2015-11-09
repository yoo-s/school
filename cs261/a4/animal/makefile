all: prog

prog: main.o
	gcc -g -Wall -std=c99 -o prog main.o

main.o: main.c
	gcc -g -Wall -std=c99 -c main.c
		
clean:	
	rm main.o
	rm prog
