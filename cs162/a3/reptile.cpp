#include <iostream>

class Reptile: public Character {
	public:
		Reptile(std::string type)
			: Character(type) {
		}

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

		virtual int armor() {
			return 7;
		}

		virtual int strength() {
			return 18;
		}

};
