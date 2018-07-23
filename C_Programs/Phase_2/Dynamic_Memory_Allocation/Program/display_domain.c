/**
 * @file            : display_domain.c
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
 * @function : display_domain
 * @brief    : This function will validate the given name is present in the
               structure or not and displays the details of that employee
 * @caller   : output
 */
void display_domain()
{
    char check_domain[3];

    flag = 1;

    printf("Enter the domain of employees whom the details is to be "
           "displayed.\n");
    scanf("%s", check_domain);
    for (iterator = 0;iterator < number;iterator++) {
        /* Checking for the given domain name mathches with the list */
        if (strcmp((details+iterator)->domain, check_domain) == SUCCESS) {
            printf("The details of the employee with domain %s are\n", \
                    (details+iterator)->domain);
            printf("Name : %s\n", (details+iterator)->name);
            printf("The DOB of the employee is : %d/%d/19%d\n",              \
                   (details+iterator)->DOB[0], (details+iterator)->DOB[1], \
                   (details+iterator)->DOB[2]);
            printf("The experience of the employee is %d\n",               \
                   (details+iterator)->experience);
            printf("The id of the employee is %d\n", (details+iterator)->id);
            flag = 0;
        }
    }
    if (flag != SUCCESS) {
        /* Displaying the error mesaage as there is no employee with the given
         * domain */
        printf("There is no employee with given domain present in the"
                " structure.\n");
        exit(FAILURE);
    }
}



