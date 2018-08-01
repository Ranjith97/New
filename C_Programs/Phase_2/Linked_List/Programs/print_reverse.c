/**
 * @file            : print_reverse.c
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
 * @function : print_reverse
 * @brief    : This function will print linked list in reverse order.
 * @caller   : List main function
 */
void print_reverse()
{
	employee_t *temp = head;
    count = 0;
	/*traverse to end*/
	if (temp != NULL) {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        while (temp != NULL) {
            printf("The details of the employees %d is:\n", count + 1);
            printf("The name of the employee is : %s\n", temp->name);
            printf("The DOB of the employee is : %d/%d/19%d\n", temp->DOB[0], \
                    temp->DOB[1], temp->DOB[2]);
            printf("The experience of the employee is %d\n", temp->experience);
            printf("The domain of the employee is %s\n", temp->domain);
            printf("The ID of the employee is %d\n", temp->id);
            temp = temp->next;
            count++;
        }
        free(temp);
    }
}

