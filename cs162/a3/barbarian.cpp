#include <iostream>
#include "barbarian.hpp"

/*********************************************
 ** Function: Barbarian::Barbarian
 ** Description: constructor
 ** Parameters: none
 ********************************************/
Barbarian::Barbarian() : Character() {
	armor = 0;
	strength = 12;
}

/*********************************************
 ** Function: Barbarian::~Barbarian
 ** Description: destructor
 ** Parameters: none
 ********************************************/
Barbarian::~Barbarian() {}

/*********************************************
 ** Function: Barbarian::attack
 ** Description: attacks target
 ** Parameters: none
 ********************************************/
int Barbarian::attack() {
	int a = (rand() % 6 + 1);
	int b = (rand() % 6 + 1);
	return a+b;
}

/*********************************************
 ** Function: Barbarian::defend
 ** Description: defends against attacker
 ** Parameters: none
 ********************************************/
int Barbarian::defend() {
	int a = (rand() % 6 + 1);
	int b = (rand() % 6 + 1);
	return a+b;
}

