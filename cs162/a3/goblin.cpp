#ifndef GOBLIN_CPP_
#define GOBLIN_CPP_

#include <iostream>
#include "char.cpp"

class Goblin: public Character {
	public:
		Goblin(std::string type)
			: Character(type) {};
		~Goblin() {};

		virtual int attack() {
			int a = (rand() % 6 + 1);
			int b = (rand() % 6 + 1);
			return a+b;
		}

		virtual int defend() {
			int a = (rand() % 6 + 1);
			return a;
		}

		virtual void set_armor() {
			armor = 3;
		}

		virtual void set_strength() {
			strength = 8;
		}

};

#endif /* GOBLIN_CPP_ */
