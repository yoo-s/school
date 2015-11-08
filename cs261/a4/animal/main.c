#include <iostream>
#include "bst.h"
#include "structs.h"

char * newStr(char * charBuffer) {
	char * p = (char *)malloc(1 + strlen(charBuffer));
	strcpy(p, charBuffer);
	return p;
}

int main() {
	FILE * a;
	char buffer[100];
	strcpy(buffer, "Hello World");	/* put text into buffer area */
	a = fopen("animals.txt", "a");
	assert(a != 0);
	fputs(buffer, a);
	while(fgets(buffer, 100, a) != 0) {
		printf("Read line %s\n", buffer);
	}

	printf("Do you you like puppies?\n");
	fgets(buffer, 100, stdin);
	if (buffer[0] == 'Y' || buffer[0] == 'y') {
		printf("You answered yes.");
	} else {
		printf("You answered no.");
	}

	return 0;
}
