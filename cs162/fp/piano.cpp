#include <iostream>
#include <string>
#include "piano.hpp"
#include "item.hpp"

/*Piano::Piano(std::string n, std::string i) :
		Room(n, i) {
	name = n;
	info = i;
}*/

Piano::Piano() : Room() {}

void Piano::options() {
	std::cout << "***Piano Room***\n" << std::endl;
	std::cout << "You are in the piano room." << std::endl;
	
	std::cout << "Where would you like to go?" << std::endl;
	std::cout << "n) North" << std::endl;
	std::cout << "e) East" << std::endl;
	std::cout << "s) South" << std::endl;
	std::cout << "w) West" << std::endl;
}

void Piano::go(char action, Room*& current) {
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
				current->printRoom();
				std::cout << "\n";
				return;
			}
		}
	} else if (action == 's') {
		std::cout << "You're at the door to the foyer.\n";
	} else if (action == 'w') {
		std::cout << "You see a large picture frame hung on the wall.\n";
	}
}

/*void Piano::input(bool& game, std::vector<Item*>& inv, Room*& current, Room*& lookat) {
	char action;
	std::string item;
	std::cout << "Enter action: ";
	std::cin >> action;
	//std::cin.ignore(1, '\n');			// this skips the apaces until next number
	//std::cin >> item;
	if (action == 'n') {
		//lookat = link1;
		std::cout << "There is a piano." << std::endl;
		std::cout << std::endl;
	} else if (action == 'e') {
		//lookat = link2;
		std::cout << "There is a door to the study room.\n" << std::endl;
		std::cout << "a) Open door\nb) Back" << std::endl;
		std::cout << std::endl;
		std::cout << "Enter action: ";
		std::cin >> action;
		if (action == 'a') {
			if (current->isHere(inv, "key")) {
				std::cout << "You unlock the door and go in.\n";
				current->dropItem(key);
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
	} else if (action == 's') {
		//lookat = link3;
		std::cout << "There is a door to the foyer." << std::endl;
		std::cout << std::endl;
	} else if (action == 'w') {
		//lookat = link4;
		std::cout << "There is a picture frame." << std::endl;
		std::cout << std::endl;
	} else if (action == 'm') {
		menu(game);
	} else {
		std::cout << "Invalid action.\n" << std::endl;
	}
}*/
