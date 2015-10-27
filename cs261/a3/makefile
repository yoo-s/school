default: test

linkedList.o: linkedList.c linkedList.h
	gcc -Wall -g -std=c99 -c linkedList.c

testLinkedList.o: linkedList.h testLinkedList.c
	gcc -Wall -g -std=c99 -c testLinkedList.c

linkedListMain.o: linkedList.h linkedListMain.c
	gcc -Wall -g -std=c99 -c linkedListMain.c

test: linkedList.o testLinkedList.o
	gcc -Wall -g -std=c99 -o test linkedList.o testLinkedList.o

compl: linkedList.o linkedListMain.o
	gcc -Wall -g -std=c99 -o compl linkedList.o linkedListMain.o

dynamicArray.o: dynamicArray.c dynamicArray.h
	gcc -Wall -g -std=c99 -c dynamicArray.c

dynamicArrayMain.o: dynamicArray.h dynamicArrayMain.c
	gcc -Wall -g -std=c99 -c dynamicArrayMain.c

comp: dynamicArray.o dynamicArrayMain.o
	gcc -Wall -g -std=c99 -o comp dynamicArray.o dynamicArrayMain.o

cirListDeque.o: cirListDeque.c cirListDeque.h
	gcc -Wall -g -std=c99 -c cirListDeque.c

testCirListDeque.o: cirListDeque.h testCirListDeque.c
	gcc -Wall -g -std=c99 -c testCirListDeque.c

prog: cirListDeque.o testCirListDeque.o
	gcc -Wall -g -std=c99 -o prog cirListDeque.o testCirListDeque.o

clean:
	rm linkedList.o
	rm testLinkedList.o
	rm linkedListMain.o
	rm dynamicArray.o
	rm dynamicArrayMain.o
	rm cirListDeque.o
	rm testCirListDeque.o
