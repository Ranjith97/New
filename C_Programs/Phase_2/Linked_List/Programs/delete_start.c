/**
 * @file            : delete_start.c
 * @brief           : This program will create a doubly linked list and do the
 *                    operations like insertion, deletion (both all cases),
 *                    printing in reversed order and displaying the contents
 *                    of the list based upon the user input
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013, VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */
#include"List.h"

/**
 * @function : delete_start
 * @brief    : This function will delete element at start of list.
 * @caller   : delete_position
 */
void delete_start() {
	employee_t *toDelete;

	if(head == NULL)
	{
		printf("Unable to delete. List is empty.\n");
	}
	else
	{
		toDelete = head;
		head = head->next; /* Move head pointer to 2 node */
		if (head != NULL) {
			head->prev = NULL; /* Remove the link to previous node */
		}
		free(toDelete); /* Delete the first node from memory */
	}
}
