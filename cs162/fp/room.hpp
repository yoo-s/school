#ifndef ROOM_HPP_
#define ROOM_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "inv.hpp"
#include "item.hpp"

class Room {
	protected:
		Room* north;
		Room* east;
		Room* south;
		Room* west;

	public:

		// Constructors
		Room();

		virtual void links(Room* a, Room* b, Room* c, Room* d);
		virtual Room* getN();
		virtual Room* getE();
		virtual Room* getS();
		virtual Room* getW();

		virtual void options();
		virtual void go(bool& game, char action, Room*& current, Inventory& inv);

		virtual void menu(bool& game);

};

#endif /* ROOM_HPP_ */
