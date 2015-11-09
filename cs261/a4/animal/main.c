#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

struct node {
	char *value;
	struct node *left;
	struct node *right;
};

struct BSTree {
	struct node *root;
	int cnt;
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

/* function to copy string value into new array to store in binary tree */
char * newStr(char * charBuffer) {
	char * p = (char *)malloc(1 + strlen(charBuffer));
	strcpy(p, charBuffer);
	return p;
}

/* function to read the tree of animals and questions */
struct node *readTree(FILE *a) {
	char c;
	char buffer[100];
	struct node *newNode;
	c = fgetc(a);
	if (c == 'A') {
		fgets(buffer, 100, a);
		newNode->value = newStr(buffer);
		newNode->left = 0;
		newNode->right = 0;
	} else {
		fgets(buffer, 100, a);
		newNode->value = newStr(buffer);
		newNode->left = readTree(a);
		newNode->right = readTree(a);
	}
	return newNode;
}

/*
  Main function for playing the "Guess the Animal" game.
*/
int main() {
	FILE * a;
	char buffer[100];
	a = fopen("animals.txt", "r");
	assert(a != 0);
	struct BSTree *tree = newBSTree();
	struct node *curr = tree->root;
	curr = readTree(a);
	assert(curr != 0);

	printf("You're thinking of an animal.\n");
	while (curr != 0) {
		if (curr->left && curr->right) {
			fgets(buffer, 100, a);
			printf("%s\n", buffer);
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
			fgets(buffer, 100, a);
			printf("%s\n", buffer);
			printf("Is it a %s?\n", buffer);
			fgets(buffer, 100, stdin);
			if (buffer[0] == 'Y' || buffer[0] == 'y') {
				printf("I win!\n");
			} else {
				printf("I lose!\n");
			}
		}
	}
	
	fclose(a);
    return 0;
}
