/**
 * @file            : option_valid.c
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
 * @function       : option_valid
 * @brief          : This function will check if the given option is within the
 *                   given limits
 * @return         : The correct value of option
 * @caller         : input
 */
int option_valid()
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
            /* Checking if the option is entered is within the range */
            if (((check != CHECK_INTEGER_LENGTH) && (valid != NEWLINE)) || \
                    (input < MIN) || (input > OPTION_MAX)) {
                printf("Invalid input.\n");
                printf("Please enter valid option.\n");
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
