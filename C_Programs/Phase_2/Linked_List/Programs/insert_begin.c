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

void insert_begin() {
    employee_t *new_node = (employee_t*)malloc(sizeof(employee_t));
    details = new_node;
    if (input(head) != FAILURE) {
        /*If no node is present*/
        if(head == NULL) {
            new_node->prev = NULL;
            new_node->next = NULL;
            head = new_node;
        } else {
            new_node->prev = NULL;
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }
}
