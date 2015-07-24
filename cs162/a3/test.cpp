/*********************************************
 ** Program: test.cpp
 ** Author: Soo-Min Yoo
 ** Date: 07/23/15
 ** Description: program that uses inheritance and polymorphism in a fantasy combat game.
 ** Input: none
 ** Output: none
 ********************************************/

#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "char.hpp"
#include "barbarian.hpp"
#include "goblin.hpp"
#include "reptile.hpp"
#include "bluemen.hpp"
#include "shadow.hpp"

/*********************************************
 ** Function: round
 ** Description: conducts rounds of combat until only one character has hp remaining.
 ** Parameters: Character *&a, Character *&b
 ********************************************/
void round(Character *&a, Character *&b) {
	int atk = a->attack();					// Attacker roll
	int dfs = b->defend();					// Defender roll
	int dmg = atk - dfs;					// Damage
	int app_dmg = dmg - b->armor;			// Applied damage

	std::cout << std::endl;

	// if applied damage is less than 0, target's hp stays the same
	if (app_dmg < 0) {
		b->strength = b->strength;
	// else target's strength decreases by applied damage
	} else {
		b->strength -= app_dmg;
	}
	
	// print results of each round
	std::cout << a->charname << " inflicts " << atk << " damage." << std::endl;
	std::cout << b->charname << " uses " << dfs << " defense." << std::endl;
	std::cout << b->charname << " takes a total of " << app_dmg << " damage." << std::endl;
	std::cout << b->charname << " has " << b->strength << " hp left." << std::endl;
	std::cout << std::endl;

}

/*********************************************
 ** Function: main
 ** Description: runs program
 ********************************************/
int main() {
	srand(time(NULL));
	
	int option;
	int option2;
	Character *c;
	Character *c2;
	int roundnum = 1;

	// prompt user for two character types
	std::cout << "Character 1: ";
	std::cin >> option;
	std::cout << "Character 2: ";
	std::cin >> option2;

	// assign character type depending on input integer
	if (option == 1) {
		c = new Barbarian();
		c->set_name("Barbarian");
	} else if (option == 2) {
		c = new Goblin();
		c->set_name("Goblin");
	} else if (option == 3) {
		c = new Reptile();
		c->set_name("Reptile");
	} else if (option == 4) {
		c = new Bluemen();
		c->set_name("Blue Men");
	} else if (option == 5) {
		c = new Shadow();
		c->set_name("Shadow");
	} else {
		std::cout << "Not valid options." << std::endl;
	}
	// do the same for option2
	if (option2 == 1) {
		c2 = new Barbarian();
		c2->set_name("Barbarian");
	} else if (option2 == 2) {
		c2 = new Goblin();
		c2->set_name("Goblin");
	} else if (option2 == 3) {
		c2 = new Reptile();
		c2->set_name("Reptile");
	} else if (option2 == 4) {
		c2 = new Bluemen();
		c2->set_name("Blue Men");
	} else if (option2 == 5) {
		c2 = new Shadow();
		c2->set_name("Shadow");
	} else {
		std::cout << "Not valid options." << std::endl;
	}

	// repeat rounds until one or both characters run out of hp
	while (c->strength > 0 && c2->strength > 0) {
		std::cout << "Round " << roundnum << "--------------------" << std::endl;
		std::cout << c->charname << " attacks " << c2->charname << std::endl;
		round(c, c2);
		std::cout << c2->charname << " attacks " << c->charname << std::endl;
		round(c2, c);
		roundnum++;
	}

	// print winner
	if (c->strength > c2->strength && c->strength > 0) {
		std::cout << "The winner is: " << c->charname << "!" << std::endl;
	} else if (c->strength < c2->strength && c2->strength > 0) {
		std::cout << "The winner is: " << c2->charname << "!" << std::endl;
	} else if (c->strength == c2->strength || (c->strength <= 0 && c2->strength <= 0)) {
		std::cout << "It's a draw!" << std::endl;
	}


	return 0;

}
