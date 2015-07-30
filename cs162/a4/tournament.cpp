#include <iostream>
#include <stack>
#include <queue>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "lineup.hpp"
#include "losers.hpp"

void round(Lineup &line1, Lineup &line2, Losers &pile) {
	int draw1;
	int draw2;

	char p1 = line1.getFront();
	line1.removeFront(p1);
	char p2 = line2.getFront();
	line2.removeFront(p2);

	std::cout << "Round:" << std::endl;
	draw1 = (rand() % 10 + 1);
	std::cout << "Roll 1: " << draw1 << std::endl;
	draw2 = (rand() % 10 + 1);
	std::cout << "Roll 2: " << draw2 << std::endl;

	if (draw1 > draw2) {
		std::cout << "Player 1 wins!" << std::endl;
		line1.addBack(p1);
		pile.push(p2);
	} else if (draw1 < draw2) {
		std::cout << "Player 2 wins!" << std::endl;
		line2.addBack(p2);
		pile.push(p1);
	} else if (draw1 == draw2) {
		std::cout << "It's a draw!" << std::endl;
		line1.addBack(p1);
		line2.addBack(p2);
	}
	std::cout << std::endl;

}

int main() {
	srand(time(NULL));

	Lineup line1;
	Lineup line2;
	Losers pile;
	int side1;
	int side2;
	char player;
	char loser;

	std::cout << "How many players on side 1? ";
	std::cin >> side1;
	std::cout << "Enter player names:" << std::endl;
	for (int i = 0; i < side1; i++) {
		std::cin >> player;
		line1.addBack(player);
	}
	std::cout << "How many players on side 2? ";
	std::cin >> side2;
	std::cout << "Enter player names:" << std::endl;
	for (int i = 0; i < side2; i++) {
		std::cin >> player;
		line2.addBack(player);
	}
	std::cout << "Lineup 1: ";
	line1.display();
	std::cout << std::endl;
	std::cout << "Lineup 2: ";
	line2.display();
	std::cout << "\n" << std::endl;

	round(line1, line2, pile);

	std::cout << "Final results:" << std::endl;
	std::cout << "Line 1: ";
	line1.display();
	std::cout << "\nLine 2: ";
	line2.display();
	std::cout << "\nLosers Pile: ";
	pile.display();
	std::cout << std::endl;
	/*while (line1.size() > 0 && line2.size() > 0) {
	round(line1, line2, pile);
	}*/

	std::cout << "1st place winner: " << "a" << std::endl;
	std::cout << "2nd place winner: " << "b" << std::endl;
	std::cout << "3rd place winner: " << "c" << std::endl;
	std::cout << "Winning side: " << "Poppy" << std::endl;


	return 0;

}

