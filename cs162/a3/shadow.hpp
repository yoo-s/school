#ifndef SHADOW_HPP_
#define SHADOW_HPP_

#include <iostream>
#include "char.hpp"

/*********************************************
 ** Class: Shadow
 ** Description: derived subclass representing the shadow character
 ** Pre-Conditions: none
 ********************************************/
class Shadow: public Character {
	public:
		Shadow();
		~Shadow();

		virtual int attack();
		virtual int defend();

};

#endif /* SHADOW_HPP_ */

