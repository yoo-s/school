#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "char.cpp"
#include "barbarian.cpp"

int main() {
	srand(time(NULL));
	
	Barbarian *b1 = new Barbarian("Barbarian1");
	Barbarian *b2 = new Barbarian("Barbarian2");
	Character *c1 = b1;
	Character *c2 = b2;

	std::string winner;
	int option;
	int option2;

	std::cout << "Character 1: ";
	std::cin >> option;
	std::cout << "Character 2: ";
	std::cin >> option2;


	std::cout << b1.get_name() << " and " << b2.get_name() << " fight!" << std::endl;
	std::cout << "Fighting...\n" << std::endl;

	while (b1.strength() > 0 || b2.strength() > 0) {
		int atk1 = b1.attack();
		int dfs1 = b1.defend();
		int atk2 = b2.attack();
		int dfs2 = b2.defend();
		int dmg1 = atk2 - dfs1;
		int dmg2 = atk1 - dfs2;
		int app_dmg1 = dmg1 - b1.armor();
		int app_dmg2 = dmg2 - b2.armor();
		
		b1.strength() -= app_dmg1;
		b2.strength() -= app_dmg2;

		if (b1.strength() > b2.strength()) {
			winner = b1.get_name();
		} else {
			winner = b2.get_name();
		}
	}

	std::cout << "The winner is: " << winner << "!" << std::endl;

	return 0;

}
