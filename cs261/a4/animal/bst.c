/*
  File: bst.c
  Implementation of the binary search tree data structure.
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "bst.h"
#include "structs.h"


struct Node {
    TYPE         val;
    struct Node *left;
    struct Node *right;
};

struct BSTree {
    struct Node *root;
    int          cnt;
};

/*----------------------------------------------------------------------------*/
/*
  function to initialize the binary search tree.
  param tree
  pre: tree is not null
  post:	tree size is 0
  root is null
*/
void initBSTree(struct BSTree *tree)
{
    tree->cnt  = 0;
    tree->root = 0;
}

/*
  function to create a binary search tree.
  param: none
  pre: none
  post: tree->count = 0
  tree->root = 0;
*/
struct BSTree*  newBSTree()
{
    struct BSTree *tree = (struct BSTree *)malloc(sizeof(struct BSTree));
    assert(tree != 0);

    initBSTree(tree);
    return tree;
}

/*----------------------------------------------------------------------------*/
/*
  function to free the nodes of a binary search tree
  param: node  the root node of the tree to be freed
  pre: none
  post: node and all descendants are deallocated
*/
void _freeBST(struct Node *node)
{
    if (node != 0) {
		_freeBST(node->left);
		_freeBST(node->right);
		free(node);
    }
}

/*
  function to clear the nodes of a binary search tree
  param: tree    a binary search tree
  pre: tree ! = null
  post: the nodes of the tree are deallocated
  tree->root = 0;
  tree->cnt = 0
*/
void clearBSTree(struct BSTree *tree)
{
    _freeBST(tree->root);
    tree->root = 0;
    tree->cnt  = 0;
}

/*
  function to deallocate a dynamically allocated binary search tree
  param: tree   the binary search tree
  pre: tree != null;
  post: all nodes and the tree structure itself are deallocated.
*/
void deleteBSTree(struct BSTree *tree)
{
    clearBSTree(tree);
    free(tree);
}

/*----------------------------------------------------------------------------*/
/*
  function to determine if  a binary search tree is empty.

  param: tree    the binary search tree
  pre:  tree is not null
*/
int isEmptyBSTree(struct BSTree *tree) { return (tree->cnt == 0); }

/*
  function to determine the size of a binary search tree

  param: tree    the binary search tree
  pre:  tree is not null
*/
int sizeBSTree(struct BSTree *tree) { return tree->cnt; }

/*----------------------------------------------------------------------------*/
/*
  recursive helper function to add a node to the binary search tree.
  HINT: You have to use the compare() function to compare values.
  param:  cur	the current root node
  val	the value to be added to the binary search tree
  pre:	val is not null
*/
struct Node *_addNode(struct Node *cur, TYPE val)
{
    /*DONE: write this*/
	assert(val != 0);
	if (cur == NULL) {
		struct Node *newNode = malloc(sizeof(struct Node));
		assert(newNode != 0);
		newNode->left = 0;
		newNode->right = 0;
		newNode->val = val;
		return newNode;
	} else if (compare(val, cur->val) <= 0) {
		cur->left = _addNode(cur->left, val);
	} else {
		cur->right = _addNode(cur->right, val);
	}
    return cur;
}

/*
  function to add a value to the binary search tree
  param: tree   the binary search tree
  val		the value to be added to the tree

  pre:	tree is not null
  val is not null
  pose:  tree size increased by 1
  tree now contains the value, val
*/
void addBSTree(struct BSTree *tree, TYPE val)
{
    tree->root = _addNode(tree->root, val);
    tree->cnt++;
}

/*
  function to determine if the binary search tree contains a particular element
  HINT: You have to use the compare() function to compare values.
  param:	tree	the binary search tree
  val		the value to search for in the tree
  pre:	tree is not null
  val is not null
  post:	none
*/

/*----------------------------------------------------------------------------*/
int containsBSTree(struct BSTree *tree, TYPE val)
{
    /*DONE: write this*/
	assert(tree != 0);
	assert(val != 0);
	struct Node *itr = tree->root;
	while (itr != 0) {
		if (compare(itr->val, val) == 0) {
			return 1;
		} else if (compare(itr->val, val) < 0) {
			itr = itr->right;
		} else {
			itr = itr->left;
		}
	}
    return 0;
}

/*
  helper function to find the left most child of a node
  return the value of the left most child of cur
  param: cur		the current node
  pre:	cur is not null
  post: none
*/

/*----------------------------------------------------------------------------*/
TYPE _leftMost(struct Node *cur)
{
    /*DONE: write this*/
	assert(cur != 0);
	while (cur->left != 0) {
		cur = cur->left;
	}
    return cur->val;
}

/*
  recursive helper function to remove the left most child of a node
  HINT: this function returns cur if its left child is NOT NULL. Otherwise,
  it returns the right child of cur and free cur.

  Note:  If you do this iteratively, the above hint does not apply.

  param: cur	the current node
  pre:	cur is not null
  post:	the left most node of cur is not in the tree
*/
/*----------------------------------------------------------------------------*/
struct Node *_removeLeftMost(struct Node *cur)
{
    /*DONE: write this*/
	assert(cur != 0);
	if (cur->left != 0) {
		cur->left = _removeLeftMost(cur->left);
		return cur;
	} else {
		struct Node *rght = cur->right;
		free(cur);
		return rght;
	}
}

/*
  recursive helper function to remove a node from the tree
  HINT: You have to use the compare() function to compare values.
  param:	cur	the current node
  val	the value to be removed from the tree
  pre:	val is in the tree
  cur is not null
  val is not null
*/
/*----------------------------------------------------------------------------*/
struct Node *_removeNode(struct Node *cur, TYPE val)
{
    /*DONE: write this*/
	assert(cur != 0);
	assert(val != 0);
	if (compare(val, cur->val) == 0) {
		if (cur->right == 0) {
			struct Node *lft = cur->left;
			free(cur);
			return lft;
		} else {
			cur->val = _leftMost(cur->right);
			cur->right = _removeLeftMost(cur->right);
		}
	} else if (compare(val, cur->val) < 0) {
		cur->left = _removeNode(cur->left, val);
	} else {
		cur->right = _removeNode(cur->right, val);
	}
    return cur;
}

/*
  function to remove a value from the binary search tree
  param: tree   the binary search tree
  val		the value to be removed from the tree
  pre:	tree is not null
  val is not null
  val is in the tree
  pose:	tree size is reduced by 1
*/
void removeBSTree(struct BSTree *tree, TYPE val)
{
    if (containsBSTree(tree, val)) {
	tree->root = _removeNode(tree->root, val);
	tree->cnt--;
    }
}

/*----------------------------------------------------------------------------*/

/* The following is used only for debugging, set to "#if 0" when used 
   in other applications */
#if 1
#include <stdio.h>

/*----------------------------------------------------------------------------*/
void printNode(struct Node *cur) {
    if (cur == 0)
	return;
    printf("(");
    printNode(cur->left);
    /*Call print_type which prints the value of the TYPE*/
    print_type(cur->val);
    printNode(cur->right);
    printf(")");
}

void printTree(struct BSTree *tree) {
    if (tree == 0)
	return;
    printNode(tree->root);
}
/*----------------------------------------------------------------------------*/

#endif


/************************************************************************************************************************
from here to the end of this file are a set of fucntions for testing the fucntions of the BST
***************************************************************************************************************************/
/*
  function to built a Binary Search Tree (BST) by adding numbers in this specific order
  the graph is empty to start: 50, 13, 110 , 10

*/
struct Node *readTree(FILE *a) {
	char c;
	char buffer[100];
	struct Node *newNode;
	c = fgetc(a);
	if (compare(c, 'A' == 0)) {
		fgets(buffer, 100, a);
		_addNode(newNode, *newStr(buffer));
	} else {
		fgets(buffer, 100, a);
		_addNode(newNode, *newStr(buffer));
		newNode->left = readTree(a);
		newNode->right = readTree(a);
	}
	return newNode;
}

char * newStr(char * charBuffer) {
	char * p = (char *)malloc(1 + strlen(charBuffer));
	strcpy(p, charBuffer);
	return p;
}

/*
  Main function for testing different fucntions of the Assignment#4.
*/
int main(int argc, char *argv[]) {

	FILE * a;
	char buffer[100];
	struct BSTree *tree = newBSTree();
	struct Node *curr = malloc(sizeof(struct Node));
	assert(curr != 0);
	a = fopen("animals.txt", "r");
	curr = readTree(tree, a);
	assert(a != 0);
	while(fgets(buffer, 100, a) != 0) {
		printf("%s\n", buffer);
	}

	printf("You're thinking of an animal.\n");
	while (curr != 0) {
	if (curr->left && curr->right) {
		fgets(buffer, 100, a);
		fgets(buffer, 100, stdin);
		if (buffer[0] == 'Y' || buffer[0] == 'y') {
			printf("You answered yes.\n");
			curr = curr->left;
		} else {
			printf("You answered no.\n");
			curr = curr->right;
		}
	} else {
		// ask if animal is correct;
		printf("Is this the right animal?\n");
		fgets(buffer, 100, stdin);
		if (buffer[0] == 'Y' || buffer[0] == 'y') {
			printf("I win!\n");
		} else {
			printf("I lose!\n");
		}
	}
	
	fclose(a);
    return 0;
}
