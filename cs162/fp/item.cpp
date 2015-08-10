#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "item.hpp"

Item::Item(std::string n, std::string i) {
	name = n;
	info = i;
}

/*void Item::addItem(std::vector<Item*>& inv, Item* item) {
	inv.push_back(item);
}

void Item::dropItem(std::vector<Item*>& inv, Item* item) {
	inv.erase(std::remove(inv.begin(), inv.end(), item), inv.end());
}*/


