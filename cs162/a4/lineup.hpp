#ifndef LINEUP_HPP_
#define LINEUP_HPP_

#include <iostream>
#include <queue>

class Lineup {
	private:
		class QueueNode {
			friend class Lineup;
			char player;
			QueueNode *next;
			// constructor
			QueueNode(char pl, QueueNode *n1 = NULL) {
				player = pl;
				next = n1;
			}
		};
		QueueNode *front;
		QueueNode *end;

	public:
		Lineup();
		~Lineup();
		void addBack(char); // puts winner at back of lineup
		char getFront(); // returns player at front of line
		void removeFront(char &); // removes player from front of line
		void display() const;
		bool isEmpty() const;
};

#endif /* LINEUP_HPP_ */
