/**
 * @file            : output.c
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
 * @function       : output
 * @brief          : This function will display the employee details as required
 *                   by the user
 * @caller         : main
 */

void output()
{
    int option;

    option = 0;

    /* Asking the user which operation is to be performed */
    printf("Enter the operation to be performed choosing from the following"   \
           " list.\n");
    printf("1. Complete details\n2. Details by name\n3. Details by ID\n"       \
           "4. Details by domain\n5. Details by experience\n");
    option = option_valid();
    switch(option)
    {
        case 1:
            for (iterator = 0;iterator < number;iterator++) {
                printf("The details of the employees %d is:\n", iterator + 1);
                printf("The name of the employee is : %s\n",
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
            }
            break;
        case 2:
            display_name();
            break;
        case 3:
            display_id();
            break;
        case 4:
            display_domain();
            break;
        case 5:
            display_experience();
            break;
    }
}
