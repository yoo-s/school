#include <iostream>
#include <string>
#include <vector>
#include "room.hpp"
#include "item.hpp"
#include "piano.hpp"
#include "study.hpp"

Piano* piano = new Piano("Piano Room", "You are in the piano room.");
Study* study = new Study("Study Room", "You are in the study room.");
Room* C = new Room("Room C", "You are in room C.");
Room* D = new Room("Room D", "You are in room D.");
Room* spare = new Room("Spare room", "You are in the spare room.");
Room* current = piano;
Room* lookat;
Item* key = new Item("key", "It's a key.");
Item* ball = new Item("ball", "It's a yellow ball.");

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
/*
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

void takeItem(vector<Item>& inv, Item item) {
	inv.push_back(item);
}

void useItem(vector<Item>& inv, Item item) {
	for (int i = 0; i < inv.size(); i++) {
		if (inv[i].getName == "key") {
			std::cout << "You used " << inv[i].getName << "." << std::endl;
			inv.pop_back(item);
		}
	}
}
*/
int main() {
	bool game = true;
	piano->links(study, C, D, spare);
	study->links(piano, C, D, spare);
	C->links(piano, study, D, spare);
	D->links(piano, study, C, spare);
	spare->links(piano, study, C, D);
	//current = piano;
	std::vector<Item> inv;
	//std::string item;

	std::cout << "------Start Game------" << std::endl;
	std::cout << "You are somehow locked in a strange room. Explore the room, find items and solve puzzles to escape!" << std::endl;
	std::cout << "Enter 'm' for menu at any time to see directions on how to play.\n" << std::endl;
	current->printRoom();
	std::cout << std::endl;
	while (game) {
		current->input(game, current, lookat);
	}

	std::cout << "\n------End game------\n" << std::endl;

	return 0;

}
