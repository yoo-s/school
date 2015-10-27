#include <iostream>
#include <stack>
#include <stdlib.h>
#include "losers.hpp"

/*********************************************
 ** Function: Losers::push
 ** Description: pushes element on top of stack
 ** Parameters: char pl
 ********************************************/
void Losers::push(char pl) {
	top = new PileNode(pl, top);
}

/*********************************************
 ** Function: Losers::peek
 ** Description: returns element on top of stack
 ** Parameters: none
 ********************************************/
char Losers::peek() {
	return top->player;
}

/*********************************************
 ** Function: Losers::pop
 ** Description: removes element on top of stack
 ** Parameters: char &pl
 ********************************************/
void Losers::pop(char &pl) {
	PileNode *temp;

	if (isEmpty()) {
		std::cout << "Pile is empty.\n";
		exit(1);
	} else {				// pop player off top
		pl = top->player;
		temp = top;
		top = top->next;
		delete temp;
	}
}

/*********************************************
 ** Function: Losers::display
 ** Description: displays stack's elements
 ** Parameters: none
 ********************************************/
void Losers::display() const {
	PileNode *ptr = top;

	while (ptr) {
		std::cout << ptr->player << " ";
		ptr = ptr->next;
	}
}

/*********************************************
 ** Function: Losers::isEmpty
 ** Description: checks if stack is empty
 ** Parameters: none
 ********************************************/
bool Losers::isEmpty() const {
	if (!top) {
		return true;
	} else {
		return false;
	}
}

