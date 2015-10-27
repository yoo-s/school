/* CS261- Assignment 1 - Q. 0*/
/* Name: Soo-Min Yoo
 * Date: 10/09/2015
 * Solution description: This program examines how to use pointers.
 */

#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
	/*Print the value pointed to by iptr*/
	printf("Value pointed to by iptr: %d\n", *iptr);

	/*Print the address pointed to by iptr*/
	printf("Address pointed to by iptr: %p\n", iptr);

	/*Print the address of iptr itself*/
	printf("Address of iptr itself: %p\n", &iptr);
}

int main(){
	int *ptr;

	/*declare an integer x*/
	int x = 1;

	/*print the address of x*/
	ptr = &x;
	printf("Address of x = %p\n", ptr);

	/*Call fooA() with the address of x*/
	fooA(&x);

	/*print the value of x*/
	printf("Value of x: %d\n", *ptr);

	return 0;
}

