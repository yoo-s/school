/*********************************************
 ** Program: assign04.cpp
 ** Author: Soo-Min Yoo
 ** Date: 05/13/15
 ** Description: program that uses command line arguments to calculate the area under a function using both the rectangle and trapezoid methods for solving integration problems.
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
 ** Description: calculates various integrals given the function, starting and ending values, method, and number of rectangles/trapezoids
 ** Parameters: int argc, char *argv[]
 ** Pre-Conditions: none
 ** Post-Conditions: return 0
 ********************************************/

int main(int argc, char *argv[]) {

   std::cout << "Assignment 4: Command Line Arguments\n" << std::endl;
   std::cout << std::endl;

   std::cout << "Function: " << argv[2] << std::endl;
   std::cout << "Starting value: " << argv[4] << std::endl;
   std::cout << "Ending value: " << argv[6] << std::endl;
   std::cout << "Method: " << argv[8] << std::endl;
   std::cout << "# of rect/trap's: " << argv[10] << std::endl;
   std::cout << std::endl;

   std::cout << std::endl;
   
   if (argc <= 1) {				//if the user didn't provide any command line arguments, print error message and exit
      std::cerr << "Usage: " << argv[0] << " function, starting/ending values, method, # of rectangles/trapezoids" << std::endl;
      return 1;
   }
   char func = argv[1][0];				// Assign argv values
   int option;
   char start = argv[3][0];
   int a = atof(argv[4]);
   char end = argv[5][0];
   int b = atof(argv[6]);
   char method = argv[7][0];
   int m = atof(argv[8]);
   char num = argv[9][0];
   int n = atof(argv[10]);

   if (argv[1][0] == 'f') {		// If f, next argv is function
      option = atof(argv[2]);
   }
   else {
      std::cout << "Not a valid argument." << std::endl;
   }
   if (argv[3][0] == 'a') {		// If a, next argv is start value
      start = atof(argv[4]);
   }
   else {
      std::cout << "Not a valid argument." << std::endl;
   }
   if (argv[5][0] == 'b') {		// If b, next argv is end value
      end = atof(argv[6]);
   }
   else {
      std::cout << "Not a valid argument." << std::endl;
   }
   if (argv[7][0] == 'm') {		// If m, next argv is method
      method = atof(argv[8]);
   }
   else {
      std::cout << "Not a valid argument." << std::endl;
   }
   if (argv[9][0] == 'n') {		// If n, next argv is number of rect/trap's
      num = atof(argv[10]);
   }
   else {
      std::cout << "Not a valid argument." << std::endl;
   }

   if (method == 1) {				//Method 1: Rectangles
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
   return 0;
}

/*********************************************
 ** Function: rect
 ** Description: calculates area using rectangles
 ** Parameters: int option, int a, int b, int n
 ** Pre-Conditions: none
 ** Post-Conditions: none
 ********************************************/

void rect(int option, int a, int b, int n) {			//Calculates area using rectangles
   double area;

   for (int i = a; i <= b; i++) {
      area += (double)((b-a)/n * f(i, option));
   }
   std::cout << "The area of the function " << option << " from  " << a << " to " << b << " using rectangles is " << area << std::endl;
   std::cout << std::endl;
}

/*********************************************
 ** Function: trap
 ** Description: calculates area using trapezoids
 ** Parameters: int option, int a, int b, int n
 ** Pre-Conditions: none
 ** Post-Conditions: none
 ********************************************/

void trap(int option, int a, int b, int n) {			//Calculates area using trapezoids
   double area;

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

double f(int x, int option) {					//Calculates height of rectangle/trapezoid depending on function
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

