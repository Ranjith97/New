/**
 * @file            : input.c
 * @brief           : This program will get the employee details from the user
 *                    and creates a database and prompts the user for different
 *                    operations that can be performed.
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013 , VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */

#include"Dynamic_memory_allocation.h"


/**
 * @function       : input
 * @brief          : This function will get the employee details from the user
 *                   for the given number of entries
 * @caller         : main
 */
void input()
{
    int choice;
    details = NULL;

    loop = 0;
    choice = 0;
    flag = 0;

    printf("Enter the number of entries.\n");
    number = integer_valid();
    details = (struct Employee *) malloc(number * sizeof(struct Employee));
    /* Getting the details of the employee from the user */
    for (iterator = 0;iterator < number;iterator++) {
        flag = 1;
        printf("Enter the details of employee %d.\n", iterator + 1);
        printf("Enter the employee name.\n");
        name_valid(iterator);
        printf("Enter the ID of the employee.\n");
        (details+iterator)->id = integer_valid();
        for (loop = 0;loop < iterator;loop++) {
            /* Checking if the entered id is already present in the list */
            if ((details+iterator)->id == (details+loop)->id) {
                printf("There is already an entry with this employee id.\n");
                iterator--;
                flag = 0;
                break;
            }
        }
        if (flag == SUCCESS) {
            continue;
        }
        printf("Enter the date of birth in DD/MM/YY format and the year must"  \
               " be within 1960 and 1998.\n");
        DOB_valid(iterator);
        printf("Enter the experience of the employee.\n");
        (details+iterator)->experience = integer_valid();
        printf("Enter the domain name like \n1. SW\n2. HW\n3. QA\n");
        choice = domain_valid();
        (details+iterator)->domain = (char *) malloc(2 * sizeof(char));
        switch(choice)
        {
            case 1:strcpy((details+iterator)->domain, "SW");
                   break;
            case 2:strcpy((details+iterator)->domain, "HW");
                   break;
            case 3:strcpy((details+iterator)->domain, "QA");
                   break;
        }
    }
}
