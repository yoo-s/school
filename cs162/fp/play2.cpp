#include <iostream>
#include <string>
#include "room.hpp"

Room A("Living Room", "You are in the Living Room.");
Room B("Study", "You are in the Study.");
Room C("Kitchen", "You are in the Kitchen.");
Room D("Bedroom", "You are in the Bedroom.");
Room spare("Spare Room", "You are in the Spare Room.");
Room* current;

void menu(bool& game) {
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

void input(bool& game) {
	char action;
	std::cout << "Enter action: ";
	std::cin >> action;

	if (action == 'n') {
		current = &B;
		std::cout << std::endl;
	} else if (action == 'e') {
		current = &C;
		std::cout << std::endl;
	} else if (action == 's') {
		current = &D;
		std::cout << std::endl;
	} else if (action == 'w') {
		current = &spare;
		std::cout << std::endl;
	} else if (action == 'm') {
		menu(game);
	} else {
		std::cout << "Invalid action.\n" << std::endl;
	}
}

int main() {
	bool game = true;
	A.links(&B, &D, &spare, &box);
	B.links(&A, &C, &drawer, &chest);
	C.links(&B, &D, &fridge, &dogbed);
	D.links(&A, &C, &base, &doggy);
	spare.links(&A, &safe, &drawer, &birdcage);
	current = &A;

	std::cout << "------Start Game------" << std::endl;
	std::cout << "You are somehow locked in a strange room. Explore the room, find items and solve puzzles to escape!" << std::endl;
	std::cout << "Enter 'm' for menu at any time to see directions on how to play.\n" << std::endl;

	while (game) {
		current->printRoom();
		std::cout << std::endl;
		input(game);
	}

	std::cout << "\n------End game------\n" << std::endl;

	return 0;

}
