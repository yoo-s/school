#ifndef BLUEMEN_HPP_
#define BLUEMEN_HPP_

#include <iostream>
#include "char.hpp"

class Bluemen: public Character {
	public:
		Bluemen();
		~Bluemen();

		virtual int attack();
		virtual int defend();

};

#endif /* BLUEMEN_HPP_ */

