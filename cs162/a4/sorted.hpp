#ifndef SORTED_HPP_
#define SORTED_HPP_

#include <iostream>
#include "list-ex.hpp"

class Sorted : public NumberList {
	public:
		void add(double num);
};

void Sorted::add(double num) {
	ListNode *ptr, *prevptr;

	if (head == NULL || head->value >= num) {
		head = new ListNode(num, head);
	} else {
		prevptr = head;
		ptr = head->next;

		while (ptr != NULL && ptr->value < num) {
			prevptr = ptr;
			ptr = ptr->next;
		}
		prevptr->next = new ListNode(num, ptr);
	}
}

#endif /* SORTED_HPP_ */
