#ifndef GOBLIN_HPP_
#define GOBLIN_HPP_

#include <iostream>
#include "char.hpp"

class Goblin: public Character {
	public:
		Goblin();
		~Goblin();

		virtual int attack();
		virtual int defend();

};

#endif /* GOBLIN_HPP_ */
