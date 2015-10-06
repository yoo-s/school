/* cs261- assignment 1 - q.1*/
/* name: soo-min yoo
 * Date: 10/09/2015
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
	/*Allocate memory for ten students*/
	struct student* stud = malloc(10 * sizeof(struct student));

	/*return the pointer*/
	return stud;
}

void generate(struct student* students){
	/*Generate random ID and scores for 10 students, ID being between
	 * 1 and 10, scores between 0 and 100*/
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		students[i].id = rand() % 10 + 1;
		students[i].score = rand() % 100 + 1;
	}

}

void output(struct student* students){
	/*Output information about the ten students in the format:
	 *  ID1 Score1
	 *  ID2 score2
	 *  ID3 score3
	 *  ...
	 *  ID10 score10*/
	for (int i = 0; i < 10; i++) {
		printf("%d %d\n", students[i].id, students[i].score);
	}
}

void summary(struct student* students){
	/*Compute and print the minimum, maximum and average scores of the ten students*/
	int min = students[0].score;
	int max = students[0].score;
	int sum = 0;

	for (int i = 0; i < 10; i++) {
		if (min > students[i].score) {
			min = students[i].score;
		} else if (max < students[i].score) {
			max = students[i].score;
		}
		sum += students[i].score;
	}

	printf("Minimum score: %d\n", min);
	printf("Maximum score: %d\n", max);
	printf("Average score: %g\n", (double)sum/10);

}

void deallocate(struct student* stud){
	/*Deallocate memory from stud*/
	assert(stud != 0);

	free(stud);
}

int main(){
	struct student* stud = NULL;

	/*call allocate*/
	stud = allocate();

	/*call generate*/
	generate(stud);

	/*call output*/
	output(stud);

	/*call summary*/
	summary(stud);

	/*call deallocate*/
	deallocate(stud);

	return 0;
}

