/*********************************************
 ** Program: assign05c.cpp
 ** Author: Soo-Min Yoo
 ** Date: 05/22/15
 ** Description: Accepts c-string input from user and prints the reversed version of the array.
 ** Input: none
 ** Output: none
 ********************************************/
#include <iostream>
#include <stdlib.h>
#include <cstring>

char* reverse (char* a, int SIZE);

/*********************************************
 ** Function: main
 ** Description: Reads in input string, prints original string and reversed string.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: return 0
 ********************************************/
int main () {
   const int SIZE = 50;
   char input[SIZE];

   // Reads in input string
   std::cout << "Input string: " << std::endl;
   std::cin.getline(input, SIZE);

   char* rev = reverse(input, SIZE);

   // Prints original and reversed strings
   std::cout << "Original: " << input << std::endl;
   std::cout << "Reversed: " << rev << std::endl;

   return 0;
}

/*********************************************
 ** Function: reverse
 ** Description: Reverses array containing input string.
 ** Parameters: char* a, int SIZE
 ** Pre-Conditions: none
 ** Post-Conditions: returns reversed array
 ********************************************/
char* reverse (char* a, int SIZE) {
   char* r = new char[SIZE];
   int j = 0;
   
   for (int i = strlen(a)-1; i >= 0; i--) {
      r[j] = a[i];
      j++;
   }
   
   return r;
}
