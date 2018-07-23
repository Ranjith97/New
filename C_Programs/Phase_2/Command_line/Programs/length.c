/**
 * @file            : length.c
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
 * @function : length
 * @param1   : character array
 * @brief    : This function will return the length of the input string.
 * @caller   : main, reverse, replace, concat
 * @return   : integer value
 */
int length(char *str)
{
    str_len = 0;
    iter = 0;
    for (iter = 0;str[iter] != NULL_CHARACTER;iter++) {
        str_len++;
    }
    return str_len;
}
