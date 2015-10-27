#include <iostream>
#include "goblin.hpp"

/*********************************************
 ** Function: Goblin::Goblin
 ** Description: constructor
 ** Parameters: none
 ********************************************/
Goblin::Goblin() : Character() {
	armor = 3;
	strength = 8;
}

/*********************************************
 ** Function: Goblin::~Goblin
 ** Description: destructor
 ** Parameters: none
 ********************************************/
Goblin::~Goblin() {}

/*********************************************
 ** Function: Goblin::attack
 ** Description: attacks target
 ** Parameters: none
 ********************************************/
int Goblin::attack() {
	int a = (rand() % 6 + 1);
	int b = (rand() % 6 + 1);
	return a+b;
}

/*********************************************
 ** Function: Goblin::defend
 ** Description: defends against attacker
 ** Parameters: none
 ********************************************/
int Goblin::defend() {
	int a = (rand() % 6 + 1);
	return a;
}

