#ifndef FOYER_HPP_
#define FOYER_HPP_

#include <iostream>
#include <string>
#include "room.hpp"

class Foyer : public Room {
	public:

		Foyer();

		void options();
		void go(char action, Room*& current, Inventory inv);

};

#endif /* FOYER_HPP_ */
