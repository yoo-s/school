#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "room.hpp"
#include "inv.hpp"
#include "item.hpp"
#include "piano.hpp"
#include "study.hpp"

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

void gameLoop(Room*& current, Inventory inv) {
		char action;

		//present user a set of choices for current room
		current->options();

		//get user's menu option
		std::cin >> action;

		//process
		current->go(action, current, inv);
}

int main() {
	bool game = true;

	Inventory inv;
	Piano* piano = new Piano();
	Study* study = new Study();
	Kitchen* kitchen = new Kitchen();
	Foyer* foyer = new Foyer();
	Secret* secret = new Secret();
	
	Item* woodkey = new Item("Wooden Key");
	Item* velvkey = new Item("Velvet Key");
	Item* dfood = new Item("Dog Food");
	Item* dbowl = new Item("Food Bowl");
	Item* flow = new Item("Glass Flower");
	Item* gold = new Item("Gold Key");
	
	Room* current = piano;

	piano->links(study, kitchen foyer, secret);
	study->links(piano, kitchen, foyer, secret);
	kitchen->links(piano, study, foyer, secret);
	foyer->links(piano, study, kitchen, secret);
	secret->links(piano, study, kitchen, foyer);
	
	std::vector<Item*> in;

	inv.addItem(in, key);
	inv.addItem(in, ball);
	inv.print(in);
	std::cout << "------Start Game------" << std::endl;
	std::cout << "You are somehow locked in a strange room. Explore the room, find items and solve puzzles to escape!" << std::endl;
	std::cout << "Enter 'm' for menu at any time to see directions on how to play.\n" << std::endl;
	current->printRoom();
	std::cout << std::endl;
	while (game) {
		gameLoop(current, inv);
	}

	std::cout << "\n------End game------\n" << std::endl;

	return 0;

}
