#include <iostream>
#include <string>
#include "piano.hpp"

Piano::Piano(std::string n, std::string i) :
		Room(n, i) {
	name = n;
	info = i;
}

void Piano::input(bool& game, Room*& lookat) {
	char action;
	std::string item;
	std::cout << "Enter action: ";
	std::cin >> action;
	//std::cin.ignore(1, '\n');			// this skips the apaces until next number
	//std::cin >> item;
	if (action == 'n') {
		lookat = link1;
		std::cout << "There is a piano." << std::endl;
		std::cout << std::endl;
	} else if (action == 'e') {
		lookat = link2;
		std::cout << "There is a door." << std::endl;
		std::cout << std::endl;
	} else if (action == 's') {
		lookat = link3;
		std::cout << "There is a door." << std::endl;
		std::cout << std::endl;
	} else if (action == 'w') {
		lookat = link4;
		std::cout << "There is a picture frame." << std::endl;
		std::cout << std::endl;
	} else if (action == 'm') {
		menu(game);
	} else {
		std::cout << "Invalid action.\n" << std::endl;
	}
}
