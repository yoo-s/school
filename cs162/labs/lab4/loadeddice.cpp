#ifndef LOADEDDICE_CPP_
#define LOADEDDICE_CPP_

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "dice.cpp"

class loadedDice: public Dice {
	public:
		loadedDice(int s);

		void roll(int sides);

};

loadedDice::loadedDice(int s): Dice(s) {
	sides = s;
}

void loadedDice::roll(int sides) {
			srand(time(NULL));
			int result = rand() & sides + 1;

			if (result != sides) {
				int chance = rand() % 20 + 1;
				if (chance = 1) {
					result += 1;
				} else {
					result = result;
				}
			} else {
				result = result;
			}
}

#endif /* LOADEDDICE_CPP_ */
