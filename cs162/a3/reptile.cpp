#ifndef REPTILE_CPP_
#define REPTILE_CPP_

#include <iostream>
#include "char.cpp"

class Reptile: public Character {
	public:
		Reptile(std::string type)
			: Character(type) {};
		~Reptile() {};

		virtual int attack() {
			int a = (rand() % 6 + 1);
			int b = (rand() % 6 + 1);
			int c = (rand() % 6 + 1);

			return a+b+c;
		}

		virtual int defend() {
			int a = (rand() % 6 + 1);
			return a;
		}

		virtual void set_armor() {
			armor = 7;
		}

		virtual void set_strength() {
			strength = 18;
		}

};

#endif /* REPTILE_CPP_ */

