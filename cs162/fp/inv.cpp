#include <iostream>
#include <string>
#include "item.hpp"
#include "inv.hpp"

Inventory::Inventory() :
	woodenkey(false),
	velvetkey(false),
	dogfood(false),
	bowl(false),
	flower(false),
	goldkey(false) {}

/*void Inventory::setItem(Item* item) {
	inv.push_back(item);
}*/

void Inventory::print() {
	std::cout << "\nInventory:\n";
	if (woodenkey = true) {
		std::cout << "Wooden Key" << std::endl;
	}
	if (velvetkey = true) {
		std::cout << "Velvet Key" << std::endl;
	}
	if (dogfood = true) {
		std::cout << "Dog Food" << std::endl;
	}
	if (bowl = true) {
		std::cout << "Food Bowl" << std::endl;
	}
	if (flower = true) {
		std::cout << "Glass Flower" << std::endl;
	}
	if (goldkey = true) {
		std::cout << "Golden Key" << std::endl;
	}
}

void Inventory::addItem(std::vector<Item*>& in, Item* item) {
	if (item->getName() == "Wooden Key") {
		woodenkey = true;
	} else if (item->getName() == "Velvet Key") {
		velvetkey = true;
	} else if (item->getName() == "Dog Food") {
		dogfood = true;
	} else if (item->getName() == "Food Bowl") {
		bowl = true;
	} else if (item->getName() == "Glass Flower") {
		flower = true;
	} else if (item->getName() == "Gold Key") {
		goldkey = true;
	}
	in.push_back(item);
}

void Inventory::dropItem(std::vector<Item*>& in, Item* item) {
	in.erase(std::remove(in.begin(), in.end(), item), in.end());
}

