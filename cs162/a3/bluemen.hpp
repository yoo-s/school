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
		virtual void set_armor();
		virtual void set_strength();

};

#endif /* BLUEMEN_HPP_ */

