/**
 * @file            : insert_position.c
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
 * @function : insert_position
 * @param1   : position to be inserted
 * @brief    : This function position to be deleted as input and inserts element
 *             at that position.
 * @caller   : List main function
 */
void insert_position(int position) {
    employee_t *temp = head;
    employee_t *previous = head;
    employee_t *next_element = head;
    employee_t *new_node = (employee_t *)calloc(1, sizeof(employee_t));
    int prev_loc = 0;
    count = 0;
    while (temp != NULL) {
        temp = temp->next;
        count++;
    }
    previous = head;
    if (count >= position && position != 0) {
        while (prev_loc < position-2) {
            previous = previous->next;
            prev_loc++;
        }
        details = new_node;
        /* Element is inserted only when there is no duplicate element already
         * present in the list */
        if (input(head) != FAILURE) {
            next_element = previous->next;
            new_node->prev = previous;
            new_node->next = next_element;
            previous->next = new_node;
            next_element->prev = new_node;
        }
        else if (position == 0) {
            insert_begin();
        }
        else if (count++ == position) {
            insert_end();
        }
        else {
            printf("\nSorry!There are only %d elements in the list", count);
        }
    }
    free(temp);
    free(previous);
    free(new_node);
    free(next_element);
}
