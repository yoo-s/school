#ifndef SECRET_HPP_
#define SECRET_HPP_

#include <iostream>
#include <string>
#include "room.hpp"

class Secret : public Room {
	public:

		Secret();

		void options();
		void go(bool& game, char action, Room*& current, Inventory inv);

};

#endif /* SECRET_HPP_ */
