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

double f(int x, int option);
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
   int method;

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
      std::cout << "Calculate area using rectangle, trapezoid, or both (1, 2, 3): " << std::endl;
      std::cin >> method;
      std::cout << std::endl;

      trap(option);

      if (method == 1) {			//Option 1
	 rect(option);
      }
      else if (method == 2) {			//Option 2
	 trap(option);
      }
      else if (method == 3) {			//Option 3
	 rect(option);
	 trap(option);
      }
      else {
	 std::cout << "Not a valid option. Please try again: \n" << std::endl;
      }

   } while (option != 6);			//End menu loop


   return 0;
}

double rect() {					//Calculates area using rectangles
   int n;
   int a;
   int b;
   double area;

   std::cout << "How many rectangles do you want? " << std::endl;
   std::cin >> n;
   std::cout << "Select starting point, a=" << std::endl;
   std::cin >> a;
   std::cout << "Select ending point, b=" << std::endl;
   std::cin >> b;

   for (int i = a; i <= b; i++) {
      area += ((b-a)/n * f(i, option));
   }
   return area;
}

double trap(int option) {					//Calculates area using trapezoids
   int n;
   int a;
   int b;
   double area;

   std::cout << "How many rectangles do you want? " << std::endl;
   std::cin >> n;
   std::cout << "Select starting point, a=" << std::endl;
   std::cin >> a;
   std::cout << "Select ending point, b=" << std::endl;
   std::cin >> b;

   for (int i = a; i <= b; i++) {
      area += ((b-a)/n * (f(i, option)+f(i+1, option))/2);
   }
   return area;
}

double f(int x, int option) {
   if (option == 1) {
      return (2*x^5 + x^3 - 10*x + 2);
   }
   else if (option == 2) {
      return (6*x^2 - x + 10);
   }
   else if (option == 3) {
      return (5*x + 3);
   }
   else if (option == 4) {
      return (2*x^3 + 120);
   }
   else if (option == 5) {
      return (2*x^2);
   }
   else {
      std::cout << "Invalid option, please try again." << std::endl;
      return 0;
   }
}

