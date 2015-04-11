/*********************************************
 ** Program: assign01.cpp
 ** Author: Soo-Min Yoo
 ** Date: 04/10/15
 ** Description: 
 ** Input: 
 ** Output: 
 ********************************************/

#include <iostream>
#include <climits>
#include <cmath>
#include <cfloat>

int main() {

	std::cout << "Sizes of primitive types:" << std::endl;
	std::cout << sizeof(int) << std::endl;
	std::cout << sizeof(short) << std::endl;
	std::cout << sizeof(long) << std::endl;
	std::cout << sizeof(float) << std::endl;
	std::cout << sizeof(double) << std::endl;
	std::cout << sizeof(bool) << std::endl;
	std::cout << sizeof(char) << std::endl;

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
	std::cout << sInt << std::endl;
	std::cout << lInt << std::endl;
	std::cout << sUint << std::endl;
	std::cout << lUint << std::endl;
	std::cout << sShort << std::endl;
	std::cout << lShort << std::endl;
	std::cout << sUshort << std::endl;
	std::cout << lUshort << std::endl;
	std::cout << sLong << std::endl;
	std::cout << lLong << std::endl;
	std::cout << sUlong << std::endl;
	std::cout << lUlong << std::endl;

	std::cout << "Values of variables:" << std::endl;
	std::cout << sInt - 1 << std::endl;
	std::cout << lInt + 1 << std::endl;
	std::cout << sUint - 1 << std::endl;
	std::cout << lUint + 1 << std::endl;
	std::cout << sShort - 1 << std::endl;
	std::cout << lShort + 1 << std::endl;
	std::cout << sUshort - 1 << std::endl;
	std::cout << lUshort + 1 << std::endl;
	std::cout << sLong - 1 << std::endl;
	std::cout << lLong + 1 << std::endl;
	std::cout << sUlong - 1 << std::endl;
	std::cout << lUlong + 1 << std::endl;

	std::cout << "Largest/smallest short, int, and long:" << std::endl;
	std::cout << "Largest unsigned short: "  << pow (2, (sizeof(unsigned short) * 8)) - 1 << std::endl;
	std::cout << "Smallest unsigned short: " << 0 << std::endl;
	std::cout << "Largest signed short: "    << 0 << std::endl;
	std::cout << "Smallest signed short: "   << 0 << std::endl;
	std::cout << "Largest unsigned int: "    << 0 << std::endl;
	std::cout << "Smallest unsigned int: "   << 0 << std::endl;
	std::cout << "Largest signed int: "      << 0 << std::endl;
	std::cout << "Smallest signed int: "     << 0 << std::endl;
	std::cout << "Largest unsigned long: "   << 0 << std::endl;
	std::cout << "Smallest unsigned long: "  << 0 << std::endl;
	std::cout << "Largest signed long: "     << 0 << std::endl;
	std::cout << "Smallest signed long: "    << 0 << std::endl;

	std::cout << 0 - pow(2, (sizeof(sInt) * 8 - 1)) << std::endl;
	std::cout << 2 * (pow(2, (sizeof(lInt) * 8 - 1) - 1)) << std::endl;
	std::cout << 0 << std::endl;
	std::cout << pow (2, (sizeof(lUint) * 8) - 1) << std::endl;
	std::cout << 0 - pow(2, (sizeof(sShort) * 8 - 1)) << std::endl;
	std::cout << 2 * (pow(2, (sizeof(lShort) * 8 - 1) - 1)) << std::endl;
	std::cout << pow (2, (sizeof(lUshort) * 8) - 1) << std::endl;
	std::cout << 0 - pow(2, (sizeof(sInt) * 8 - 1)) << std::endl;
	std::cout << 2 * (pow(2, (sizeof(lInt) * 8 - 1) - 1)) << std::endl;
	std::cout << pow (2, (sizeof(lUlong) * 8) - 1) << std::endl;

	std::cout << "Floats and doubles:" << std::endl;
	std::cout << FLT_MANT_DIG << std::endl;
	std::cout << DBL_MANT_DIG << std::endl;
	std::cout << FLT_MIN_EXP << std::endl;
	std::cout << FLT_MAX_EXP << std::endl;
	std::cout << DBL_MIN_EXP << std::endl;
	std::cout << DBL_MAX_EXP << std::endl;

	float fl;
	double dbl;

	std::cout << "Enter a real number for a float: " << std::endl;
	std::cin >> fl;

	std::cout << "Enter a real number for a double: " << std::endl;
	std::cin >> dbl;

	fl = fl - .01;
	dbl = dbl - .01;

	std::cout << fl << std::endl;
	std::cout << dbl << std::endl;


	return 0;
}
