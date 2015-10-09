/* CS261- Assignment 1 - Q.5*/
/* Name: Soo-Min Yoo
 * Date: 10/09/2015
 * Solution description: This program takes in an input word and prints it in studly
 * caps, or in alternating cases.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	int count = 1;

	for (int i = 0; word[i]; i++) {
		if (isupper(word[i]) && (count % 2 == 0)) {
			word[i] = tolower(word[i]);
		} else if (islower(word[i]) && (count % 2 == 1)) {
			word[i] = toupper(word[i]);
		} else {
			word[i] = word[i];
		}
		count++;
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

