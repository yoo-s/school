#include <iostream>
#include <stack>
#include <stdlib.h>
#include "losers.hpp"

void Losers::push(char pl) {
	top = new PileNode(pl, top);
}

char Losers::peek() {
	return top->player;
}

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

void Losers::display() const {
	PileNode *ptr = top;

	while (ptr) {
		std::cout << ptr->player << " ";
		ptr = ptr->next;
	}
}

bool Losers::isEmpty() const {
	if (!top) {
		return true;
	} else {
		return false;
	}
}
/*
Losers::~Losers() {
	ListNode *ptr = head;

	while (ptr != NULL) {
		// garbage keeps track of node to be deleted
		ListNode *garbage = ptr;
		// Move to next node if there is one
		ptr = ptr->next;
		// delete garbage node
		delete garbage;
	}
}
*/
