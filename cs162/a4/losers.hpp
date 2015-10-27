#ifndef LOSERS_HPP_
#define LOSERS_HPP_

#include <iostream>
#include <stack>

/*********************************************
 ** Class: Losers
 ** Description: stack containing loser players
 ** Pre-Conditions: none
 ********************************************/
class Losers {
	private:
		class PileNode {
			friend class Losers;
			char player;
			PileNode *next;
			//constructor
			PileNode(char p1, PileNode *n1 = NULL) {
				player = p1;
				next = n1;
			}
		};
		PileNode *top;

	public:
		Losers() {
			top = NULL;
		}
		void push(char); // puts loser on loser pile
		char peek(); // returns loser on top of pile
		void pop(char &); // removes loser from top of pile
		void display() const;
		bool isEmpty() const;
};

#endif /* LOSERS_HPP_ */
