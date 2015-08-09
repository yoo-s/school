#include <iostream>
#include <string>
#include "room.hpp"

Room::Room(std::string n, std::string i) {
	name = n;
	info = i;
	north = NULL;
	east = NULL;
	south = NULL;
	west = NULL;
}

void Room::links(Room* a, Room* b, Room* c, Room* d) {
	this->north = a;
	this->east = b;
	this->south = c;
	this->west = d;
}

Room* Room::getN() {
	return north;
}

Room* Room::getE() {
	return east;
}

Room* Room::getS() {
	return south;
}

Room* Room::getW() {
	return west;
}

void Room::menu(bool& game) {
	char action;

	std::cout << "You are somehow locked in a strange room. Explore the room, find items and solve puzzles to escape!" << std::endl;
	std::cout << "Enter any other rooms by moving in the room's direction with the commands 'n', 's', 'e', or 'w' (w/o quotes).\n" << std::endl;
	std::cout << "Quit game (q) or back to playing game (any other char)? ";
	std::cin >> action;
	if (action == 'q') {
		game = false;
	} else {
		game = true;
	}
	std::cout << std::endl;
}

void Room::input(bool& game, Room*& current, Room*& lookat) {
	char action;
	std::string item;
	std::cout << "Enter action: ";
	std::cin >> action;
	//std::cin.ignore(1, '\n');			// this skips the apaces until next number
	//std::cin >> item;

	if (action == 'n') {
		//lookat = link1;
		std::cout << std::endl;
	} else if (action == 'e') {
		//lookat = link2;
		std::cout << std::endl;
	} else if (action == 's') {
		//lookat = link3;
		std::cout << std::endl;
	} else if (action == 'w') {
		//lookat = link4;
		std::cout << std::endl;
	} else if (action == 'm') {
		menu(game);
	} else {
		std::cout << "Invalid action.\n" << std::endl;
	}
}
