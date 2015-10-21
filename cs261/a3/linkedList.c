#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


/* Double Link */
struct DLink {
	TYPE value;
	struct DLink * next;
	struct DLink * prev;
};

/* Double Linked List with Head and Tail Sentinels  */
struct linkedList {
	int size;
	struct DLink *firstLink;
	struct DLink *lastLink;
};

/*
	initList
	param lst the linkedList
	pre: lst is not null
	post: lst size is 0
*/
void _initList (struct linkedList *lst) {		// DONE
  /* FIXME: you must write this */
	assert(lst != 0);
	lst->firstLink = malloc(sizeof(struct DLink));
	assert(lst->firstLink != 0);
	lst->lastLink = malloc(sizeof(struct DLink));
	assert(lst->lastLink != 0);
	lst->firstLink->next = lst->lastLink;
	lst->lastLink->next = lst->firstLink;
	lst->size = 0;
}

/*
	createList
	param: none
	pre: none
	post: firstLink and lastLink reference sentinels
*/
struct linkedList *createLinkedList() {
	struct linkedList *newList = malloc(sizeof(struct linkedList));
	_initList(newList);
	return(newList);
}

/*
	_addLinkBeforeBefore
	param: lst the linkedList
	param: l the  link to add before
	param: v the value to add
	pre: lst is not null
	pre: l is not null
	post: lst is not empty
*/

/* Adds Before the provided link, l */
void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v) {	// DONE
	/* FIXME: you must write this */
	struct DLink *new = malloc(sizeof(struct DLink));
	assert(lst != 0);
	assert(l != 0);
	assert(new != 0);
	new->value = v;
	new->next = l;
	new->prev = l->prev;

	l->prev->next = new;
	l->prev = new;
	lst->size++;
}

/*
	_removeLink
	param: lst the linkedList
	param: l the link to be removed
	pre: lst is not null
	pre: l is not null
	post: lst size is reduced by 1
*/
void _removeLink(struct linkedList *lst, struct DLink *l) {		// DONE
	/* FIXME: you must write this */
	assert(lst != 0);
	assert(l != 0);
	struct DLink *temp = malloc(sizeof(struct DLink));
	assert(temp != 0);
	temp = l;
	l->prev->next = temp->next;
	l->next->prev = temp->prev;
	free(temp);
	lst->size--;
}

/*
	isEmptyList
	param: lst the linkedList
	pre: lst is not null
	post: none
*/
int isEmptyList(struct linkedList *lst) {		// DONE
 	/* FIXME: you must write this */
	assert(lst != 0);
	if (lst->size == 0) {
		return 1;
	} else {
		return 0;
	}
	/*temporary return value...you may need to change this */
	//return(1);
}

/*
	De-allocate all links of the list
	param: 	lst		pointer to the linked list
	pre:	none
	post:	All links (including the two sentinels) are de-allocated
*/
void freeLinkedList(struct linkedList *lst) {
	while(!isEmptyList(lst)) {
		/* remove the link right after the first sentinel */
		_removeLink(lst, lst->firstLink->next);
	}		
	/* remove the first and last sentinels */
	free(lst->firstLink);
	free(lst->lastLink);
}

/*
	Deallocate all the links and the linked list itself.
	param: 	lst		pointer to the dynamic array
	pre:	lst is not null
	post:	the memory used by lst->data is freed
*/
void deleteLinkedList(struct linkedList *lst) {
	assert (lst != 0);
	freeLinkedList(lst);
	free(lst);
}

/*
	Function to print list
	pre: lst is not null
*/
void _printList(struct linkedList* lst) {		// DONE
	/* FIXME: you must write this */
	assert(lst != 0);
	struct Dlink *beg = malloc(sizeof(struct DLink));
	beg = lst->firstLink->next;
	assert(beg != 0);
	while (beg != lst->lastLink) {
		printf("%d", beg->value);
		beg = beg->next;
	}
}


/* ************************************************************************
	Deque Interface Functions
************************************************************************ */

/*
	addFrontList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/
void addFrontList(struct linkedList *lst, TYPE e) {		// DONE
	/* FIXME: you must write this */
	assert(lst != 0);
	_addLinkBefore(lst, lst->firstLink->next, e);
}

/*
	addBackList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/
void addBackList(struct linkedList *lst, TYPE e) {		// DONE
  
	/* FIXME: you must write this */
	assert(lst != 0);
	_addLinkBefore(lst, lst->lastLink, e);
}

/*
	frontList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: none
*/
TYPE frontList (struct linkedList *lst) {		// DONE
	/* FIXME: you must write this */
	/*temporary return value...you may need to change this */
	assert(lst != 0);
	assert(!isEmptyList(lst));
	return(lst->firstLink->next->value);
}

/*
	backList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: lst is not empty
*/
TYPE backList(struct linkedList *lst) {			// DONE
	/* FIXME: you must write this */
	/*temporary return value...you may need to change this */
	assert(lst != 0);
	assert(!isEmptyList(lst));
	return(lst->lastLink->prev->value);
}

/*
	removeFrontList
	param: lst the linkedList
	pre:lst is not null
	pre: lst is not empty
	post: size is reduced by 1
*/
void removeFrontList(struct linkedList *lst) {		// DONE
   	/* FIXME: you must write this */
	assert(lst != 0);
	assert(!isEmptyList(lst));
	_removeLink(lst, lst->firstLink->next);
}

/*
	removeBackList
	param: lst the linkedList
	pre: lst is not null
	pre:lst is not empty
	post: size reduced by 1
*/
void removeBackList(struct linkedList *lst) {		// DONE
	/* FIXME: you must write this */
	assert(lst != 0);
	assert(!isEmptyList(lst));
	_removeLink(lst, lst->lastLink->prev);
}


/* ************************************************************************
	Stack Interface Functions
************************************************************************ */

/*
	Add an item to the bag
	param: 	lst		pointer to the bag
	param: 	v		value to be added
	pre:	lst is not null
	post:	a link storing val is added to the bag
*/
void addList(struct linkedList *lst, TYPE v) {		// DONE
	/* FIXME: you must write this */
	assert(lst != 0);
	addFrontList(lst, v);
}

/*
	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	lst		pointer to the bag
	param:	e		the value to look for in the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	no changes to the bag
*/
int containsList (struct linkedList *lst, TYPE e) {		// DONE
	/* FIXME: you must write this */
	assert(lst != 0);
	assert(!isEmptyList(lst));
	struct DLink *test = malloc(sizeof(struct DLink));
	test = lst->firstLink->next;
	assert(test != 0);
	while (test != lst->lastLink) {
		if (test->value == e) {
			return 1;
		} else {
			return 0;
		}
		test = test->next;
	}

	/*temporary return value...you may need to change this */
	//return(1);
}

/*
	Removes the first occurrence of the specified value from the collection if it occurs
	param:	lst		pointer to the bag
	param:	e		the value to be removed from the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	e has been removed
	post:	size of the bag is reduced by 1
*/
void removeList (struct linkedList *lst, TYPE e) {		// DONE
	/* FIXME: you must write this */
	assert(lst != 0);
	assert(!isEmptyList(lst));
	struct DLink *test = malloc(sizeof(struct DLink));
	test = lst->firstLink->next;
	assert(test != 0);
	while (test != lst->lastLink) {
		if (test->value == e) {
			_removeLink(lst, test);
		}
		test = test->next;
	}
}
