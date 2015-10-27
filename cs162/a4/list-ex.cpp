#include <iostream>
#include "list-ex.hpp"


void NumberList::add(double num) {
	if (head == NULL) {
		head = new ListNode(num);
	} else {
		// list not empty, traverse list
		ListNode *ptr = head;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = new ListNode(num);
	}
}

void NumberList::remove(double num) {
	ListNode *ptr, *prevptr;

	// list empty, do nothing
	if (!head) return;

	// is first node the one to delete?
	if (head->value == num) {
		ptr = head;
		head = ptr->next;
		delete ptr;
	} else {
		ptr = head;
		while (ptr != NULL && ptr->value != num) {
			prevptr = ptr;
			ptr = ptr->next;
		}
		if (ptr) {
			prevptr->next = ptr->next;
			delete ptr;
		}
	}
}

void NumberList::display() const {
	ListNode *ptr = head;

	while (ptr) {
		std::cout << ptr->value << " ";
		ptr = ptr->next;
	}
}

NumberList::~NumberList() {
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

