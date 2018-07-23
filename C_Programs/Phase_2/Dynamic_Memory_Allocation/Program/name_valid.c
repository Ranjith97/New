/**
 * @file            : name_valid.c
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
 * @function       : name_valid
 * @brief          : This function will validate the given name that it must
 *                   have only characters
 * @caller         : input
 */
void name_valid(int iterator)
{
    char buffer[NAME_LENGTH];

    count = 0;
    flag = 1;

    do {
        if (count < COUNT) {
            count++;
            flag = 1;
            scanf("%[^\n]s", buffer);
            for (loop = 0;loop < strlen(buffer);loop++) {
                /* Checking if only character is present in the entered name */
                if (!(isalpha(buffer[loop]))) {
                    printf("Please enter characters only.\n");
                    flag = 0;
                    break;
                }
            }
        }
        else {
            printf("Program is terminated due to repeated false inputs.\n");
            exit(FAILURE);
        }
        while (getchar() != NEWLINE);
    }while (flag == SUCCESS);
    (details+iterator)->name = (char *) malloc(strlen(buffer) * sizeof(char));
    memcpy((details+iterator)->name, &buffer, strlen(buffer));
}


