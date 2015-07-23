#ifndef BARBARIAN_HPP_
#define BARBARIAN_HPP_

#include <iostream>
#include "char.hpp"

class Barbarian: public Character {
	public:
		Barbarian(std::string type)
			: Character(type) {};
		~Barbarian() {};

		virtual int attack() {
			int a = (rand() % 6 + 1);
			int b = (rand() % 6 + 1);
			return a+b;
		}

		virtual int defend() {
			int a = (rand() % 6 + 1);
			int b = (rand() % 6 + 1);
			return a+b;
		}

		virtual void set_armor() {
			armor = 0;
		}

		virtual void set_strength() {
			strength = 12;
		}

};

#endif /* BARBARIAN_HPP_ */
