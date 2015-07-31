/*********************************************
 ** Program: tournament.cpp
 ** Author: Soo-Min Yoo
 ** Date: 07/30/15
 ** Description: program that runs a competition using two lineups and a loser pile 
	through the use of stacks and queues.
 ** Input: none
 ** Output: none
 ********************************************/

#include <iostream>
#include <stack>
#include <queue>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "lineup.hpp"
#include "losers.hpp"

/*********************************************
 ** Function: round
 ** Description: conducts rounds of combat until only one player remains.
 ** Parameters: Lineup &line1, Lineup &line2, Losers &pile, int &s1, int &s2
 ********************************************/
void round(Lineup &line1, Lineup &line2, Losers &pile, int &s1, int &s2) {
	int draw1;
	int draw2;

	// take front of each line and decrement number of players in queues
	char p1 = line1.getFront();
	line1.removeFront(p1);
	s1--;
	char p2 = line2.getFront();
	line2.removeFront(p2);
	s2--;

	// draw random roll for both players
	draw1 = (rand() % 10 + 1);
	std::cout << "Roll 1: " << draw1 << std::endl;
	draw2 = (rand() % 10 + 1);
	std::cout << "Roll 2: " << draw2 << std::endl;

	// determine winner and loser
	if (draw1 > draw2) {
		std::cout << "Player 1 wins!" << std::endl;
		line1.addBack(p1);
		s1++;
		pile.push(p2);
	} else if (draw1 < draw2) {
		std::cout << "Player 2 wins!" << std::endl;
		line2.addBack(p2);
		s2++;
		pile.push(p1);
	} else if (draw1 == draw2) {
		std::cout << "It's a draw!" << std::endl;
		line1.addBack(p1);
		s1++;
		line2.addBack(p2);
		s2++;
	}
	// print resulting player locations
	std::cout << std::endl;
	std::cout << "Line 1: ";
	line1.display();
	std::cout << "\nLine 2: ";
	line2.display();
	std::cout << "\nLosers Pile: ";
	pile.display();
	std::cout << "\n" << std::endl;

}

/*********************************************
 ** Function: main
 ** Description: runs program
 ********************************************/
int main() {
	srand(time(NULL));

	Lineup line1;
	Lineup line2;
	Losers pile;
	int size1;
	int size2;
	char player;
	char loser;
	int roundnum = 1;

	// prompt user for number of players in both line 1
	std::cout << "How many players on line 1? ";
	std::cin >> size1;
	// prompt for player names
	std::cout << "Enter player names:" << std::endl;
	for (int i = 0; i < size1; i++) {
		std::cin >> player;
		line1.addBack(player);
	}
	// same for line 2
	std::cout << "How many players on line 2? ";
	std::cin >> size2;
	std::cout << "Enter player names:" << std::endl;
	for (int i = 0; i < size2; i++) {
		std::cin >> player;
		line2.addBack(player);
	}
	// display players in both lines
	std::cout << "Lineup 1: ";
	line1.display();
	std::cout << std::endl;
	std::cout << "Lineup 2: ";
	line2.display();
	std::cout << "\n" << std::endl;

	// run competition rounds until one player remains
	while (size1 > 0 && size2 > 0) {
		std::cout << "Round " << roundnum << "-------------" << std::endl;
		round(line1, line2, pile, size1, size2);
		roundnum++;
	}
	int winside;
	// determine winning side
	if (size1 > size2) {
		winside = 1;
	} else if (size1 < size2) {
		winside = 2;
	}

	// print final 3 winners and winning side
	std::cout << "Final results ----------------" << std::endl;
	std::cout << "1st place winner: " << "a" << std::endl;
	std::cout << "2nd place winner: " << "b" << std::endl;
	std::cout << "3rd place winner: " << "c" << std::endl;
	std::cout << "Winning side: Line " << winside << std::endl;
	std::cout << std::endl;

	return 0;

}

