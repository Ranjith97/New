/**
 * @file            : insert_end.c
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
 * @function       : insert_end
 * @brief          : This function will insert element at end of list
 * @caller         : List main function, insert_function
 */
void insert_end()
{
    new_node = (employee_t*)calloc(1, sizeof(employee_t));
    details = new_node;
    /* Element is inserted only when there is no duplicate element already
     * present in the list */
    if (input(head) != FAILURE) {
        if (head == NULL) {
            new_node->prev = NULL;
            new_node->next = NULL;
            head = new_node;
        }
        else {
            employee_t *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->prev = temp;
            new_node-> next = NULL;
            free(temp);
        }
    }
}
