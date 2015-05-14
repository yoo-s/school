/*********************************************
 ** Program: assign04.cpp
 ** Author: Soo-Min Yoo
 ** Date: 05/13/15
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
#include <stdlib.h>

double f(int x, int option);
void rect(int option, int a, int b, int n);
void trap(int option, int a, int b, int n);

/*********************************************
 ** Function: main
 ** Description: menu of options that each carry out different calculations
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: return 0
 ********************************************/

int main(int argc, char *argv[]) {

   std::cout << "There are " << argc << " arguments:" << std::endl;
   for (int i = 0; i < argc; i++) {
      std::cout << "Argument " << i << " " << argv[i] << std::endl;
   }
   //if user didn't provide filename command line arg, print error/exit
   if (argc <= 1) {
      std::cerr << "Usage: " << argv[0] << " function, starting/ending values, method, # of rectangles/trapezoids" << std::endl;
      return 1;
   }
   int option = atof(argv[1]);
   int a = atof(argv[2]);
   int b = atof(argv[3]);
   int method = atof(argv[4]);
   int n = atof(argv[5]);

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
      /*std::cout << "Enter your option: " << std::endl;
      std::cin >> option;*/
      //Prompt user to select a method
      /*std::cout << "Calculate area using rectangle, trapezoid, or both (1, 2, 3): " << std::endl;
      std::cin >> method;*/
      std::cout << std::endl;

      if (method == 1) {			//Method 1: Rectangles
	 rect(option, a, b, n);
      }
      else if (method == 2) {			//Method 2: Trapezoids
	 trap(option, a, b, n);
      }
      else if (method == 3) {			//Method 3: Both
	 rect(option, a, b, n);
	 trap(option, a, b, n);
      }
      else {
	 std::cout << "Not a valid option. Please try again: \n" << std::endl;
      }

   } while (option != 6);			//End menu loop

   return 0;
}

/*********************************************
 ** Function: rect
 ** Description: calculates area using rectangles
 ** Parameters: int option
 ** Pre-Conditions: none
 ** Post-Conditions: return 0
 ********************************************/

void rect(int option, int a, int b, int n) {			//Calculates area using rectangles
   double area;

   /*std::cout << "How many rectangles do you want? " << std::endl;
   std::cin >> n;
   std::cout << "Select starting point, a=" << std::endl;
   std::cin >> a;
   std::cout << "Select ending point, b=" << std::endl;
   std::cin >> b;*/

   for (int i = a; i <= b; i++) {
      area += (double)((b-a)/n * f(i, option));
   }
   std::cout << "The area of the function " << option << " from  " << a << " to " << b << " using rectangles is " << area << std::endl;
   std::cout << std::endl;
}

/*********************************************
 ** Function: trap
 ** Description: calculates area using trapezoids
 ** Parameters: int option
 ** Pre-Conditions: none
 ** Post-Conditions: return 0
 ********************************************/

void trap(int option, int a, int b, int n) {			//Calculates area using trapezoids
   double area;

   /*std::cout << "How many trapezoids do you want? " << std::endl;
   std::cin >> n;
   std::cout << "Select starting point, a=" << std::endl;
   std::cin >> a;
   std::cout << "Select ending point, b=" << std::endl;
   std::cin >> b;*/

   for (int i = a; i <= b; i++) {
      area += (double)((b-a)/n * (f(i, option)+f(i+1, option))/2);
   }
   std::cout << "The area of the function " << option << " from  " << a << " to " << b << " using trapezoids is " << area << std::endl;
   std::cout << std::endl;
 
}

/*********************************************
 ** Function: f
 ** Description: calculates height of each rectangle/trapezoid for each function
 ** Parameters: int x, int option
 ** Pre-Conditions: none
 ** Post-Conditions: return rectangle/trapezoid height
 ********************************************/

double f(int x, int option) {			//Calculates height of rectangle/trapezoid depending on function
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

