/**
 * @file            : delete_id.c
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
 * @function : delete_id
 * @param1   : input id number
 * @brief    : This function takes channel number to be delted as input
 *             and finds position to be deleted and calls delete_at_position
 *             function
 * @caller   : List main function
 */
void delete_id(int data) {
	employee_t *temp = head;
	count = 0;
	/*Find position to be deleted*/
	while (temp != NULL) {
		if (temp->id == data) {
			printf("COUNT:%d\n",count);
			delete_position(count);/*Delete at that position.*/
		} else {
			count++;
		}
		temp = temp->next;
	}
    free(temp);
}
