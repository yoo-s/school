#include <iostream>
#include <string>
#include "room.hpp"

Room A("Room A", "You are in room A.");
Room B("Room B", "You are in room B.");
Room C("Room C", "You are in room C.");
Room D("Room D", "You are in room D.");
Room spare("Spare room", "You are in the spare room.");
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
		std::cout << "Invalid action." << std::endl;
	}
}

int main() {
	bool game = true;
	A.links(&B, &C, &D, &spare);
	B.links(&A, &C, &D, &spare);
	C.links(&A, &B, &D, &spare);
	D.links(&A, &B, &C, &spare);
	spare.links(&A, &B, &C, &D);
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
