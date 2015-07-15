//CS162 001 Lab 4
//Soo-Min Yoo
//David Yun
//Nabeel Shariff
//Fuli Ma

#include <iostream>
#include "dice.cpp"
#include "loadeddice.cpp"

int main() {
	Dice die1(6);
	Dice die2(3);
	int sum;

	sum = die1.roll(6) + die2.roll(3);
	
	std::cout << "Sum: " << sum << std::endl;
	//repeat 10 times

	return 0;
}
