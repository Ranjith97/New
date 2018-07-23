/**
 * @file            : display_id.c
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
 * @function : display_id
 * @brief    : This function will get experience and checks if any of the
               employees are with more than that experience and displays the
               details of those employees only
 * @caller   : output
 */
void display_id()
{
    int input;

    input = 0;
    flag = 0;

    printf("Enter the ID of employee whom the details is to be displayed.\n");
    scanf("%d", &input);
    for (iterator = 0;iterator < number;iterator++) {
        flag = 1;
        /* Checking with the given id of the employee with the list already
         * present */
        if (input == (details+iterator)->id) {
            printf("The details of the employee with id %d are\n", \
                    (details+iterator)->id);
            printf("Name : %s\n", (details+iterator)->name);
            printf("The DOB of the employee is : %d/%d/19%d\n",              \
                   (details+iterator)->DOB[0], (details+iterator)->DOB[1], \
                   (details+iterator)->DOB[2]);
            printf("The experience of the employee is %d\n",               \
                   (details+iterator)->experience);
            printf("The domain of the employee is %s\n",                   \
                   (details+iterator)->domain);
            flag = 0;
            break;
        }
    }
    if (flag != SUCCESS) {
        /* Displaying the error message as there is no employee with the given
         * id in the list */
        printf("The id entered is not present in the structure.\n");
        exit(FAILURE);
    }
}


