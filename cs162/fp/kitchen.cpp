#include <iostream>
#include <string>
#include "kitchen.hpp"
#include "inv.hpp"
#include "item.hpp"

Kitchen::Kitchen() : Room() {}

void Kitchen::options() {

	std::cout << "***Kitchen***\n" << std::endl;
	std::cout << "You are in the kitchen. There is a fridge and a cabinet.\n" << std::endl;
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "a) Open the fridge" << std::endl;
	std::cout << "b) Open the cabinet" << std::endl;
	std::cout << "\nOr you could go to the other rooms:" << std::endl;
	std::cout << "c) Go to Foyer" << std::endl;
	std::cout << "d) Go to the Study Room" << std::endl;
	std::cout << "e) Go to Spare Room" << std::endl;
	std::cout << "f) Go to Piano Room" << std::endl;
}

void Kitchen::go(bool& game, char action, Room*& current, Inventory inv) {
	char open;
	std::string notes;
	int num;

	// open the fridge
	if (action == 'a') {
		std::cout << "There are alphabet magnets stuck on the fridge spelling 'bcage'. Interesting. You open the fridge and see a can of dog food inside.\n";
		std::cout << "q) Take dog food\nw) Go back\n";
		std::cin >> open;
		if (open == 'q') {
			inv.dogfood = true;
			std::cout << "You now have the dog food." << std::endl;
			return;
		} else if (open == 'w') {
			std::cout << "You close the fridge." << std::endl;
			return;
		}
	// open the cabinet
	} else if (action == 'b') {
		std::cout << "You open the cabinet and see a velvet key inside.\n";
		std::cout << "q) Take velvet key\nw) Go back\n";
		std::cin >> open;
		if (open == 'q') {
		inv.velvetkey = true;
		std::cout << "You now have the velvet key." << std::endl;
		return;
		} else if (open == 'w') {
			std::cout << "You close the cabinet." << std::endl;
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
	// go to study room
	} else if (action == 'd') {
		std::cout << "You go into the study room.";
		current = getE();
			return;
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

