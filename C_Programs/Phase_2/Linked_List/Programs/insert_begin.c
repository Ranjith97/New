/**
 * @file            : insert_begin.c
 * @brief           :
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013 , VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */

#include"List.h"

/**
 * @function       : insert_begin
 * @brief          : This function is used to insert element at begining of
 *                   linked list.
 * @caller         : list main function
 */
void insert_begin() {
    new_node = (employee_t*)calloc(1, sizeof(employee_t));
    details = new_node;
    /* Element is inserted only when there is no duplicate element already
     * present in the list */
    if (input(head) != FAILURE) {
        /*If no node is present*/
        if (head == NULL) {
            new_node->prev = NULL;
            new_node->next = NULL;
            head = new_node;
        }
        else {
            new_node->prev = NULL;
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }
}
