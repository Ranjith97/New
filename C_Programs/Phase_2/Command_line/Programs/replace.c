/**
 * @file            : replace.c
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
 * @function : replace
 * @param1   : first string
 * @param2   : character
 * @param3   : character
 * @brief    : This function will replace str2 with str3 in str1 and prints str1
 * @caller   : main
 */
void replace(char *str1, char str2, char str3)
{
    int flag;

    flag = 1;
    for (iter = 0;str1[iter] != NULL_CHARACTER;iter++) {
        if (str1[iter] == str2) {
            flag = 0;
            break;
        }
    }
    if (flag != SUCCESS) {
        printf("%c is not present in %s\n", str2, str1);
        exit(FAILURE);
    }
    else {
        for (iter = 0;str1[iter] != NULL_CHARACTER;iter++) {
            if (str1[iter] == str2) {
                str1[iter] = str3;
            }
        }
        printf("The replaced string is %s\n", str1);
    }
}
