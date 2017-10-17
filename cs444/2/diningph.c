// Code written and documented following the code from here: http://pseudomuto.com/development/2014/03/01/dining-philosophers-in-c/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

// POSIX threads take a single void* parameter. But we need to pass in four values to each thread - current philosopher's position at table,
// total number of philosophers, semaphore for critical region, and semaphore for forks.
// So we create the struct params_t to wrap these values.
typedef struct {
	int position;
	int count;
	sem_t *forks;
	sem_t *lock;
} params_t;

void initialize_semaphores(sem_t *lock, sem_t *forks, int num_forks);
void run_all_threads(pthread_t *threads, sem_t *forks, sem_t *lock, int num_philosophers);
void *philosopher(void *params);
void think(int position);
void eat(int position);


int main(int argc, char *args[]) {
	int num_philosophers = 5;

	// define a few semaphores - one for each fork and one for controlling the critical region. (What exactly are semaphores and the critical region?)
	sem_t lock;
	sem_t forks[num_philosophers];
	pthread_t philosophers[num_philosophers];

	initialize_semaphores(&lock, forks, num_philosophers);
	run_all_threads(philosophers, forks, &lock, num_philosophers);
	pthread_exit(NULL);
	
}

void initialize_semaphores(sem_t *lock, sem_t *forks, int num_forks) {
	int i;
	for (i = 0; i < num_forks; i++) {
		// Initializes the unnamed semaphore referred to by &forks[i]. The value of the initialized semaphore is 1 (third arg).
		// If the 2nd arg has a non-zero value, then the semaphore is shared between processes, and any process that can access the semaphore &forks[i]
		// 		can use &forks[i] for performing sem_wait(), trywait(), post(), and destroy() operations.
		// If the 2nd arg is zero, then the semaphore is shared between threads of the process, and any threads in this process can use &forks[i]
		// 		for performing the same operations.
		// If completed successfully, sem_init initializes the semaphore in &forks[i].
		sem_init(&forks[i], 0, 1);
		// We've initialized the forks by setting their initial value to 1.
	}

	// Initialize the lock semaphore - this will be used to wrap the calls to 'eat' in a critical region.
	// Since only two philosophers can eat at a time (5 forks, 2 required to eat), a simple way to avoid deadlock is to not let all philosphers
	// grab forks. So we can initialize it to 4 (one less than total philosophers).
	sem_init(lock, 0, num_forks-1);
}

void run_all_threads(pthread_t *threads, sem_t *forks, sem_t *lock, int num_philosophers) {
	int i;
	// Creates an instance of params_t to pass to each philosopher thread
	for (i = 0; i < num_philosophers; i++) {
		params_t *arg = malloc(sizeof(params_t));
		arg->position = i;
		arg->count = num_philosophers;
		arg->lock = lock;
		arg->forks = forks;

		// Spawns philosopher threads by calling pthread_create for each thread &threads[i].
		// NULL for the 2nd arg means default thread attributes are used.
		// Each thread is created by calling the philosopher() function, passing its params_t instance as an argument.
		// If completed successfully, pthread_create stores the ID of the created thread in the location referenced by &threads[i].
		pthread_create(&threads[i], NULL, philosopher, (void*)arg);
	}
}

void *philosopher(void *params) {
	int i;
	params_t self = *(params_t *)params;

	// why iterate 3 times?
	for (i = 0; i < 3; i++) {
		think(self.position);

		// Locks the semaphore referenced by lock by performing a semaphore lock operation on that semaphore.
		// If semaphore values is currently zero, calling thread won't return from sem_wait() call until either semaphore is locked or the
		// call is interrupted by a signal.
		// If returned successfully, the state of the semaphore stays locked until the sem_post() function is executed/returns successfully.
		// So first, we wait on the lock. This is the start of the critical region and makes sure that no more than 4 philosophers are trying
		// to pick up a fork at any given time.
		sem_wait(self.lock);
		// Next, wait on the left and right forks. Since these semaphores are initialized to 1, we're sure that the current philosopher's the
		// only one using either of them at that moment.
		// what's the difference between the two calls below? I'm guessing left and right fork but how does it work?
		sem_wait(&self.forks[self.position]);
		sem_wait(&self.forks[(self.position+1) % self.count]);
		// Now the philosopher eats.
		eat(self.position);
		// Indicate to forks that philosopher's done eating
		// sem_post() unlocks the semaphore referenced by &self.forks[self.position].
		sem_post(&self.forks[self.position]);
		sem_post(&self.forks[(self.position+1) % self.count]);
		// Post to lock to exit critical region so that other philosophers can eat.
		sem_post(self.lock);
	}
	think(self.position);
	pthread_exit(NULL);
}

void think(int position) {
	printf("Philosopher %d thinking...\n", position);
}

void eat(int position) {
	printf("Philosopher %d eating...\n", position);
}
