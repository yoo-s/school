#include <iostream>
#include <stdlib.h>

class player {
public:
	int vict;
	int play();
	player() : vict(0) {}
};

int player::play() {
	return rand() % 52 + 1;
}

int main() {
	int rounds;

	player p1;
	player p2;

	std::cout << "How many rounds will you play? ";
	std::cin >> rounds;
	std::cout << std::endl;

	for (int i = 0; i < rounds; i++) {
		std::cout << "Round " << i+1 << "-----" << std::endl;
		std::cout << "P1: " << p1.play() << std::endl;
		std::cout << "P2: " << p2.play() << std::endl;
		if (p1.play() > p2.play()) {
			std::cout << "Player 1 wins!" << std::endl;
			p1.vict++;
		} else if (p1.play() < p2.play()) {
			std::cout << "Player 2 wins!" << std::endl;
			p2.vict++;
		}
		else if (p1.play() == p2.play()) {
			std::cout << "It's a tie! No one wins." << std::endl;
		}
	}

	std::cout << "Player 1 score: " << p1.vict << std::endl;
	std::cout << "Player 2 score: " << p2.vict << std::endl;
	if (p1.vict > p2.vict) {
		std::cout << "Player 1 wins!" << std::endl;
	}
	else if (p1.vict < p2.vict) {
		std::cout << "Player 2 wins!" << std::endl;
	}
	else {
		std::cout << "It's a tie!" << std::endl;
	}

	return 0;
}
