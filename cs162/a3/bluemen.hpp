#ifndef BLUEMEN_HPP_
#define BLUEMEN_HPP_

#include <iostream>
#include "char.hpp"

/*********************************************
 ** Class: Blue Men
 ** Description: derived subclass representing the blue men character
 ** Pre-Conditions: none
 ********************************************/
class Bluemen: public Character {
	public:
		Bluemen();
		~Bluemen();

		virtual int attack();
		virtual int defend();

};

#endif /* BLUEMEN_HPP_ */

