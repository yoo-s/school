/*********************************************
 ** Program: assign02.cpp
 ** Author: Soo-Min Yoo
 ** Date: 04/17/15
 ** Description: program exploring the different data types in C++ and their differing value ranges.
 ** Input: none
 ** Output: return 0
 ********************************************/

#include <iostream>


/*********************************************
 ** Function: main
 ** Description: 
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: return 0
 ********************************************/
int main() {

   int option;
   do {
      std::cout << "1) Highest of ten integers" << std::endl;
      std::cout << "2) Money earning rate" << std::endl;
      std::cout << "3) Average generator" << std::endl;
      std::cout << "4) Decimal to binary" << std::endl;
      std::cout << "5) Exit" << std::endl;
      //Prompt user to select an option
      std::cout << "Enter your option: " << std::endl;
      std::cin >> option;

      if (option == 1) {
	 std::cout << "Enter ten integer values: " << std::endl;
      } else if (option == 2) {
	 std::cout << "Enter starting value: " << std::endl;
      } else if (option == 3) {
	 std::cout << "Enter a positive value: " << std::endl;
      } else if (option == 4) {
	 std::cout << "Enter a decimal (base 10) number: " << std::endl;
      } else if (option == 5) {
	 std::cout << "Exit" << std::endl;
      } else {
	 std::cout << "Not a valid option. Please try again: " << std::endl;
      }

   } while (option != 5);

      return 0;
}
