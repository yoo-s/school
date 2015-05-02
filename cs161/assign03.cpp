/*********************************************
 ** Program: assign03.cpp
 ** Author: Soo-Min Yoo
 ** Date: 05/01/15
 ** Description: program that calculates the area under a function using both the rectangle and trapezoid methods for solving integration problems.
 ** Input:
       Starting and ending points for the area
       Function to calculate the area, i.e. f1, f2, f3, f4, f5
       Function/Procedure(s) for calculating the area, i.e. rect, trap, both
       Number of rectangles and/or trapezoids to use
 ** Output:
       The function being evaluated
       Starting and ending points for the integral
       Number of rectangles and/or trapezoids used
       The area calculated by the method(s)
 ********************************************/

#include <iostream>

double f1();
double f2();
double f3();
double f4();
double f5();
double rect();
double trap();

/*********************************************
 ** Function: main
 ** Description: menu of options that each carry out different calculations
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: return 0
 ********************************************/
int main() {

   int option;
   std::cout << "Assignment 3: Decomposition/Functions\n" << std::endl;
   do {		   //Creates menu of options
      std::cout << "MENU----------------------" << std::endl;
      std::cout << "1) f1(x) = 2x^5 + x^3 - 10x + 2" << std::endl;
      std::cout << "2) f2(x) = 6x^2 - x + 10" << std::endl;
      std::cout << "3) f3(x) = 5x + 3" << std::endl;
      std::cout << "4) f4(x) = 2x^3 + 120" << std::endl;
      std::cout << "5) f5(x) = 2x^2" << std::endl;
      std::cout << "6) Quit" << std::endl;
      std::cout << std::endl;
      //Prompt user to select an option
      std::cout << "Enter your option: " << std::endl;
      std::cin >> option;
      std::cout << std::endl;

      if (option == 1) {			//Option 1
      }
      else if (option == 2) {			//Option 2
      }
      else if (option == 3) {			//Option 3
      }
      else if (option == 4) {			//Option 4
      }
      else if (option == 5) {			//Option 5
      }
      else if (option == 6) {
	 std::cout << "Exit" << std::endl;
      }
      else {
	 std::cout << "Not a valid option. Please try again: \n" << std::endl;
      }
     
   } while (option != 6);			//End menu loop


   return 0;
}
