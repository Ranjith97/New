/**
 * @file            : reverse.c
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
 * @function : reverse
 * @param1   : character array
 * @brief    : This function will reverse the input string and print it
 * @caller   : main
 */
void reverse(char *str)
{
    printf("The reversed string is :");
    for (iter = length(str);iter >= FAILURE;iter--) {
        printf("%c", str[iter]);
    }
    printf("\n");
}
