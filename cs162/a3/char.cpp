#ifndef CHAR_CPP_
#define CHAR_CPP_

#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

class Character {
	protected:
		std::string chartype;

	public:
		int armor;
		int strength;
		Character(std::string type);
		virtual ~Character();

		std::string get_name() {
			return chartype;
		}

		virtual int attack() = 0;
		virtual int defend() = 0;
		virtual void set_armor() = 0;
		virtual void set_strength() = 0;

};

#endif /* CHAR_CPP_ */
