/**
 * @file            : concat.c
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
 * @function : concat
 * @param1   : first string
 * @param2   : second string
 * @brief    : This function will concatenate the 2 input strings and prints it
 * @caller   : main
 */
void concat(char *str1, char *str2)
{
    int loop;

    loop = 0;
    for (iter = 0;str1[iter] != NULL_CHARACTER;iter++);
    str1[iter++] = ' ';
    for (loop = 0;str2[loop] != NULL_CHARACTER;loop++,iter++) {
        str1[iter] = str2[loop];
      //  printf("%c", str1[iter]);
    }
    str1[iter] = '\0';
    printf("The concatenated string is %s\n", str1);
}
