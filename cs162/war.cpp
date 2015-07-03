/*********************************************
 ** Program: war.cpp
 ** Author: Soo-Min Yoo
 ** Date: 07/02/15
 ** Description: program that automatically plays a simplified version of
 ** the card game War.
 ** Input: none
 ** Output: return 0
 ********************************************/

#include <iostream>
#include <stdlib.h>
#include <time.h>

/*********************************************
 ** Class: player
 ** Description: player class with a victory counter and member function play
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 ********************************************/

class player {
public:
	int vict;
	int play();
	player() : vict(0) {}
};
/*********************************************
 ** Member function: play
 ** Description: returns a random number between 1 and 52
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 ********************************************/

int player::play() {
	return rand() % 52 + 1;
}
/*********************************************
 ** Function: main
 ** Description: plays through input number of rounds of the card game War,
 ** displaying their victories for each round, their final scores, and the
 ** final winner.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: return 0
 ********************************************/

int main() {
	srand(time(NULL));
	int rounds;

	player p1;
	player p2;

	std::cout << "How many rounds will you play? ";
	std::cin >> rounds;
	std::cout << std::endl;

	for (int i = 0; i < rounds; i++) {
		std::cout << "Round " << i+1 << "-----" << std::endl;
		int p1num = p1.play();
		int p2num = p2.play();
		std::cout << "P1: " << p1num << std::endl;
		std::cout << "P2: " << p2num << std::endl;
		if (p1num > p2num) {
			std::cout << "Player 1 wins!" << std::endl;
			p1.vict++;
		} else if (p1num < p2num) {
			std::cout << "Player 2 wins!" << std::endl;
			p2.vict++;
		}
		else if (p1num == p2num) {
			std::cout << "It's a tie! No one wins." << std::endl;
		}
	}

	std::cout << "\nResults -----------" << std::endl;
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
