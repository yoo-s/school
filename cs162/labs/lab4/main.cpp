//CS162 001 Lab 4
//Soo-Min Yoo
//David Yun
//Nabeel Shariff
//Fuli Ma

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "dice.cpp"
#include "loadeddice.cpp"

int main() {
	srand(time(NULL));

	Dice die1(5);
	Dice die2(2);
	loadedDice ld1(5);
	loadedDice ld2(2);
	int roll1 = die1.roll();
	int roll2 = die2.roll();
	int ldroll1 = ld1.roll();
	int ldroll2 = ld2.roll();
	int sum;
	int ldsum;

	sum = roll1 + roll2;
	ldsum = ldroll1 + ldroll2;
	
	std::cout << "First die: " << roll1 
		<< "  Second die: " << roll2 << std::endl;
	std::cout << "Sum: " << sum << std::endl;
	std::cout << "First loaded die: " << ldroll1 
		<< "  Second loaded die: " << ldroll2 << std::endl;
	std::cout << "Loaded Sum: " << ldsum << std::endl;
	std::cout << std::endl;

	return 0;
}
