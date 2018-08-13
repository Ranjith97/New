/**
 * @file            : delete_position.c
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
 * @function : delete_position
 * @param1   : position
 * @brief    : This function will delete element at a particular position
 * @caller   : delete_id
 */
void delete_position(int position) {
    employee_t *temp = head;
    employee_t *del_ptr = head;
    int prev_loc = 0, count = 0;
    /* Counting the number of elements */
    while (temp != NULL) {
        temp = temp->next;
        count++;
    }
    free(temp);
    del_ptr = head;
    if (count > position && position != 1) {
        /* Traversing till the position is reached */
        while (prev_loc < position - 2) {
            del_ptr = del_ptr->next;
            prev_loc++;
        }
        del_ptr->prev->next = del_ptr->next;
        del_ptr->next->prev = del_ptr->prev;
        free(del_ptr);
    }
    else if (position == 1) {
        delete_start();
    }
    else if (count == position) {
        delete_end();
    }
    else {
        printf("\nSorry!There are only %d elements in the list",count);
    }
}
