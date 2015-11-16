#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


int main (int argc, const char * argv[])
{
	char cmd = ' ';
	DynArr* mainList = createDynArr(10);
	char desc[TASK_DESC_SIZE];
	int priority;
	char filename[30];
	char *newline;
	FILE *fileptr;

	printf("\n\n** TO-DO LIST APPLICATION **\n\n");

	do {
		printf("Press:\n"
		"'l' to load to-do list from a file\n"
		"'s' to save to-do list to a file\n"
		"'a' to add a new task\n"
		"'g' to get the first task\n"
		"'r' to remove the first task\n"
		"'p' to print the list\n"
		"'e' to exit the program\n"
		);
		/* get input command (from the keyboard) */
		cmd = getchar();
		/* clear the trailing newline character */
		while (getchar() != '\n');

		/* Fixme:  Your logic goes here! */
		switch (cmd) {
			/* load list */
			case 'l':
				printf("Type filename: ");
				if (fgets(filename, sizeof(filename), stdin) != 0) {
					newline = strchr(filename, '\n');
					if (newline) {
						*newline = '\0';
					}
				}
				fileptr = fopen(filename, "r");
				if (fileptr == 0) {
					fprintf(stderr, "Error: unable to open file.\n\n");
					break;
				}
				loadList(mainList, fileptr);
				fclose(fileptr);
				printf("Loaded list.\n\n");
				break;
			
			/* save list */
			case 's':
				if (sizeDynArr(mainList) > 0) {
					printf("Type filename: ");
					if (fgets(filename, sizeof(filename), stdin) != 0) {
						newline = strchr(filename, '\n');
						if (newline) {
							*newline = '\0';
						}
					}
					fileptr = fopen(filename, "w");
					if (fileptr == 0) {
						fprintf(stderr, "Error: unable to open file.\n\n");
						break;
					}
					saveList(mainList, fileptr);
					fclose(fileptr);
					printf("Saved list.\n\n");
				} else {
					printf("List is empty.\n\n");
				}
				break;

			/* add new task */
			case 'a':
				printf("Task description: ");
				if (fgets(desc, sizeof(desc), stdin) != 0) {
					newline = strchr(desc, '\n');
					if (newline) {
						*newline = '\0';
					}
				}
				do {
					printf("Task priority (0-999): ");
					scanf("%d", &priority);
				} while (!(priority >= 0 && priority <= 999));

				TaskP new = createTask(priority, desc);
				addHeap(mainList, new, compare);
				printf("Added task '%s'.\n\n", desc);
				break;

			/* get first task */
			case 'g':
				if (sizeDynArr(mainList) > 0) {
					printf("First task: %s\n\n", ((struct Task*)getMinHeap(mainList))->description);
				} else {
					printf("List is empty.\n\n");
				}
				break;

			/* remove first task */
			case 'r':
				if (sizeDynArr(mainList) > 0) {
					printf("Removed first task '%s'.\n\n", ((struct Task*)getMinHeap(mainList))->description);
					removeMinHeap(mainList, compare);
				} else {
					printf("List is empty.\n\n");
				}
				break;

			/* print list */
			case 'p':
				if (sizeDynArr(mainList) > 0) {
					printList(mainList);
				} else {
					printf("List is empty.\n\n");
				}
				break;

			/* exit program */
			case 'e':
				printf("Exit.\n\n");
				break;
		}
	/* Note: We have provided functions called printList(), saveList() and loadList() for you to use.  They can be found in toDoList.c */
	} while(cmd != 'e');
	/* delete the list */
	deleteDynArr(mainList);

	return 0;
}
