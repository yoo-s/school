#include <iostream>
#include <queue>
#include <stdlib.h>
#include "lineup.hpp"

Lineup::Lineup() {
	front = NULL;
	end = NULL;
}

void Lineup::addBack(char pl) {
	if (isEmpty()) {
		front = new QueueNode(pl);
		end = front;
	} else {
		end->next = new QueueNode(pl);
		end = end->next;
	}
}

char Lineup::getFront() {
	return front->player;
}

void Lineup::removeFront(char &pl) {
	QueueNode *temp;

	if (isEmpty()) {
		std::cout << "Line is empty.\n";
		exit(1);
	} else {				// pop player off top
		pl = front->player;
		temp = front;
		front = front->next;
		delete temp;
	}
}

void Lineup::display() const {
	QueueNode *ptr = front;

	while (ptr) {
		std::cout << ptr->player << " ";
		ptr = ptr->next;
	}
}

bool Lineup::isEmpty() const {
	if (front == NULL) {
		return true;
	} else {
		return false;
	}
}

Lineup::~Lineup() {
	char player;

	while(!isEmpty()) {
		removeFront(player);
	}
}

