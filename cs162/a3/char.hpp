#ifndef CHAR_HPP_
#define CHAR_HPP_

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

class Character {
	public:
		std::string charname;
		int armor;
		int strength;
		Character();
		virtual ~Character();

		virtual void set_name(std::string name);
		virtual int attack() = 0;
		virtual int defend() = 0;

};

#endif /* CHAR_HPP_ */
