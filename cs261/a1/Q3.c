/* CS261- Assignment 1 - Q.3*/
/* Name: Soo-Min Yoo
 * Date: 10/09/2015
 * Solution description: This program takes an array of 20 random numbers and
 * sorts them in ascending order.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void sort(int* number, int n){
	/*Sort the given array number, of length n*/
	int temp;

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (number[i] > number[j]) {
				temp = number[i];
				number[i] = number[j];
				number[j] = temp;
			}
		}
	}
}

int main(){
	/*Declare an integer n and assign it a value of 20.*/
	int n = 20;

	/*Allocate memory for an array of n integers using malloc.*/
	int *arr = malloc(n * sizeof(int));

	/*Fill this array with random numbers between 0 and n, using rand().*/
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % n + 1;
	}

	/*Print the contents of the array.*/
	printf("Original contents:\n");
	for (int i = 0; i < n; i++) {
		printf("%d \n", arr[i]);
	}

	/*Pass this array along with n to the sort() function.*/
	sort(arr, n);

	/*Print the contents of the array.*/
	printf("Sorted contents:\n");
	for (int i = 0; i < n; i++) {
		printf("%d \n", arr[i]);
	}

	return 0;
}

