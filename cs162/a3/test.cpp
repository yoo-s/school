#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "char.cpp"
#include "barbarian.cpp"

void round(Character *&a, Character *&b) {			// how to do this??
	int atk1 = a.attack();
	int dfs1 = a.defend();
	int atk2 = b.attack();
	int dfs2 = b.defend();
	int dmg1 = atk2 - dfs1;
	int dmg2 = atk1 - dfs2;
	int app_dmg1 = dmg1 - a.armor();
	int app_dmg2 = dmg2 - b.armor();

	std::cout << a.get_name() << " and " << b.get_name() << " fight!" << std::endl;
	std::cout << "Fighting...\n" << std::endl;

	while (a.strength() > 0 || b.strength() > 0) {
		a.strength() -= app_dmg1;
		b.strength() -= app_dmg2;

		if (a.strength() > b.strength()) {
			winner = a.get_name();
		} else {
			winner = b.get_name();
		}
	}

	std::cout << "The winner is: " << winner << "!" << std::endl;
}

int main() {
	srand(time(NULL));
	
	std::string winner;
	int option;
	int option2;

	std::cout << "Character 1: ";
	std::cin >> option;
	std::cout << "Character 2: ";
	std::cin >> option2;

	if (option == 1) {
		Character *c = new Barbarian("Barbarian");
	/*} else if (option == 2) {
		Goblin *gb = new Goblin("Goblin");
		Character *c = gb;
	} else if (option == 3) {
		Reptile *rp = new Reptile("Reptile");
		Character *c = rp;
	} else if (option == 4) {
		Bluemen *bm = new Bluemen("Blue Men");
		Character *c = bm;
	} else if (option == 5) {
		Shadow *sh = new Shadow("Shadow");
		Character *c = sh;*/
	} else {
		std::cout << "Not valid options." << std::endl;
	}

	if (option == 1 && option2 == 1) {
		round(c, c);
/*	} else if (option == 1 && option2 == 2) {
		round(bb, gb);
	} else if (option == 1 && option2 == 3) {
		round(bb, rp);
	} else if (option == 1 && option2 == 4) {
		round(bb, bm);
	} else if (option == 1 && option2  == 5) {
		round(bb, sh);
	} else if (option == 2 && option2 == 2) {
		round(gb, gb2);
	} else if (option == 2 && option2 == 3) {
		round(gb, rp);
	} else if (option == 2 && option2 == 4) {
		round(gb, bm);
	} else if (option == 2 && option2 == 5) {
		round(gb, sh);
	} else if (option == 3 && option2 == 3) {
		round(rp, rp2);
	} else if (option == 3 && option2 == 4) {
		round(rp, bm);
	} else if (option == 3 && option2 == 5) {
		round(rp, sh);
	} else if (option == 4 && option2 == 4) {
		round(bm, bm2);
	} else if (option == 4 && option2 == 5) {
		round(bm, sh);
	} else if (option == 5 && option2 == 5) {
		round(sh, sh2);*/
	} else {
		std::cout << "Not valid options, please try again." << std::endl;
	}

	return 0;

}
