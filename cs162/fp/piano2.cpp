#include <iostream>
#include <string>
#include <vector>
#include "piano.hpp"

Piano::Piano(std::string n, std::string i) :
		Room(n, i) {
	name = n;
	info = i;
}

void Piano::input(bool& game, Room*& current, Room*& lookat) {
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
		std::cout << "There is a door to the study room." << std::endl;
		std::cout << "a) Open door\nb) Go back" << std::endl;
		std::cout << std::endl;
		std::cout << "Enter action: ";
		std::cin >> action;
		if (action == 'a') {
			current = north;
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
	} else if (action == 's') {
		//lookat = link3;
		std::cout << "There is a door to the foyer." << std::endl;
		std::cout << std::endl;
	} else if (action == 'w') {
		//lookat = link4;
		std::cout << "There is a picture frame. You notice a key taped on the frame's corner." << std::endl;
		std::cout << "a) Take key\nb) Go back" << std::endl;
		std::cout << std::endl;
		std::cout << "Enter action: ";
		std::cin >> action;
		if (action == 'a' && current->isHere("key")) {
			current->popItem("key");
			current->takeItem(inv, "key");
			std::cout << "You took the key.\n";
			return;
		} else {
			std::cout << "\n";
			current->printRoom();
			std::cout << "\n";
			return;
		}
	} else if (action == 'm') {
		menu(game);
	} else if (action == 'i') {
		inventory(inv);
	} else {
		std::cout << "Invalid action.\n" << std::endl;
	}
}
