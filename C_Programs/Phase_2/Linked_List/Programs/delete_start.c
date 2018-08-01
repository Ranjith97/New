/**
 * @file            : delete_start.c
 * @brief           :
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
	employee_t *temp = head;
	if (temp != NULL) {
		if (head->next == NULL)
		{
			head = NULL;
			return;
		}
		head = head->next;
		head->prev = NULL;
		free(temp);
	}
    else {
		printf("No elements in list\n");
	}
}
