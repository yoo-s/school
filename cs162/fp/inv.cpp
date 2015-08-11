#include <iostream>
#include <string>
#include "item.hpp"
#include "inv.hpp"

Inventory::Inventory() {
	woodenkey = false;
	velvetkey = false;
	dogfood = false;
	bowl = false;
	flower = false;
	goldkey = false;
}

void Inventory::print() {
	std::cout << "\nInventory:\n";
	if (woodenkey = true) {
		std::cout << "Wooden Key" << std::endl;
	} else {
		std::cout << "---" << std::endl;
	}
	if (velvetkey = true) {
		std::cout << "Velvet Key" << std::endl;
	} else {
		std::cout << "---" << std::endl;
	}
	if (dogfood = true) {
		std::cout << "Dog Food" << std::endl;
	} else {
		std::cout << "---" << std::endl;
	}
	if (bowl = true) {
		std::cout << "Food Bowl" << std::endl;
	} else {
		std::cout << "---" << std::endl;
	}
	if (flower = true) {
		std::cout << "Glass Flower" << std::endl;
	} else {
		std::cout << "---" << std::endl;
	}
	if (goldkey = true) {
		std::cout << "Golden Key" << std::endl;
	} else {
		std::cout << "---" << std::endl;
	}
}

