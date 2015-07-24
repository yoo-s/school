#include <iostream>
#include "bluemen.hpp"

/*********************************************
 ** Function: Bluemen::Bluemen
 ** Description: constructor
 ** Parameters: none
 ********************************************/
Bluemen::Bluemen() : Character() {
	armor = 3;
	strength = 12;
}

/*********************************************
 ** Function: Bluemen::~Bluemen
 ** Description: destructor
 ** Parameters: none
 ********************************************/
Bluemen::~Bluemen() {}

/*********************************************
 ** Function: Bluemen::attack
 ** Description: attacks target
 ** Parameters: none
 ********************************************/
int Bluemen::attack() {
	int a = (rand() % 10 + 1);
	int b = (rand() % 10 + 1);
	return a+b;
}

/*********************************************
 ** Function: Bluemen::defend
 ** Description: defends against attacker
 ** Parameters: none
 ********************************************/
int Bluemen::defend() {
	int a = (rand() % 6 + 1);
	int b = (rand() % 6 + 1);
	int c = (rand() % 6 + 1);
	return a+b+c;
}

