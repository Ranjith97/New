/**
 * @file            : name_valid.c
 * @brief           :
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
    details->name = (char *) malloc(strlen(buffer) * sizeof(char));
    memcpy(details->name, &buffer, strlen(buffer));
}
