#ifndef STUDY_HPP_
#define STUDY_HPP_

#include <iostream>
#include <string>
#include "room.hpp"

class Study : public Room {
	public:

		Study();

		void options();
		void go(char action, Room*& current, Inventory inv);

};

#endif /* STUDY_HPP_ */
