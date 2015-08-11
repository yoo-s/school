#ifndef KITCHEN_HPP_
#define KITCHEN_HPP_

#include <iostream>
#include <string>
#include "room.hpp"

class Kitchen : public Room {
	public:

		Kitchen();

		void options();
		void go(char action, Room*& current, Inventory inv);

};

#endif /* KITCHEN_HPP_ */
