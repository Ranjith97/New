/**
 * @file            : display_experience.c
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
 * @function : display_experience
 * @brief    : This function will get experience and checks if any of the
               employees are with more than that experience and displays the
               details of those employees only
 * @caller   : output
 */
void display_experience()
{
    int input;

    flag = 1;
    input = 0;

    printf("Enter the experience of employees above which whom the details is" \
           " to be displayed.\n");
    scanf("%d", &input);
    for (iterator = 0;iterator < number;iterator++) {
        /* Checking if there are employee with experience greater than as
         * entered by the user */
        if ((details+iterator)->experience >= input) {
            printf("The details of the employee with experience greater than"  \
                    " %d are\n", (details+iterator)->experience);
            printf("Name : %s\n", (details+iterator)->name);
            printf("The DOB of the employee is : %d/%d/19%d\n",                  \
                   (details+iterator)->DOB[0], (details+iterator)->DOB[1],     \
                   (details+iterator)->DOB[2]);
            printf("The domain of the employee is %s\n",                       \
                   (details+iterator)->domain);
            printf("The id of the employee is %d\n", (details+iterator)->id);
            flag = 0;
        }
    }
    if (flag != SUCCESS) {
        /* Displaying the error message as there are no employees with
         * experience greater than as entered by the user */
        printf("There is no employee with given experience greater than %d"    \
               " present in the structure.\n", (details+iterator)->experience);
        exit(FAILURE);
    }
}
