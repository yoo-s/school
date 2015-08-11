#include <iostream>
#include <string>
#include "study.hpp"
#include "inv.hpp"
#include "item.hpp"

Study::Study() : Room() {}

void Study::options() {

	std::cout << "***Study Room***\n" << std::endl;
	std::cout << "You are in the study room. You see a drawer desk nearby and a wooden chest in the corner.\n" << std::endl;
	
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "a) Open the drawers" << std::endl;
	std::cout << "b) Open the chest" << std::endl;
	std::cout << "\nOr you could go to the other rooms:" << std::endl;
	std::cout << "c) Go to Foyer" << std::endl;
	std::cout << "d) Go to Kitchen" << std::endl;
	std::cout << "e) Go to Spare Room" << std::endl;
	std::cout << "f) Go to Piano Room" << std::endl;
}

void Study::go(bool& game, char action, Room*& current, Inventory inv) {
	char open;
	std::string notes;
	int num;

	// open the drawers
	if (action == 'a') {
		std::cout << "You open the drawers and see a wooden key inside.\n";
		std::cout << "q) Pick up key\nw) Go back\n";
		std::cin >> open;
		if (open == 'q') {
			inv.woodenkey = true;
			std::cout << "You now have the wooden key." << std::endl;
			return;
		} else if (open == 'w') {
			std::cout << "You close the drawers." << std::endl;
			return;
		}
	// open the chest
	} else if (action == 'b') {
		if (inv.woodenkey = true) {
			std::cout << "You unlock the wooden chest and open it. You see a notepad inside that reads, '9+4*152'.\n";
			return;
		} else {
			std::cout << "The chest is locked." << std::endl;
			return;
		}
	// go to foyer
	} else if (action == 'c') {
		std::cout << "The door is locked. There's a four-letter combination lock.\n";
		std::cout << "Enter code: ";
		std::cin >> notes;
		if (notes == "woof") {
			std::cout << "The door unlocks and you go into the foyer.\n";
			current = getS();
			return;
		} else {
			std::cout << "The door remains locked." << std::endl;
			return;
		}
	// go to kitchen
	} else if (action == 'd') {
		std::cout << "The door is locked. There is a number combination lock.";
		std::cout << "Enter combination number: ";
		std::cin >> num;
		if (num = 617) {
			std::cout << "The door unlocks and you go into the kitchen.\n";
			current = getE();
			return;
		} else {
			std::cout << "The door remains locked." << std::endl;
			return;
		}
	// go to spare room
	} else if (action == 'e') {
		std::cout << "You go into the spare room.\n";
		current = getW();
		return;
	// go to piano room
	} else if (action == 'f') {
		std::cout << "You go into the piano room.\n";
		current = getN();
	// menu
	} else if (action == 'm') {
		menu(game);
	// inventory
	} else if (action == 'i') {
		inv.print();
	}
}

