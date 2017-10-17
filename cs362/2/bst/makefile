default: prog

prog:
	#gcc -Wall -std=c99 -o prog compare.c bst.c main.c
	gcc -fprofile-arcs -ftest-coverage compare.c bst.c main.c -o prog
		
clean:
	rm prog

cleanall: 
	rm prog 