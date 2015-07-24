#include <iostream>
#include "shadow.hpp"

/*********************************************
 ** Function: Shadow::Shadow
 ** Description: constructor
 ** Parameters: none
 ********************************************/
Shadow::Shadow() : Character() {
	armor = 0;
	strength = 12;
}

/*********************************************
** Function: Shadow::~Shadow
** Description: destructor
** Parameters: none
********************************************/
Shadow::~Shadow() {}

/*********************************************
 ** Function: Shadow::attack
 ** Description: attacks target
 ** Parameters: none
 ********************************************/
int Shadow::attack() {
	int a = (rand() % 10 + 1);
	int b = (rand() % 10 + 1);
	return a+b;
}

/*********************************************
 ** Function: Shadow::defend
 ** Description: defends against attacker
 ** Parameters: none
 ********************************************/
int Shadow::defend() {
	int a = (rand() % 6 + 1);
	return a;
}

