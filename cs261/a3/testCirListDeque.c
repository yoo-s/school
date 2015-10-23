#include "cirListDeque.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
        

	/* Test your linked list in here! */

	printf("Deque Implementation Test:\n");
	printf("Creating circular deque...");
	struct cirListDeque *deq = createCirListDeque();
	printf("Done.\n");
	printf("Let's add the values 2, 6, and 9 to the circular deque.\n");
	printf("Adding 2 and 6 to front of circular deque...");
	addFrontCirListDeque(deq, 6);
	addFrontCirListDeque(deq, 2);
	printf("Done.\n");
	printf("Adding 9 to back of circular deque...");
	addBackCirListDeque(deq, 9);
	printf("Done.\n");
	printf("Checking if first element is 2...It is %d", frontCirListDeque(deq));
	printf("Checking if last element is 9...It is %d", backCirListDeque(deq));
	printf("Now printing the whole circular deque...\n");
	printCirListDeque(deq);
	printf("Reversing the circular deque...\n");
	reverseCirListDeque(deq);
	printCirListDeque(deq);
	printf("Let's remove the values from the circular deque.\n");
	printf("Removing 2 from front of circular deque...");
	removeFrontCirListDeque(deq);
	printf("Done.\n");
	printf("Removing 6 and 9 from back of circular deque...");
	removeBackCirListDeque(deq);
	removeBackCirListDeque(deq);
	printf("Done.\n");
	printf("Checking if circular deque is empty...");
	if (isEmptyCirListDeque(deq)) {
		printf("Done.\n");
	} else {
		printf("Failed.\n");
	}
	printf("Deleting circular deque...");
	deleteCirListDeque(deq);
	printf("Done.\n");
	printf("\nTesting completed.\n");

	return 0;
}


