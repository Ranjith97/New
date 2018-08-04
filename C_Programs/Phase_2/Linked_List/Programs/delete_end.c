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
 * @function : delete_end
 * @brief    : This function will delete the last element in list.
 * @caller   : delete_position
 */
void delete_end() {
    employee_t *toDelete;

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
