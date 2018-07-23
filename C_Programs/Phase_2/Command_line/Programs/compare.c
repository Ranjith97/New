/**
 * @file            : compare.c
 * @brief           : This program will get command line arguments as input and
 *                    do the functions as entered by the user
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013 , VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */

#include"Command_line.h"

/**
 * @function : compare
 * @param1   : first string
 * @param2   : second string
 * @brief    : This function will compare the two given input strings and tells
 *             whether they are equal or not
 * @caller   : main
 */
void compare(char *str1, char *str2)
{
    int flag;

    flag = 1;
    for (iter = 0;((str1[iter] != NULL_CHARACTER) && \
        (str2[iter] != NULL_CHARACTER));iter++) {
        if ((str1[iter] - str2[iter]) != SUCCESS) {
            printf("The 2 strings are not equal.\n");
            flag = 0;
            exit(FAILURE);
        }
    }
    if (flag == TRUE) {
        printf("The 2 strings are equal.\n");
    }
}
