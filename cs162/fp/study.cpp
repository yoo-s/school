#include <iostream>
#include <string>
#include "study.hpp"
#include "item.hpp"

/*Study::Study(std::string n, std::string i) :
		Room(n, i) {
	name = n;
	info = i;
}*/

Study::Study() : Room() {}

void Study::options() {
	std::cout << "***Study Room***\n";
	std::cout << std::endl;
	std::cout << "Where would you like to go? \n";
	std::cout << "n) North\n";
	std::cout << "e) East\n";
	std::cout << "s) South\n";
	std::cout << "w) West\n";
}

void Study::go(char action, Room*& current, Inventory inv) {
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
				std::cout << "\n";
				current->printRoom();
				std::cout << "\n";
				return;
			} else {
				std::cout << "\n";
				current->printRoom();
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

/*void Study::input(bool& game, Room*& current, Room*& lookat) {
	char action;
	std::string item;
	std::cout << "Enter action: ";
	std::cin >> action;
	//std::cin.ignore(1, '\n');			// this skips the apaces until next number
	//std::cin >> item;
	if (action == 'n') {
		//lookat = link1;
		std::cout << "There is a drawer desk." << std::endl;
		std::cout << std::endl;
	} else if (action == 'e') {
		//lookat = link2;
		std::cout << "There is a wooden chest." << std::endl;
		std::cout << std::endl;
	} else if (action == 's') {
		//lookat = link3;
		std::cout << "There is a door to the kitchen." << std::endl;
		std::cout << std::endl;
	} else if (action == 'w') {
		//lookat = link4;
		std::cout << "There is a door to the piano room." << std::endl;
		std::cout << std::endl;
	} else if (action == 'm') {
		menu(game);
	} else {
		std::cout << "Invalid action.\n" << std::endl;
	}
}*/
