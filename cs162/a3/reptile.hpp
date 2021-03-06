#ifndef REPTILE_HPP_
#define REPTILE_HPP_

#include <iostream>
#include "char.hpp"

/*********************************************
 ** Class: Reptile People
 ** Description: derived subclass representing the reptile people character
 ** Pre-Conditions: none
 ********************************************/
class Reptile: public Character {
	public:
		Reptile();
		~Reptile();

		virtual int attack();
		virtual int defend();

};

#endif /* REPTILE_HPP_ */

