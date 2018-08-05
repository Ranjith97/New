/**
 * @file            : insert_position.c
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
 * @function : insert_position
 * @param1   : position to be inserted
 * @brief    : This function position to be deleted as input and inserts element
 *             at that position.
 * @caller   : List main function
 */
void insert_position(int position) {
    employee_t *temp = head;
    employee_t *previous = head;
    int prev_loc = 0;
    count = 0;
    /* Counting the number of elements in the list */
    while (temp != NULL) {
        temp = temp->next;
        count++;
    }
    free(temp);
    previous = head;
    if (count > position && position != 0) {
        /* Traversing till the position is reached */
        while (prev_loc < position - 2) {
            previous = previous->next;
            prev_loc++;
        }
        new_node = (employee_t *)calloc(1, sizeof(employee_t));
        details = new_node;
        /* Element is inserted only when there is no duplicate element already
         * present in the list */
        if (input(head) != FAILURE) {
            new_node->next = previous->next;
            new_node->prev = previous;
            if (previous->next != NULL) {
                previous->next->prev = new_node;
            }
            previous->next = new_node;
        }
    }
    else if (position - 1 == 0) {
        insert_begin();
    }
    else if (count == position) {
        insert_end();
    }
    else {
        printf("\nSorry!There are only %d elements in the list\n", count);
    }
    free(previous);
}
