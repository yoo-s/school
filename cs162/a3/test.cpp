#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "char.cpp"
#include "barbarian.cpp"
#include "goblin.cpp"
#include "reptile.cpp"
#include "bluemen.cpp"
#include "shadow.cpp"


void round(Character *&a, Character *&b, int roundnum) {
	int atk1 = a->attack();
	int dfs1 = a->defend();
	int atk2 = b->attack();
	int dfs2 = b->defend();
	int dmg1 = atk1 - dfs2;
	int dmg2 = atk2 - dfs1;
	int app_dmg1 = dmg2 - a->armor;
	int app_dmg2 = dmg1 - b->armor;

	std::cout << a->get_name() << " and " << b->get_name() << " fight!" << std::endl;
	std::cout << std::endl;

	a->strength -= app_dmg1;
	b->strength -= app_dmg2;

	std::cout << "Round " << roundnum << ":" << std::endl;
	std::cout << a->get_name() << " inflicts " << atk1 << " damage." << std::endl;
	std::cout << b->get_name() << " uses " << dfs2 << " defense." << std::endl;
	std::cout << b->get_name() << " takes a total of " << app_dmg2 << " damage." << std::endl;
	std::cout << b->get_name() << " has " << b->strength << " hp left." << std::endl;
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
		c = new Barbarian("Barbarian");
	} else if (option == 2) {
		c = new Goblin("Goblin");
	} else if (option == 3) {
		c = new Reptile("Reptile");
	} else if (option == 4) {
		c = new Bluemen("Blue Men");
	} else if (option == 5) {
		c = new Shadow("Shadow");
	} else {
		std::cout << "Not valid options." << std::endl;
	}
	if (option2 == 1) {
		c2 = new Barbarian("Barbarian");
	} else if (option == 2) {
		c2 = new Goblin("Goblin");
	} else if (option == 3) {
		c2 = new Reptile("Reptile");
	} else if (option == 4) {
		c2 = new Bluemen("Blue Men");
	} else if (option == 5) {
		c2 = new Shadow("Shadow");
	} else {
		std::cout << "Not valid options." << std::endl;
	}

	while (c->strength > 0 || c2->strength > 0) {
		round(c, c2, roundnum);
		roundnum++;
		round(c2, c, roundnum);
		roundnum++;
	}

	if (c->strength > c2->strength) {
		winner = c->get_name();
	} else {
		winner = c2->get_name();
	}

	std::cout << "The winner is: " << winner << "!" << std::endl;


	return 0;

}
