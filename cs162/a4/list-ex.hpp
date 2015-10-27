#ifndef LIST_EX_HPP_
#define LIST_EX_HPP_

#include <iostream>


class NumberList {
	protected:
		struct ListNode {
			double value;
			ListNode *next;
			// constructor
			ListNode(double v, ListNode *n1 = NULL) {
				value = v;
				next = n1;
			}
		};
		ListNode *head;

	public:
		NumberList() {
			head = NULL;
		}
		~NumberList();
		void add(double num);
		void remove(double num);
		void display() const;
};

#endif /* LIST_EX_HPP_ */
