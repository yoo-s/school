/*********************************************
 ** Program: assign02.cpp
 ** Author: Soo-Min Yoo
 ** Date: 04/22/15
 ** Description: program that gives a menu of options, each of which executes various calculations
                 using conditional and repetitive statements.
 ** Input: none
 ** Output: return 0
 ********************************************/

#include <iostream>


/*********************************************
 ** Function: main
 ** Description: menu of options that each carry out different calculations
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: return 0
 ********************************************/
int main() {

   int option;
   std::cout << "Assignment 2: Conditional & Repetitive Statements\n" << std::endl;
   do {		   //Creates menu of options
      std::cout << "MENU----------------------" << std::endl;
      std::cout << "1) Highest of ten integers" << std::endl;
      std::cout << "2) Money earning rate" << std::endl;
      std::cout << "3) Average generator" << std::endl;
      std::cout << "4) Decimal to binary" << std::endl;
      std::cout << "5) Exit" << std::endl;
      std::cout << std::endl;
      //Prompt user to select an option
      std::cout << "Enter your option: " << std::endl;
      std::cin >> option;
      std::cout << std::endl;

      if (option == 1) {			//Option 1
	 int value;
	 int amount = 0;
	 int highest = 0;

	 //Prompts user to enter 10 integer values and prints the highest number
	 while (amount < 10) {
	    std::cout << "Enter an integer value: " << std::endl;
	    std::cin >> value;
	    amount++;
	    if (value > highest) {
	       highest = value;
	    } else {
	       highest = highest;
	    }
	 }
      	 std::cout << "The highest number was: " << highest << std::endl;
	 std::cout << std::endl;

      } else if (option == 2) {			//Option 2
	 double earned;
	 double target;
	 double rate;
	 int years = 0;

	 std::cout << "Enter starting value: " << std::endl;
	 std::cin >> earned;
	 std::cout << "Enter target value: " << std::endl;
	 std::cin >> target;
	 std::cout << "Enter annual percentage rate: " << std::endl;
	 std::cin >> rate;
	 while (earned < target) {		//Calculates how many years it takes to reach target
	    earned *= (1+(rate/100));
	    years++;
	 }
	 std::cout << "It will take " << years << " years to reach the target value." << std::endl;
	 std::cout << std::endl;

      } else if (option == 3) {			//Option 3
	 int value;
	 int count = 0;
	 int sum = 0;

	 std::cout << "Enter a series of positive values. Enter -1 to end the series." << std::endl;
	 do {
	    std::cout << "Enter a positive value: " << std::endl;
	    std::cin >> value;
	    if (value != -1 && value >= 1) {
	       sum += value;
	       count++;
	    } else {
	       sum = sum;
	       count = count;
	    }
	 } while (value != -1 && value >= 1);
	 std::cout << "The average of your values is " << (double)sum/count << "." << std::endl;
	 std::cout << std::endl;

      } else if (option == 4) {			//Option 4
	 int dec;
	 int bin = 0;
	 int tens = 1;

	 do {
	    std::cout << "Enter a decimal (base 10) number: " << std::endl;
	    std::cin >> dec;
	    while (dec > 0) {			//Converts decimal to binary by adding the remainder of
	       bin += (dec%2)*tens;		//the decimal divided by two to each tens place.
	       dec /= 2;
	       tens *= 10;
	    }
	    std::cout << "The binary version of this number is " << bin << "." << std::endl;
	    std::cout << std::endl;
	 } while (dec > 0);

      } else if (option == 5) {			//Option 5
	 std::cout << "Exit" << std::endl;
      } else {
	 std::cout << "Not a valid option. Please try again: \n" << std::endl;
      }
      
   } while (option != 5);			//End menu loop


      return 0;
}
