#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "room.hpp"
#include "inv.hpp"
#include "item.hpp"
#include "piano.hpp"
#include "study.hpp"
/*
Piano* piano = new Piano("Piano Room", "You are in the piano room.");
Study* study = new Study("Study Room", "You are in the study room.");
Room* C = new Room("Room C", "You are in room C.");
Room* D = new Room("Room D", "You are in room D.");
Room* spare = new Room("Spare room", "You are in the spare room.");
Room* current = piano;
Room* lookat;
*/

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

void gameLoop(Room*& current) {
		char action;

		//present user a set of choices for current room
		current->options();

		//get user's menu option
		std::cin >> action;

		//process
		current->go(action, current);
}

int main() {
	bool game = true;

	Piano* piano;
	Study* study;
	Piano* C;
	Study* D;
	Piano* spare;
	
	Item key("Wooden Key");
	Item ball("ball");
	Item* wkey = &key;
	Item* bb = &ball;
	
	Room* current = piano;

	piano->links(C, study, D, spare);
	//piano->setItem(key);
	//piano->setItem(ball);
	study->links(piano, C, D, spare);
	//C->links(piano, study, D, spare);
	//D->links(piano, study, C, spare);
	//spare->links(piano, study, C, D);
	std::vector<Item*> in;
	inv.addItem(in, wkey);
	inv.addItem(in, bb);
	inv.print(in);

	std::cout << "------Start Game------" << std::endl;
	std::cout << "You are somehow locked in a strange room. Explore the room, find items and solve puzzles to escape!" << std::endl;
	std::cout << "Enter 'm' for menu at any time to see directions on how to play.\n" << std::endl;
	current->printRoom();
	std::cout << std::endl;
	while (game) {
		gameLoop(current);
		//current->input(game, inv, current, lookat);
	}

	std::cout << "\n------End game------\n" << std::endl;

	return 0;

}
