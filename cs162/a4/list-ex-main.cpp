#include <iostream>
#include "list-ex.hpp"
#include "sorted.hpp"

int main() {
	//ListNode *head;

	/*head = new ListNode;
	head->value = 12.5;
	head->next = NULL;

	ListNode *secondPtr = new ListNode;
	secondPtr->value = 13.5;
	secondPtr->next = NULL;
	head->next = secondPtr;

	ListNode *head = new ListNode(13.5);
	head = new ListNode(12.5, head);
	head = new ListNode(11.5, head);

	std::cout << "First: " << head->value << std::endl;
	std::cout << "Second: " << head->next->value << std::endl;
	std::cout << "Third: " << head->next->next->value << std::endl;

	//print entire list
	ListNode *ptr = head;
	while (ptr != NULL) {
		std::cout << ptr->value << " ";
		ptr = ptr->next;
	}
	std::cout << std::endl;*/

	NumberList list;
	list.add(2);
	list.add(3);
	list.add(1);
	list.add(4);
	list.display();
	std::cout << std::endl;
	list.remove(2);
	list.display();
	std::cout << std::endl;

	std::cout << std::endl;
	Sorted list2;
	list2.add(3);
	list2.add(2);
	list2.add(1);
	list2.add(4);
	list2.display();
	std::cout << std::endl;
	list2.remove(3);
	list2.display();
	std::cout << std::endl;

	return 0;

}
