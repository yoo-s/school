#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

// buffer has max size of 32 items
// it must be implicitly shared between the threads
#define BUFSIZE 32

// the two values should be created using the rdrand x86 ASM instruction on
// systems that support it, and using the Mersenne Twister on systems that
// don't support rdrand
struct Item {
	int first_value;
	int second_value;
};

// When creating a thread using pthreads, you need to point it to a function
// for it to start execution.
// This function is run by the consumer thread.
void *consume(void *item) {
	// lock mutex to get sole access to buffer
	//
	// check and see if buffer is filled
	// if buffer is empty, block until producer adds a new item

	// print out first value of item
	printf("This is the first value in item.\n");
	// random wait period of 2-9 seconds, then print second value
	sleep(2);
	printf("This is the second value in item.\n");
	
	// unlock mutex to release sole access to buffer

	pthread_exit(NULL);
}


int main(int argc, char **argv) {
	// create an item object
	struct Item item;

	// variable type pthread_t is a means of referencing threads
	pthread_t consumer;

	// A call to pthread_join blocks the calling thread until the thread with
	// identifier equal to the first argument terminates. Similar to wait() for
	// processes.
	printf("Creating consumer thread...\n");
	// create consumer thread
	if (pthread_create(&consumer, NULL, consume, &item)) {
		fprintf(stderr, "Unable to create thread\n");
		return 1;
	}
	printf("Thread created.\n");

	// lock mutex for producer to get sole access to buffer
	//
	// check and see if buffer has space
	// if buffer is full, block until consumer removes an item
	//
	// wait 3-7 seconds, then produce another item
	sleep(5);
	// add item to buffer
	printf("Item added to buffer by the producer thread!\n");
	
	// unlock mutex to release sole access to buffer
	
	// wait for thread to finish and join them together
	printf("Waiting for consumer to finish...\n");
	if(pthread_join(consumer, NULL)) {
		fprintf(stderr, "Unable to join thread\n");
		return 2;
	}
	printf("Successfully joined threads.\n");

	pthread_exit(NULL);
	return 0;
}
