#include <iostream>
#include <queue>
#include <stdlib.h>
#include "lineup.hpp"

/*********************************************
 ** Function: Lineup::Lineup
 ** Description: constructor
 ** Parameters: none
 ********************************************/
Lineup::Lineup() {
	front = NULL;
	end = NULL;
}

/*********************************************
 ** Function: Lineup::addBack
 ** Description: adds element to the end of queue
 ** Parameters: char pl
 ********************************************/
void Lineup::addBack(char pl) {
	if (isEmpty()) {
		front = new QueueNode(pl);
		end = front;
	} else {
		end->next = new QueueNode(pl);
		end = end->next;
	}
}

/*********************************************
 ** Function: Lineup::getFront
 ** Description: returns the element at front of queue
 ** Parameters: none
 ********************************************/
char Lineup::getFront() {
	return front->player;
}

/*********************************************
 ** Function: Lineup::removeFront
 ** Description: removes the element at front of queue
 ** Parameters: char &pl
 ********************************************/
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

/*********************************************
 ** Function: Lineup::display
 ** Description: displays the queue's elements
 ** Parameters: none
 ********************************************/
void Lineup::display() const {
	QueueNode *ptr = front;

	while (ptr) {
		std::cout << ptr->player << " ";
		ptr = ptr->next;
	}
}

/*********************************************
 ** Function: Lineup::isEmpty
 ** Description: checks if queue is empty
 ** Parameters: none
 ********************************************/
bool Lineup::isEmpty() const {
	if (front == NULL) {
		return true;
	} else {
		return false;
	}
}

/*********************************************
 ** Function: Lineup::~Lineup
 ** Description: destructor
 ** Parameters: none
 ********************************************/
Lineup::~Lineup() {
	char player;

	while(!isEmpty()) {
		removeFront(player);
	}
}

