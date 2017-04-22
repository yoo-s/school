#include <pthread.h>
#include <stdio.h>

struct Item {
	int first_value;
	int second_value;
};

// When creating a thread using pthreads, you need to point it to a function
// for it to start execution. This function is run by the producer thread.
void *produce(void *item) {
	return NULL;
}

void *consume(void *item) {
	return NULL;
}


int main(int argc, char **argv) {
	// create an item object
	struct Item item;

	// variable type pthread_t is a means of referencing threads
	pthread_t producer;
	pthread_t consumer;
	
	// create producer thread
	if (pthread_create(&producer, NULL, produce, &item)) {
		fprintf(stderr, "Unable to create thread\n");
		return 1;
	}
	// create consumer thread
	if (pthread_create(&consumer, NULL, consume, &item)) {
		fprintf(stderr, "Unable to create thread\n");
		return 1;
	}

	if(pthread_join(producer, NULL)) {
		fprintf(stderr, "Unable to join thread\n");
		return 2;
	}
	if(pthread_join(consumer, NULL)) {
		fprintf(stderr, "Unable to join thread\n");
		return 2;
	}



	return 0;
}
