/**
 * @file            : display_name.c
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
 * @function       : display_name
 * @brief          : This function will display only the details of the employee
 *                   as required by the user
 * @caller         : output
 */
void display_name()
{
    char check_name[NAME_LENGTH];

    flag = 0;

    printf("Enter the name of employee whom the details is to be displayed.\n");
    scanf("%[^\n]s", check_name);
    for (iterator = 0;iterator < number;iterator++) {
        flag = 1;
        /* Checking if there is employee present in the list */
        if (strcmp((details+iterator)->name, check_name) == SUCCESS) {
            printf("The details of the employee %s are \n", \
                    (details+iterator)->name);
            printf("The DOB of the employee is : %d/%d/19%d\n",              \
                   (details+iterator)->DOB[0], (details+iterator)->DOB[1], \
                   (details+iterator)->DOB[2]);
            printf("The experience of the employee is %d\n",               \
                   (details+iterator)->experience);
            printf("The domain of the employee is %s\n",                   \
                   (details+iterator)->domain);
            printf("The ID of the employee is %d\n",                       \
                   (details+iterator)->id);
            flag = 0;
            break;
        }
    }
    if (flag != SUCCESS) {
        /* Displaying the error message as there is no employee present in the
         * list */
        printf("The name entered is not present in the structure.\n");
        exit(FAILURE);
    }
}
