#include <iostream>
#include <string>
#include "item.hpp"

Inventory::Inventory() :
	woodenkey(false),
	velvetkey(false),
	dogfood(false),
	bowl(false),
	glassflower(false),
	goldkey(false) {}

/*void Inventory::setItem(Item* item) {
	inv.push_back(item);
}*/

void Inventory::print(std::vector<Item*> in) {
	std::cout << "\nInventory:\n";
	for (int i = 0; i < in.size(); i++) {
		std::cout << in[i]->getName() << std::endl;
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

