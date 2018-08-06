/**
 * @file            : delete_id.c
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
 * @function : delete_id
 * @param1   : input id number
 * @brief    : This function takes channel number to be delted as input
 *             and finds position to be deleted and calls delete_at_position
 *             function
 * @caller   : List main function
 */
void delete_id(int data) {
	employee_t *tmp = head;
	int count1 = 1;
	/* Find position to be deleted */
	while (tmp != NULL) {
		if (tmp->id == data) {
			printf("COUNT:%d\n", count1);
			delete_position(count1);/* Delete at that position. */
		} else {
			count1++;
		}
		tmp = tmp->next;
	}
}
