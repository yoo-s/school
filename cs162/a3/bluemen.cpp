#ifndef BLUEMEN_CPP_
#define BLUEMEN_CPP_

#include <iostream>
#include "char.cpp"

class Bluemen: public Character {
	public:
		Bluemen(std::string type)
		: Character(type) {};
		~Bluemen() {};

		virtual int attack() {
			int a = (rand() % 10 + 1);
			int b = (rand() % 10 + 1);
			return a+b;
		}

		virtual int defend() {
			int a = (rand() % 6 + 1);
			int b = (rand() % 6 + 1);
			int c = (rand() % 6 + 1);

			return a+b+c;
		}

		virtual void set_armor() {
			armor = 3;
		}

		virtual void set_strength() {
			strength = 12;
		}

};

#endif /* BLUEMEN_CPP_ */

