/*********************************************
 ** Program: assign05a.cpp
 ** Author: Soo-Min Yoo
 ** Date: 05/22/15
 ** Description: Recursively calculates matrix
 ** Input: 
 ** Output: 
 ********************************************/
#include <iostream>
#include <stdlib.h>
#include <cstring>


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
   int n;

   std::cout << "N value: ";
   std::cin >> n;

   double data[n][n] = {
      0, 0, 0, 0,
      0, 0, 0, 0,
      0, 0, 0, 0,
      0, 0, 0, 0
   };

   init(data);

  
   std::cout << std::endl;
   std::cout << "Initial array: " <<  << std::endl;
   std::cout << "Resulting array: " <<  << std::endl;

   return 0;
}
/*********************************************
 ** Function: calculate_result
 ** Description: 
 ** Parameters: 
 ** Pre-Conditions: none
 ** Post-Conditions: return number of words
 ********************************************/
void init (double (&r)[4][4]) {

   r[0][0] = 1;
}
/*********************************************
 ** Function: recursive_calculate_result
 ** Description: 
 ** Parameters: 
 ** Pre-Conditions: none
 ** Post-Conditions: list occurrences of each letter
 ********************************************/
void recursive_calculate_result () {
   
}
