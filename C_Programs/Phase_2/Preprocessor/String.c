/**
 * @file            : String.c
 * @brief           : This program will find if the given string is alphabetic
 *                    or numeric or alphanumeric or invalid. 
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013 , VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */


#include<stdio.h>
#include<string.h>

#define ARRAY_SIZE 10
#define SUCCESS 0
#define SPACE ' '
#define MIN_ALPHA_LOW 'a'
#define MAX_ALPHA_LOW 'z'
#define MIN_ALPHA_HIGH 'A'
#define MAX_ALPHA_HIGH 'Z'
#define NUM_MIN '0'
#define NUM_MAX '9'
#define NULL_CHARACTER '\0'
#define IS_ALPHA(input) ((((input >= MIN_ALPHA_LOW) &&                   \
                           (input <= MAX_ALPHA_LOW)) ||                  \
                          ((input >= MIN_ALPHA_HIGH) &&                  \
                           (input <= MAX_ALPHA_HIGH)) ||                 \
                           (input == SPACE)) ? 1 : 0)
#define IS_NUMBER(input) ((((input >= NUM_MIN) && (input <= NUM_MAX)) || \
                           (input == SPACE)) ? 1 : 0)

int main()
{
    char string[ARRAY_SIZE];
    int iterator, alpha_count, number_count;

    iterator = 0;
    alpha_count = 0;
    number_count = 0;

    printf("Enter the string within 10 characters.\n");
    scanf("%[^\n]", string);
    if (strlen(string) <= ARRAY_SIZE) {
        /* Passing each character in the string to the macro */
        for (iterator = 0;string[iterator] != NULL_CHARACTER;iterator++) {
            /* Counting the number of characters */
            if (IS_ALPHA(string[iterator])) {
                alpha_count++;
            }
            /* Counting the number of numerics */
            if (IS_NUMBER(string[iterator])) {
                number_count++;
            }
        }
        /* Checking the alphabetic and numerical counts */
        if (alpha_count == strlen(string)) {
            printf("The entered string is alphabetic.\n");
        }
        else if (number_count == strlen(string)) {
            printf("The entered string is numeric.\n");
        }
        else if ((number_count + alpha_count) == strlen(string)) {
            printf("The entered string is alphanumeric.\n");
        }
        else {
            printf("The entered string is invalid.\n");
        }
    }
    /* Printing error when the string size exceeded 10 characters */
    else {
        printf("The string exceeded 10 characters.\n");
    }
    return SUCCESS;
}



