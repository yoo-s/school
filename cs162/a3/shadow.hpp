#ifndef SHADOW_HPP_
#define SHADOW_HPP_

#include <iostream>
#include "char.hpp"

class Shadow: public Character {
	public:
		Shadow();
		~Shadow();

		virtual int attack();
		virtual int defend();

};

#endif /* SHADOW_HPP_ */

