#include <iostream>
#include <string>
#include "piano.hpp"
#include "inv.hpp"
#include "item.hpp"

Piano::Piano() : Room() {}

void Piano::options() {

	std::cout << "***Piano Room***\n" << std::endl;
	std::cout << "You are in the piano room. You see a lovely piano, and a picture frame hanging on the wall." << std::endl;
	
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "a) Play the piano" << std::endl;
	std::cout << "\nOr you could go to the other rooms:" << std::endl;
	std::cout << "b) Go to Study Room" << std::endl;
	std::cout << "c) Go to Foyer" << std::endl;
	std::cout << "d) Go to Kitchen" << std::endl;
	std::cout << "e) Go to Spare Room" << std::endl;
}

void Piano::go(bool& game, char action, Room*& current, Inventory inv) {
	char open;
	std::string notes;
	int num;

	// play the piano
	if (action == 'a') {
		std::cout << "You play the piano.\n";
		std::cout << "Play some music notes (enter a string):";
		std::cin >> notes;
		if (notes == "bcage") {
			std::cout << "You play the notes 'bcage'.\nThe picture frame slides open to reveal a door with a golden keyhole." << std::endl;
			std::cout << "\no) Open door?" << std::endl;
			std::cout << "Enter action: ";
			std::cin >> open;
			if (inv.goldkey = true) {
				std::cout << "You open the hidden door with the golden key and escape!\nCONGRATULATIONS!" << std::endl;
				game = false;
			} else {
				std::cout << "The door is locked." << std::endl;
				return;
			}
		} else {
			std::cout << "You play the notes '" << notes << "'."<< std::endl;
			return;
		}
	// go to study room
	} else if (action == 'b') {
		std::cout << "You go to the study room.\n";
		current = getN();
		return;
	// go to foyer
	} else if (action == 'c') {
		std::cout << "The door is locked. There's a four-letter combination lock.\n";
		std::cout << "Enter code: ";
		std::cin >> notes;
		if (notes == "woof") {
			std::cout << "The door unlocks and you go into the foyer.\n";
			current = getE();
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
			current = getS();
			return;
		} else {
			std::cout << "The door remains locked." << std::endl;
			return;
		}
	} else if (action == 'e') {
		std::cout << "You go into the spare room.\n";
		current = getW();
		return;
	} else if (action == 'm') {
		menu(game);
	} else if (action == 'i') {
		inv.print();
	}
}

