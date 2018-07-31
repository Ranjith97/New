/**
 * @file            : input.c
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
 * @function       : input
 * @brief          : This function will get the employee details from the user
 *                   for the given number of entries
 * @caller         : main
 */
int input(employee_t *head)
{
    int choice, time = 0;
    employee_t *temp = NULL, *temp1 = NULL, *temp2 = NULL;

    choice = 0;

    if(time == 0) {
        while(getchar() != '\n');
        time = 1;
    }
    /* Getting the details of the employee from the user */
    printf("Enter the details of employee.\n");
    printf("Enter the employee name.\n");
    name_valid();
    printf("Enter the ID of the employee.\n");
    details->id = integer_valid();

    while (head != NULL) {
        temp = head;
        while(temp)
        {
            temp1 = temp->next;
            while(temp1)
            {
                temp2 = temp1;
                temp1 = temp1->next;
                if(temp->id == temp2->id) {
                    printf("There is already an element with this id.\n");
                    return FAILURE;
                }
            }
            temp = temp->next;
        }
    }
    free(temp);
    free(temp1);
    free(temp2);
    printf("Enter the date of birth in DD/MM/YY format and the year must"  \
            " be within 1960 and 1998.\n");
    DOB_valid();
    printf("Enter the experience of the employee.\n");
    details->experience = integer_valid();
    printf("Enter the domain name like \n1. SW\n2. HW\n3. QA\n");
    choice = domain_valid();
    details->domain = (char *) calloc(1, 2 * sizeof(char));
    switch(choice)
    {
        case 1:strcpy(details->domain, "SW");
               break;
        case 2:strcpy(details->domain, "HW");
               break;
        case 3:strcpy(details->domain, "QA");
               break;
    }
    return TRUE;
}
