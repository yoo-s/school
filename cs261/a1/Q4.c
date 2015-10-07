/* CS261- Assignment 1 - Q.4*/
/* Name: Soo-Min Yoo
 * Date: 10/09/2015
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
	/*Sort the n students based on their score*/
	/* Remember, each student must be matched with their original score after sorting */
	int tempid;
	int tempsc;

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (students[i].score > students[j].score) {
				tempid = students[i].id;
				tempsc = students[i].score;
				students[i].id = students[j].id;
				students[i].score = students[j].score;
				students[j].id = tempid;
				students[j].score = tempsc;
			}
		}
	}
}

int main(){
	/*Declare an integer n and assign it a value.*/
	int n = 10;

	/*Allocate memory for n students using malloc.*/
	struct student* stud = malloc(n * sizeof(struct student));

	/*Generate random IDs and scores for the n students, using rand().*/
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		stud[i].id = rand() % n + 1;
		stud[i].score = rand() % 100 + 1;
	}

	/*Print the contents of the array of n students.*/
	printf("Random scores:\n");
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", stud[i].id, stud[i].score);
	}

	/*Pass this array along with n to the sort() function*/
	sort(stud, n);

	/*Print the contents of the array of n students.*/
	printf("Sorted scores:\n");
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", stud[i].id, stud[i].score);
	}

	return 0;
}

