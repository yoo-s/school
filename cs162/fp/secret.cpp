#include <iostream>
#include <string>
#include "secret.hpp"
#include "inv.hpp"
#include "item.hpp"

Secret::Secret() : Room() {}

void Secret::options() {

	std::cout << "***Spare Room***\n" << std::endl;
	std::cout << "You are in the spare room. There's not much here - only a single, small box of red velvet sits in the center of the room." << std::endl;
	
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "a) Open the velvet box" << std::endl;
	std::cout << "\nOr you could go to the other rooms:" << std::endl;
	std::cout << "b) Go to Foyer" << std::endl;
	std::cout << "c) Go to Kitchen" << std::endl;
	std::cout << "d) Go to Study Room" << std::endl;
	std::cout << "e) Go to Piano Room" << std::endl;
}

void Secret::go(bool& game, char action, Room*& current, Inventory inv) {
	char open;
	std::string notes;
	int num;

	// open the velvet box
	if (action == 'a') {
		if (inv.velvetkey = true) {
			std::cout << "You unlock the velvet box with the velvet key and peer inside to see... 'woof' elegantly etched on the bottom of the box." << std::endl;
			return;
		} else {
			std::cout << "The box is locked." << std::endl;
			return;
		}
	// go to foyer
	} else if (action == 'b') {
		std::cout << "The door is locked. There's a four-letter combination lock.\n";
		std::cout << "Enter code: ";
		std::cin >> notes;
		if (notes == "woof") {
			std::cout << "The door unlocks and you go into the foyer.\n";
			current = getW();
			return;
		} else {
			std::cout << "The door remains locked." << std::endl;
			return;
		}
	// go to kitchen
	} else if (action == 'c') {
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
	// go to study room
	} else if (action == 'd') {
		std::cout << "You go into the study room.\n";
		current = getE();
		return;
	// go to piano room
	} else if (action == 'e') {
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

