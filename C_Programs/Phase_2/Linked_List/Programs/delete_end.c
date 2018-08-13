/**
 * @file            : delete_end.c
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
 * @function : delete_end
 * @brief    : This function will delete the last element in list.
 * @caller   : delete_position
 */
void delete_end() {
    employee_t *toDelete = NULL;

    if(head == NULL)
    {
        printf("Unable to delete. List is empty.\n");
    }
    else
    {
        toDelete = head;
        while (toDelete != NULL) {
            if (toDelete-> next == NULL) {
                toDelete->prev->next = NULL;
                free(toDelete); /* Freeing the allocated memory */
                break;
            }
            /* Traversing till last element is reached */
            toDelete = toDelete->next;
        }
    }
}
