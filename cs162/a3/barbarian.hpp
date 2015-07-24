#ifndef BARBARIAN_HPP_
#define BARBARIAN_HPP_

#include <iostream>
#include "char.hpp"

/*********************************************
 ** Class: Barbarian
 ** Description: derived subclass representing the barbarian character
 ** Pre-Conditions: none
 ********************************************/
class Barbarian: public Character {
	public:
		Barbarian();
		~Barbarian();

		virtual int attack();
		virtual int defend();

};

#endif /* BARBARIAN_HPP_ */
