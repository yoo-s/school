#include <iostream>
#include "reptile.hpp"

/*********************************************
 ** Function: Reptile::Reptile
 ** Description: constructor
 ** Parameters: none
 ********************************************/
Reptile::Reptile() : Character() {
	armor = 7;
	strength = 18;
}

/*********************************************
 ** Function: Reptile::~Reptile
 ** Description: destructor
 ** Parameters: none
 ********************************************/
Reptile::~Reptile() {}

/*********************************************
 ** Function: Reptile::attack
 ** Description: attacks target
 ** Parameters: none
 ********************************************/
int Reptile::attack() {
	int a = (rand() % 6 + 1);
	int b = (rand() % 6 + 1);
	int c = (rand() % 6 + 1);
	return a+b+c;
}

/*********************************************
 ** Function: Reptile::defend
 ** Description: defends against attacker
 ** Parameters: none
 ********************************************/
int Reptile::defend() {
	int a = (rand() % 6 + 1);
	return a;
}

