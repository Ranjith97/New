/**
 * @file            : DOB_valid.c
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
 * @function       : DOB_valid
 * @brief          : This function will check if the given DOB is valid or not
 * @caller         : input function
 */
void DOB_valid()
{
    int buffer[INT_LENGTH];

    count = 0;
    flag = 1;
    check = 0;

    do {
        if (count < COUNT) {
            count++;
            flag = 1;
            check = scanf("%d/%d/%d%c", &buffer[0], &buffer[1], &buffer[2],
                    &valid);
            /* Checking the DOB for valid numbers and years */
            if ((DOB_LENGTH != check) || (valid != NEWLINE) ||            \
                (buffer[0] > DATE_MAX) || (buffer[0] < DOB_MIN) ||        \
                (buffer[1] < DOB_MIN) || (buffer[1] > MONTH_MAX) ||       \
                (buffer[2] < YEAR_MIN) || (buffer[2] > YEAR_MAX)) {
                printf("Invalid Input.\n");
                printf("Enter the correct DOB before 2018.\n");
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
    details->DOB = (int *) malloc(3 * sizeof(int));
    for (loop = 0;loop < INT_LENGTH;loop++) {
        details->DOB[loop] = buffer[loop];
    }
}
