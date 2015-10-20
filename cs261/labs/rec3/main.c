//
//  main.c
//  Lab4
//
//  Created by Todd Kulesza on 1/25/14.
//  Copyright (c) 2014 Todd Kulesza. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sll.h"

#define N_STRINGS 4

/* Returns 1 if 'string' is a palindrom, 0 otherwise. */
int isPalindrome(char *string)
{
    int result = 0; /* set to 1 if 'string' is a palindrome */
    int i;
	int count = 0;
    
    /* Before finishing this function, you'll need to finish sll.c */
    struct sll *halfword = sll_create();
    struct sll *halfword2 = sll_create();
    for (i = 0; i < (int)strlen(string)/2; i++) {
        /* "string[i]" will retrieve the next character */
		sll_push(halfword, string[i]);
		printf("%c", sll_top(halfword));
    }
	printf(" ");
	for (i = (int)strlen(string); i > (int)strlen(string)/2; i--) {
		sll_push(halfword2, string[i]);
		printf("%c", sll_top(halfword2));
	}

    
    /* This loop will help you iterate over a string one character at time */
    for (i = 0; i < (int)strlen(string)/2; i++) {
		if (sll_top(halfword) == sll_top(halfword2)) {
			sll_pop(halfword);
			sll_pop(halfword2);
			count++;
	    }
	}
	printf("\n%d\n", count);

	if (count == (int)strlen(string)/2) {
		result = 1;
	} else {
		result = 0;
	}
    
    return result;
}

/* You shouldn't need to modify the main() function */
int main(void)
{
    int i;
    char *testStrings[N_STRINGS];
    testStrings[0] = "redder";
    testStrings[1] = "tacocat";
    testStrings[2] = "drabasafoolaloofasabard";
    testStrings[3] = "i'mnotapalindrome";
    
    for (i = 0; i < N_STRINGS; i++) {
        printf("Checking \"%s\"... ", testStrings[i]);
        if (isPalindrome(testStrings[i])) {
            printf ("it's a palindrome!\n");
        }
        else {
            printf ("nope, not a palindrome.\n");
        }
    }

    return 0;
}
