/*********************************************
 ** Program: assign05b.cpp
 ** Author: Soo-Min Yoo
 ** Date: 05/22/15
 ** Description: Reads in a line of text up to 100 characters and outputs the number of words in the line as well as the number of occurrences of each letter.
 ** Input: none
 ** Output: return 0
 ********************************************/
#include <iostream>
#include <stdlib.h>
#include <cstring>

const int size = 100;			// declare max char size of input string
const int numLetters = 26;		// declare number of alphabet letters


int wordCount(char input[]);
void letterCount(char input[], int letters[]);

/*********************************************
 ** Function: main
 ** Description: reads in input string, outputs number of words in string and number of occurrences of each letter
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: return 0
 ********************************************/
int main() {
   int letters[numLetters];	// initializes array that counts letters
   char input[size];			// initializes array storing input string

   // reads input string
   std::cout << "Input string: " << std::endl;
   std::cin.getline(input, size);
   std::cout << input << std::endl;

   letterCount(input, letters);

   std::cout << std::endl;
   // prints number of words in input string
   std::cout << "You have " << wordCount(input) << " words with these letters:" << std::endl;
   // lists occurrences of each letter
   for (int i = 0; i < numLetters; i++) {
      if (letters[i] > 0) {
	 std::cout << static_cast<char>(i+'a') << " " << letters[i] << std::endl;
      }
   }

   return 0;
}
/*********************************************
 ** Function: wordCount
 ** Description: counts the number of words in input string
 ** Parameters: char input[]
 ** Pre-Conditions: none
 ** Post-Conditions: return number of words
 ********************************************/
int wordCount (char input[]) {
   std::cout << "running wordCount" << std::endl;
   int words = 0;

   int letterCount = 0;
   for (int i = 0; i < strlen(input); i++) {
      if (!(input[i] == ' ' || input[i] == '.' || input[i] == ',' || input[i] == '\n' || input[i] == '\r')) {
	 letterCount++;
      }
      else if (letterCount > 0) {
      	 words++;
         letterCount = 0;
      }
   }
   if (letterCount > 0) {
      words++;
   }
   std::cout << "Number of words: " << words << std::endl;
   return words;
}
/*********************************************
 ** Function: letterCount
 ** Description: counts number of occurrences of each letter
 ** Parameters: char input[], int letters[]
 ** Pre-Conditions: none
 ** Post-Conditions: list occurrences of each letter
 ********************************************/
void letterCount (char input[], int letters[]) {
   std::cout << "running letterCount" << std::endl;
   
   for (int i = 0; i < numLetters; i++) {
      letters[i] = 0;
   }
   
   for (int i = 0; i < strlen(input); i++) {
      //std::cout << "Loop #: " << i << std::endl;
      input[i] = tolower(input[i]);
      //std::cout << "Letter in input string: " << input[i] << std::endl;
      letters[input[i]-'a']++;
      //std::cout << "Letter count: " << letters[input[i]-'a'] << std::endl;
   }
}
