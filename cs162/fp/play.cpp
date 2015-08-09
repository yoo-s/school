#include <iostream>
#include <string>
#include <vector>
#include "room.hpp"
#include "item.hpp"
#include "piano.hpp"

Room A("Room A", "You are in room A.");
Room B("Room B", "You are in room B.");
Room C("Room C", "You are in room C.");
Room D("Room D", "You are in room D.");
Room spare("Spare room", "You are in the spare room.");
Room* current;
Room* lookat;
Item key("key", "It's a key.");
Item ball("ball", "It's a yellow ball.");

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
	std::string item;
	std::cout << "Enter action: ";
	std::cin >> action;
	//std::cin.ignore(1, '\n');			// this skips the apaces until next number
	//std::cin >> item;

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
/*
void takeItem(vector<Item>& inv, Item item) {
	inv.push_back(item);
}

void useItem(vector<Item>& inv, std::string item) {
	for (int i = 0; i < inv.size(); i++) {
		if (inv[i].getName == item) {
			std::cout << "You used " << inv[i].getName << "." << std::endl;
			inv.pop_back(item);
		}
	}
}
*/
int main() {
	bool game = true;
	A.links(&B, &C, &D, &spare);
	B.links(&A, &C, &D, &spare);
	C.links(&A, &B, &D, &spare);
	D.links(&A, &B, &C, &spare);
	spare.links(&A, &B, &C, &D);
	current = &A;
	std::vector<Item> inv;
	//std::string item;

	std::cout << "------Start Game------" << std::endl;
	std::cout << "You are somehow locked in a strange room. Explore the room, find items and solve puzzles to escape!" << std::endl;
	std::cout << "Enter 'm' for menu at any time to see directions on how to play.\n" << std::endl;

	while (game) {
		current->printRoom();
		std::cout << std::endl;
		current->input(game, lookat);
	}

	std::cout << "\n------End game------\n" << std::endl;

	return 0;

}
