#ifndef BARBARIAN_HPP_
#define BARBARIAN_HPP_

#include <iostream>
#include "char.hpp"

class Barbarian: public Character {
	public:
		Barbarian();
		~Barbarian();

		virtual int attack();
		virtual int defend();
		virtual void set_armor();
		virtual void set_strength();

};

#endif /* BARBARIAN_HPP_ */
