/**
 * @file            : delete_poistion.c
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
 * @function : delete_position
 * @param1   : position
 * @brief    : This function will delete element at a particular position
 * @caller   : delete_id
 */
void delete_position(int position) {
    employee_t *temp = head;
    employee_t *del_ptr = head;
    employee_t *previous = head;
    employee_t *next_element = head;
    int prev_loc = 0;
    count = 0;
    while (temp != NULL) {
        temp = temp->next;
        count++;
    }
    del_ptr = head;
    if (count >= position && position != FAILURE) {
        while (prev_loc < position-2) {
            del_ptr = del_ptr->next;
            prev_loc++;
        }
        previous = del_ptr->prev;
        next_element = del_ptr->next;
        previous->next =next_element;
        next_element->prev = previous;
        free(del_ptr);
    }
    else if (position == 0) {
        delete_start();
    }
    else if (count == position) {
        delete_end();
    }
    else {
        printf("\nSorry!There are only %d elements in the list",count);
    }
    free(temp);
    free(previous);
    free(next_element);
}
