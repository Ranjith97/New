/**
 * @file            : display.c
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
 * @function : display
 * @brief    : This function will display elements of linked list.
 * @caller   : List main function
 */
void display()
{
    employee_t *temp = head;
    count = 0;
    /* Traverse and display elements in list */
    while (temp != NULL) {
        printf("The name of the employee is : %s\n", temp->name);
        printf("The DOB of the employee is : %d/%d/19%d\n", temp->DOB[0], \
                temp->DOB[1], temp->DOB[2]);
        printf("The experience of the employee is %d\n", temp->experience);
        printf("The domain of the employee is %s\n", temp->domain);
        printf("The ID of the employee is %d\n\n", temp->id);
        temp = temp->next;
        count = 1;
    }
    if (count == SUCCESS) {
        printf("\nThere are no elements in the list.\n\n");
    }
}
