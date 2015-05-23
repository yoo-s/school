/*********************************************
 ** Program: assign05b.cpp
 ** Author: Soo-Min Yoo
 ** Date: 05/22/15
 ** Description: 
 ** Input: 
 ** Output: 
 ********************************************/
#include <iostream>
#include <stdlib.h>
#include <cstring>

// declare max char size of input string
const int size = 100;
// declare number of alphabet letters
const int numLetters = 26;

int wordCount(char input[]);
void letterCount(char input[], int letters[]);

/*********************************************
 ** Function: main
 ** Description: 
 ** Parameters: 
 ** Pre-Conditions: none
 ** Post-Conditions: return 0
 ********************************************/
int main() {
   int letters[numLetters] = {};
   char input[size];

   std::cout << "Input string: " << std::endl;
   std::cin.getline(input, size);

   letterCount(input, letters);

   std::cout << std::endl;
   std::cout << "You have " << wordCount(input) << " words with these letters:" << std::endl;
   for (int i = 0; i <= numLetters; i++) {
      if (letters[i] > 0) {
	 std::cout << static_cast<char>(i+'a') << " " << letters[i] << std::endl;
      }
   }

   return 0;
}
/*********************************************
 ** Function: wordCount
 ** Description: 
 ** Parameters: 
 ** Pre-Conditions: none
 ** Post-Conditions: return number of words
 ********************************************/
int wordCount (char input[]) {
   std::cout << "running wordCount" << std::endl;
   int words;

   for (int i = 0; i <= ; i++) {
      if (input[i] == ' ' || input[i] == '.' || input[i] == ',' || input[i] == '\n' || input[i] == '\r') {
	 words++;
      }
   }
   return words;
}
/*********************************************
 ** Function: letterCount
 ** Description: 
 ** Parameters: 
 ** Pre-Conditions: none
 ** Post-Conditions: list occurrences of each letter
 ********************************************/
void letterCount (char input[], int letters[]) {
   std::cout << "running letterCount" << std::endl;
   
   for (int i = 0; i <= numLetters; i++) {
      letters[i] = 0;
   }
   
   for (int i = 0; i < size; i++) {
      input[i] = tolower(input[i]);
      letters[input[i]-'a']++;
   }
}
