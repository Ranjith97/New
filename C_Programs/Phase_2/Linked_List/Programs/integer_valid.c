/**
 * @file            : integer_valid.c
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
 * @function       : integer_valid
 * @brief          : This function will check if the given is an integer or not
 *                   and return that integer value
 * @return         : The integer value entered
 * @caller         : input function
 */
int integer_valid()
{
    int input;

    flag = 1;
    input = 0;
    count = 0;
    check = 0;

    do {
        if (count < COUNT) {
            count++;
            check=scanf("%d%c", &input, &valid);
            /* Checks if integer is entered or not */
            if ((check != CHECK_INTEGER_LENGTH) && (valid != NEWLINE) && \
                 (input <= SUCCESS)) {
                printf("Invalid input.\n");
                printf("Please enter valid number.\n");
                flag = 0;
            }
            else {
                break;
            }
        }
        else {
            printf("Program is terminated due to repeated false inputs.\n");
            exit(FAILURE);
        }
        while (getchar() != NEWLINE);
    }while (flag == SUCCESS);
    return input;
}
