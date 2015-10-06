/* CS261- Assignment 1 - Q.2*/
/* Name: Soo-Min Yoo
 * Date: 10/09/2015
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
	/*Set a to double its original value*/
	*a = *a * 2;

	/*Set b to half its original value*/
	*b = *b / 2;

	/*Assign a+b to c*/
	c = *a + *b;

	/*Return c*/
	return c;
}

int main(){
	/*Declare three integers x,y and z and initialize them to 7, 8, 9 respectively*/
	int x = 7;
	int y = 8;
	int z = 9;

	/*Print the values of x, y and z*/
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("z = %d\n", z);

	/*Call foo() appropriately, passing x,y,z as parameters*/
	int newZ = foo(&x, &y, z);

	/*Print the value returned by foo*/
	printf("value returned by foo = %d\n", newZ);

	/*Print the values of x, y and z again*/
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("z = %d\n", z);

	/*Is the return value different than the value of z?  Why?*/
	/*The return value is different than the value of z, because z was passed
	 * by value when being called by foo, meaning only a copy of z was used by
	 * foo. Even though z was modified inside the foo function, the original
	 * z value in the main function was unchanged and remained the same.*/

	return 0;
}



