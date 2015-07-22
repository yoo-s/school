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
		int armor;
		int strength;

		Character(std::string type)
			: chartype(type) {
		}

	public:
		std::string get_name() {
			return chartype;
		}

		virtual int attack() = 0;
		virtual int defend() = 0;
		virtual void set_armor() = 0;
		virtual void set_strength() = 0;

		virtual void round(Object& a, Object2& b) {			// how to do this??
			std::cout << a.get_name() << " and " << b.get_name() << " fight!" << std::endl;
			std::cout << "Fighting...\n" << std::endl;

			while (a.strength() > 0 || b.strength() > 0) {
				int atk1 = a.attack();
				int dfs1 = a.defend();
				int atk2 = b.attack();
				int dfs2 = b.defend();
				int dmg1 = atk2 - dfs1;
				int dmg2 = atk1 - dfs2;
				int app_dmg1 = dmg1 - a.armor();
				int app_dmg2 = dmg2 - b.armor();
				
				a.strength() -= app_dmg1;
				b.strength() -= app_dmg2;

				if (a.strength() > b.strength()) {
					winner = a.get_name();
				} else {
					winner = b.get_name();
				}
			}

			std::cout << "The winner is: " << winner << "!" << std::endl;
		}


};

#endif /* CHAR_CPP_ */
