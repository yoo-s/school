#ifndef CHAR_HPP_
#define CHAR_HPP_

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

class Character {
	protected:
		//std::string chartype;
		//std::string charname;

	public:
		std::string charname;
		int armor;
		int strength;
		Character();
		virtual ~Character();

		/*std::string get_name() {
			return chartype;
		}*/

		virtual void set_name(std::string name);
		virtual int attack() = 0;
		virtual int defend() = 0;
		virtual void set_armor() = 0;
		virtual void set_strength() = 0;

};

#endif /* CHAR_HPP_ */
