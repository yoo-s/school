#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
        

	/* Test your linked list in here! */

	printf("Deque Implementation Test:\n");
	printf("Creating deque...");
	struct linkedList *deq = createLinkedList();
	printf("Done.\n");
	printf("Let's add the values 2, 6, and 9 to the deque.\n");
	printf("Adding 2 and 6 to front of deque...");
	addFrontList(deq, 6);
	addFrontList(deq, 2);
	printf("Done.\n");
	printf("Adding 9 to back of deque...");
	addBackList(deq, 9);
	printf("Done.\n");
	printf("Checking if first element is 2...It is %d", frontList(deq));
	printf("Checking if last element is 9...It is %d", backList(deq));
	printf("Now printing the whole deque...\n");
	_printList(deq);
	printf("Let's remove the values from the deque.\n");
	printf("Removing 2 from front of deque...");
	removeFrontList(deq);
	printf("Done.\n");
	printf("Removing 6 and 9 from back of deque...");
	removeBackList(deq);
	removeBackList(deq);
	printf("Done.\n");
	printf("Checking if deque is empty...");
	if (isEmptyList(deq)) {
		printf("Done.\n");
	} else {
		printf("Failed.\n");
	}
	printf("Deleting deque...");
	deleteLinkedList(deq);
	printf("Done.\n");

	printf("\nBag Implementation Test:\n");
	printf("Creating bag...");
	struct linkedList *bag = createLinkedList();
	printf("Done.\n");
	printf("Let's add the values 1, 4, 9, and 16 to the bag.\n");
	printf("Adding values...");
	addList(bag, 1);
	addList(bag, 4);
	addList(bag, 9);
	addList(bag, 16);
	printf("Done.\n");
	printf("Checking if bag contains the value 6...");
	if (containsList(bag, 6)) {
		printf("It does.");
	} else {
		printf("It does not.");
	}
	printf("Now printing the bag's values...\n");
	_printList(bag);
	printf("Let's remove the values from the bag.\n");
	printf("Removing value 4...");
	removeList(bag, 4);
	printf("Done.\n");
	printf("Removing value 16...");
	removeList(bag, 16);
	printf("Done.\n");
	printf("Removing the remaining values...");
	removeList(bag, 1);
	removeList(bag, 9);
	printf("Done.\n");
	printf("Checking if bag is empty...");
	if (isEmptyList(bag)) {
		printf("Done.\n");
	} else {
		printf("Failed.\n");
	}
	printf("Deleting bag...");
	deleteLinkedList(bag);
	printf("Done.\n");
	printf("\nTesting completed.\n");

	return 0;
}


