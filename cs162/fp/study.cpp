#include <iostream>
#include <string>
#include "study.hpp"
#include "item.hpp"

Study::Study() : Room() {}

void Study::options() {
	std::cout << "***Study Room***\n";
	std::cout << "You are in the study room." << std::endl;
	std::cout << std::endl;
	std::cout << "Where would you like to go? \n";
	std::cout << "n) North\n";
	std::cout << "e) East\n";
	std::cout << "s) South\n";
	std::cout << "w) West\n";
}

void Study::go(bool& game, char action, Room*& current, Inventory inv) {
	char open;

	if (action == 'n') {
		std::cout << "You see a drawer desk.\n";
		std::cout << "a) Open drawer\nb) Back" << std::endl;
		std::cout << std::endl;
		std::cout << "Enter action: ";
		std::cin >> open;
		if (open == 'a') {
			if (inv.woodenkey = true) {
				std::cout << "You open the wooden chest with the wooden key.\n";
				std::cout << "There's a notepad inside that reads, '9+4*152'.\n";
				inv.woodenkey = false;
				return;
			} else {
				std::cout << "\n";
				return;
			}
		}
	} else if (action == 'e') {
		std::cout << "You see a wooden chest.\n";
	} else if (action == 's') {
		std::cout << "You're at the door to the kitchen.\n";
	} else if (action == 'w') {
		std::cout << "You're at the door to the piano room.\n";
	}
}

