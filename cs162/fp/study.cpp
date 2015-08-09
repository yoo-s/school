#include <iostream>
#include <string>
#include "study.hpp"

Study::Study(std::string n, std::string i) :
		Room(n, i) {
	name = n;
	info = i;
}

void Study::input(bool& game, Room*& current, Room*& lookat) {
	char action;
	std::string item;
	std::cout << "Enter action: ";
	std::cin >> action;
	//std::cin.ignore(1, '\n');			// this skips the apaces until next number
	//std::cin >> item;
	if (action == 'n') {
		lookat = link1;
		std::cout << "There is a drawer desk." << std::endl;
		std::cout << std::endl;
	} else if (action == 'e') {
		lookat = link2;
		std::cout << "There is a wooden chest." << std::endl;
		std::cout << std::endl;
	} else if (action == 's') {
		lookat = link3;
		std::cout << "There is a door to the kitchen." << std::endl;
		std::cout << std::endl;
	} else if (action == 'w') {
		lookat = link4;
		std::cout << "There is a door to the piano room." << std::endl;
		std::cout << std::endl;
	} else if (action == 'm') {
		menu(game);
	} else {
		std::cout << "Invalid action.\n" << std::endl;
	}
}
