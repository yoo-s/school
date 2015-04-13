/*********************************************
 ** Program: assign01.cpp
 ** Author: Soo-Min Yoo
 ** Date: 04/10/15
 ** Description: program exploring the different data types in C++ and their differing value ranges.
 ** Input: none
 ** Output: return 0
 ********************************************/

#include <iostream>
#include <climits>
#include <cmath>
#include <cfloat>

/*********************************************
 ** Function: main
 ** Description: prints data type sizes, macro values, and their min and max values.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: return 0
 ********************************************/
int main() {
	std::cout << "Assignment 1: All About Numbers in C++\n\n";

	std::cout << "Sizes of primitive types:" << std::endl;
	std::cout << "int: "    << sizeof(int)    << std::endl;
	std::cout << "short: "  << sizeof(short)  << std::endl;
	std::cout << "long: "   << sizeof(long)   << std::endl;
	std::cout << "float: "  << sizeof(float)  << std::endl;
	std::cout << "double: " << sizeof(double) << std::endl;
	std::cout << "bool: "   << sizeof(bool)   << std::endl;
	std::cout << "char: "   << sizeof(char)   << std::endl;
	std::cout << std::endl;

	int sInt = INT_MIN;
	int lInt = INT_MAX;
	unsigned int sUint = 0;
	unsigned int lUint = UINT_MAX;
	short int sShort = SHRT_MIN;
	short int lShort = SHRT_MAX;
	unsigned short int sUshort = 0;
	unsigned short int lUshort = USHRT_MAX;
	long int sLong = LONG_MIN;
	long int lLong = LONG_MAX;
	unsigned long int sUlong = 0;
	unsigned long int lUlong = ULONG_MAX;

	std::cout << "Values of macros:" << std::endl;
	std::cout << "Smallest signed int: "     << sInt    << std::endl;
	std::cout << "Largest signed int: "      << lInt    << std::endl;
	std::cout << "Smallest unsigned int: "   << sUint   << std::endl;
	std::cout << "Largest unsigned int: "    << lUint   << std::endl;
	std::cout << "Smallest signed short: "   << sShort  << std::endl;
	std::cout << "Largest signed short: "    << lShort  << std::endl;
	std::cout << "Smallest unsigned short: " << sUshort << std::endl;
	std::cout << "Largest unsigned short: "  << lUshort << std::endl;
	std::cout << "Smallest signed long: "    << sLong   << std::endl;
	std::cout << "Largest signed long: "     << lLong   << std::endl;
	std::cout << "Smallest unsigned long: "  << sUlong  << std::endl;
	std::cout << "Largest unsigned long: "   << lUlong  << std::endl;
	std::cout << std::endl;

	std::cout << "Values of variables in respective order:" << std::endl;
	std::cout << sInt - 1    << std::endl;
	std::cout << lInt + 1    << std::endl;
	std::cout << sUint - 1   << std::endl;
	std::cout << lUint + 1   << std::endl;
	std::cout << sShort - 1  << std::endl;
	std::cout << lShort + 1  << std::endl;
	std::cout << sUshort - 1 << std::endl;
	std::cout << lUshort + 1 << std::endl;
	std::cout << sLong - 1   << std::endl;
	std::cout << lLong + 1   << std::endl;
	std::cout << sUlong - 1  << std::endl;
	std::cout << lUlong + 1  << std::endl;
	std::cout << std::endl;

	std::cout << "Largest/smallest of short, int, and long:" << std::endl;
	std::cout << "Smallest signed int: "     << (0 - pow (2, (sizeof(int) * 8)) + 1) / 2 << std::endl;
	std::cout << "Largest signed int: "      << (pow (2, (sizeof(int) * 8)) - 1) / 2 << std::endl;
	std::cout << "Smallest unsigned int: "   << 0 << std::endl;
	std::cout << "Largest unsigned int: "    << pow (2, (sizeof(unsigned int) * 8)) - 1 << std::endl;
	std::cout << "Smallest signed short: "   << (0 - pow (2, (sizeof(short) * 8)) + 1) / 2 << std::endl;
	std::cout << "Largest signed short: "    << (pow (2, (sizeof(short) * 8)) - 1) / 2 << std::endl;
	std::cout << "Smallest unsigned short: " << 0 << std::endl;
	std::cout << "Largest unsigned short: "  << pow (2, (sizeof(unsigned short) * 8)) - 1  << std::endl;
	std::cout << "Smallest signed long: "    << (0 - pow (2, (sizeof(long) * 8)) + 1) / 2 << std::endl;
	std::cout << "Largest signed long: "     << (pow (2, (sizeof(long) * 8)) - 1) / 2 << std::endl;
	std::cout << "Smallest unsigned long: "  << 0 << std::endl;
	std::cout << "Largest unsigned long: "   << pow (2, (sizeof(unsigned long) * 8)) - 1 << std::endl;
	std::cout << std::endl;

	std::cout << "Number of digits in mantissa: " << std::endl;
	std::cout << "Float: "  << FLT_MANT_DIG << std::endl;
	std::cout << "Double: " << DBL_MANT_DIG << std::endl;
	std::cout << std::endl;
	std::cout << "Largest and smallest exponent values: " << std::endl;
	std::cout << "Float (smallest): "  << FLT_MIN_EXP << std::endl;
	std::cout << "Float (largest): "   << FLT_MAX_EXP << std::endl;
	std::cout << "Double (smallest): " << DBL_MIN_EXP << std::endl;
	std::cout << "Double (largest): "  << DBL_MAX_EXP << std::endl;
	std::cout << std::endl;

	float fl;
	double dbl;

	std::cout << "Enter a real number for a float: " << std::endl;
	std::cin >> fl;

	std::cout << "Enter a real number for a double: " << std::endl;
	std::cin >> dbl;

	fl = fl - .01;
	dbl = dbl - .01;

	std::cout << std::endl;
	std::cout << "Entered float value - .01 = "  << fl << std::endl;
	std::cout << "Entered double value - .01 = " << dbl << std::endl;


	return 0;
}
