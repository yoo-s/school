/*********************************************
 ** Program: buttercup.cpp
 ** Author: Soo-Min Yoo
 ** Date: 07/02/15
 ** Description: program that uses a vector to determine which suitor will
 ** marry the princess.
 ** Input: none
 ** Output: return 0
 ********************************************/

#include <iostream>
#include <vector>
#include <algorithm>

bool third(int a) {
	if (a%3) {
		return true;
	} else {
		return false;
	}
}

/*********************************************
 ** Function: main
 ** Description: creates vector of input number of suitors each assigned a number,
 ** eliminates every third suitor until one winner remains.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: return 0
 ********************************************/
int main() {
	int suitors;

	// Prompt user for number of suitors
	std::cout << "How many suitors? ";
	std::cin >> suitors;

	// Initialize vector of input size, assigns each element with a number
	std::vector<int> vect(suitors);
	std::vector<int>::iterator it = vect.begin();
	for (int i = 0; i < suitors; i++) {
		vect.push_back(i+1);
	}
	// Prints out suitor numbers
	for (int i = 0; i < suitors; i++) {
		std::cout << vect[i] << " ";
	}

	// Loop through vector, eliminating every third element (suitor)
	while (vect.size() > 1) {
		for (int i = 2; i < vect.size(); i+=2) {
			std::cout << vect[i];
			vect.erase(i);
		}
	}

	// Prints remaining suitor number
	std::cout << std::endl;
	for (int i = 0; i < vect.size(); i++) {
		std::cout << vect[i] << " ";
	}
	int winner = vect[0];
	std::cout << std::endl;
	std::cout << "The winner would be suitor " << winner << std::endl;

	return 0;

}

