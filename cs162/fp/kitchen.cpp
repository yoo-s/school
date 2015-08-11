#include <iostream>
#include <string>
#include "kitchen.hpp"
#include "inv.hpp"
#include "item.hpp"

Kitchen::Kitchen() : Room() {}

void Kitchen::options() {
	std::cout << "***Kitchen***\n" << std::endl;
	std::cout << "You are in the kitchen." << std::endl;
	
	std::cout << "Where would you like to go?" << std::endl;
	std::cout << "n) North" << std::endl;
	std::cout << "e) East" << std::endl;
	std::cout << "s) South" << std::endl;
	std::cout << "w) West" << std::endl;
}

void Kitchen::go(bool& game, char action, Room*& current, Inventory inv) {
	char open;

	if (action == 'n') {
		std::cout << "You see a piano.\n";
	} else if (action == 'e') {
		std::cout << "You're at the door to the study.\n";
		std::cout << "a) Open door\nb) Back" << std::endl;
		std::cout << std::endl;
		std::cout << "Enter action: ";
		std::cin >> open;
		if (open == 'a') {
				std::cout << "\n";
				current = current->getE();
				return;
		}
	} else if (action == 's') {
		std::cout << "You're at the door to the foyer.\n";
	} else if (action == 'w') {
		std::cout << "You see a large picture frame hung on the wall.\n";
	}
}

