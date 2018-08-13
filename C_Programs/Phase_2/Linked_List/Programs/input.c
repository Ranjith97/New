/**
 * @file            : input.c
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
 * @function       : input
 * @param1         : address of head
 * @brief          : This function will get the employee details from the user
 * @caller         : main
 */
int input(employee_t *head)
{
    int time = 0, choice = 0;
    employee_t *temp = head, *new_node = head;

    if(time == 0) {
        while(getchar() != '\n');
        time = 1;
    }
    /* Getting the details of the employee from the user */
    printf("Enter the details of employee.\n");
    printf("Enter the employee name : ");
    name_valid();
    printf("Enter the ID of the employee : ");
    new_node->id = integer_valid();

    while (temp != NULL) {
        if (new_node->id == temp->id) {
            printf("There is already an element with given id in the list.\n");
            return FAILURE;
        }
        temp = temp->next;
    }
    free(temp);
    printf("Enter the date of birth in DD/MM/YY format and the year must"  \
            " be within 1960 and 1998 : ");
    DOB_valid();
    printf("Enter the experience of the employee : ");
    new_node->experience = integer_valid();
    printf("Enter the domain name like \n1. SW\n2. HW\n3. QA\n");
    choice = domain_valid();
    new_node->domain = (char *) calloc(1, 2 * sizeof(char));
    switch(choice)
    {
        case 1:strcpy(new_node->domain, "SW");
               break;
        case 2:strcpy(new_node->domain, "HW");
               break;
        case 3:strcpy(new_node->domain, "QA");
               break;
    }
    return TRUE;
}
