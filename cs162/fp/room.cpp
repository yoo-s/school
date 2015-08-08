#include <iostream>
#include <string>
#include "room.hpp"

Room::Room(std::string n, std::string i) {
	name = n;
	info = i;
}

void Room::links(Room* a, Room* b, Room* c, Room* d) {
	link1 = a;
	link2 = b;
	link3 = c;
	link4 = d;
}


