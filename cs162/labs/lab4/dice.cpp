#ifndef DICE_CPP_
#define DICE_CPP_

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

class Dice {
	public:
		void set_sides() {
			sides = 6;
		}

		Dice (int s) {
			sides = s;
		}

		int roll(int sides);

	protected:
		int sides;

};

int Dice::roll(int sides) {
	srand(time(NULL));
	return (rand() % sides + 1);
}

#endif /* DICE_CPP_ */
