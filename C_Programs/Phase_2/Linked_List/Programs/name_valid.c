/**
 * @file            : name_valid.c
 * @brief           : This program will create a doubly linked list and do the
 *                    operations like insertion, deletion (both all cases),
 *                    printing in reversed order and displaying the contents
 *                    of the list based upon the user input
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013 , VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */

#include"List.h"

/**
 * @function       : name_valid
 * @brief          : This function will validate the given name that it must
 *                   have only characters
 * @caller         : input function
 */
void name_valid()
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
    new_node->name = (char *) calloc(1, strlen(buffer) * sizeof(char));
    memcpy(new_node->name, &buffer, strlen(buffer));
}
