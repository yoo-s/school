#ifndef SHADOW_CPP_
#define SHADOW_CPP_

#include <iostream>
#include "char.cpp"

class Shadow: public Character {
	public:
		Shadow(std::string type)
		: Character(type) {};
		~Shadow() {};

		virtual int attack() {
			int a = (rand() % 10 + 1);
			int b = (rand() % 10 + 1);
			return a+b;
		}

		virtual int defend() {
			int a = (rand() % 6 + 1);
			return a;
		}

		virtual void set_armor() {
			armor = 0;
		}

		virtual void set_strength() {
			strength = 12;
		}

};

#endif /* SHADOW_CPP_ */

