/**
 * @file            : delete_end.c
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
 * @function : deletet_end
 * @brief    : This function will delete the last element in list.
 * @caller   : delete_position
 */
void delete_end() {
	employee_t *temp = head;
	employee_t *last_one = head;
	if (temp != NULL) {
		while (temp->next != NULL) {
			temp = temp->next;
		}
		last_one = temp->prev;
		last_one->next = NULL;
		free(temp);
        free(last_one);
	}
    else {
		printf("\nNo elements present in the list\n");
	}
}
