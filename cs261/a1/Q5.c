/* CS261- Assignment 1 - Q.5*/
/* Name: Soo-Min Yoo
 * Date: 10/09/2015
 * Solution description: This program takes in input word and prints in studly
 * caps.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
	return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
	return ch-'A'+'a';
}

void studly(char* word){
	/*Convert to studly caps*/
	for (int i = 0; i < sizeof(word); i++) {
		if (isupper(word[i])) {
			toLowerCase(word[i]);
		} else if (islower(word[i])) {
			toUpperCase(word[i]);
		}
	}
}

int main(){
	/*Read word from the keyboard using scanf*/
	char word[100];

	printf("Type a word: ");
	scanf("%s", word);

	/*Call studly*/
	studly(word);

	/*Print the new word*/
	printf("Your word in studly caps: %s\n", word);

	return 0;
}

