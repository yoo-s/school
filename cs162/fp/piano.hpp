#ifndef PIANO_HPP_
#define PIANO_HPP_

#include <iostream>
#include <string>
#include "room.hpp"

class Piano : public Room {
	public:

		Piano();

		void options();
		void go(bool& game, char action, Room*& current, Inventory inv);

};

#endif /* PIANO_HPP_ */
