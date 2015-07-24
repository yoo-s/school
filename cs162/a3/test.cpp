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


void round(Character *&a, Character *&b, int roundnum) {
	int atk = a->attack();
	int dfs = b->defend();
	int dmg = atk - dfs;
	int app_dmg = dmg - b->armor;

	std::cout << a->charname << " and " << b->charname << " fight!" << std::endl;
	std::cout << std::endl;

	if (app_dmg < 0) {
		b->strength = b->strength;
	} else {
		b->strength -= app_dmg;
	}
	
	std::cout << "Round " << roundnum << ":" << std::endl;
	std::cout << a->charname << " inflicts " << atk << " damage." << std::endl;
	std::cout << b->charname << " uses " << dfs << " defense." << std::endl;
	std::cout << b->charname << " takes a total of " << app_dmg << " damage." << std::endl;
	std::cout << b->charname << " has " << b->strength << " hp left." << std::endl;
	std::cout << std::endl;

}

int main() {
	srand(time(NULL));
	
	int option;
	int option2;
	Character *c;
	Character *c2;
	int roundnum = 1;
	std::string winner;

	std::cout << "Character 1: ";
	std::cin >> option;
	std::cout << "Character 2: ";
	std::cin >> option2;

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

	round(c, c2, roundnum);
	/*while (c->strength > 0 || c2->strength > 0) {
		round(c, c2, roundnum);
		roundnum++;
		round(c2, c, roundnum);
		roundnum++;
	}*/

	if (c->strength > c2->strength) {
		winner = c->charname;
	} else {
		winner = c2->charname;
	}

	std::cout << "The winner is: " << winner << "!" << std::endl;


	return 0;

}
