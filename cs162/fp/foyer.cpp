#include <iostream>
#include <string>
#include "foyer.hpp"
#include "inv.hpp"
#include "item.hpp"

Foyer::Foyer() : Room() {}

void Foyer::options() {

	std::cout << "***Foyer***\n" << std::endl;
	std::cout << "You are in the foyer. You see a closet in a corner and a doggy door on the lower wall.\n" << std::endl;
	
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "a) Open the closet" << std::endl;
	std::cout << "b) Open the doggy door" << std::endl;
	std::cout << "\nOr you could go to the other rooms:" << std::endl;
	std::cout << "c) Go to Study Room" << std::endl;
	std::cout << "d) Go to Kitchen" << std::endl;
	std::cout << "e) Go to Spare Room" << std::endl;
	std::cout << "f) Go to Piano Room" << std::endl;
}

void Foyer::go(bool& game, char action, Room*& current, Inventory inv) {
	char open;
	std::string notes;
	int num;

	// open the closet
	if (action == 'a') {
		std::cout << "You open the closet and see a food bowl inside. Looks like it's for a dog.\n";
		std::cout << "q) Take food bowl\nw) Go back\n";
		std::cin >> open;
		if (open == 'q') {
			inv.bowl = true;
			std::cout << "You now have the dog's food bowl." << std::endl;
			return;
		} else if (open == 'w') {
			std::cout << "You close the closet." << std::endl;
			return;
		}
	// open the doggy door
	} else if (action == 'b') {
		std::cout << "You open the doggy door and see a dog with a golden key in its mouth. The dog looks awfully hungry...\n";
		std::cout << "q) Give dog food to the dog\nw) Go back\n";
		std::cin >> open;
		if (open == 'q') {
			if ((inv.dogfood = true) && (inv.bowl = true)) {
				std::cout << "You pour the dog food into the bowl and set it outside the doggy door. The dog drops the golden key and starts feasting on the food, wagging its tail." << std::endl;
				inv.goldkey = true;
				std::cout << "You take the golden key." << std::endl;
				return;
			} else if ((inv.dogfood = true) && (inv.bowl = false)) {
				std::cout << "You don't have a bowl to put the dog food in!" << std::endl;
				return;
			} else if ((inv.dogfood = false) && (inv.bowl = true)) {
				std::cout << "You don't have any dog food!" << std::endl;
				return;
			} else {
				std::cout << "You don't have any dog food!" << std::endl;
				return;
			}
		} else if (open == 'w') {
			std::cout << "You close the doggy door." << std::endl;
			return;
		}
	// go to study room
	} else if (action == 'c') {
		std::cout << "You go into the study room.\n";
		current = getE();
		return;
	// go to kitchen
	} else if (action == 'd') {
		std::cout << "The door is locked. There is a number combination lock.";
		std::cout << "Enter combination number: ";
		std::cin >> num;
		if (num = 617) {
			std::cout << "The door unlocks and you go into the kitchen.\n";
			current = getS();
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

