/**
 * @file            : Union.c
 * @brief           : Write a program to get the N people entries.The structure
 *                    should contain people's's name and any of their mobile
 *                    number or AAadhar number(12 digit). After getting the
 *                    inputs the N entry details should be displayed to the
 *                    user.Use unions.Note: If the user enters only name and
 *                    mobile number only that details has to be shown to the
 *                    user.
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013 , VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SUCCESS 0
#define ARRAY_SIZE 10
#define AADHAR_SIZE 13
#define NAME_LENGTH 20
#define COUNT 3
#define NEWLINE '\n'
#define AADHAR_LENGTH 12
#define MOBILE_LENGTH 10
#define NUM_MAX '9'
#define NUM_MIN '0'
#define FAILURE 0
#define CHECK_LENGTH 2

void structure_union_input();
int number_valid();
int choice_valid();
long int mobile_valid();
void aadhar_valid(int iterator);

/**
 * @union   : choice
 * @brief   : This union is defined to store the mobile number and aadhar
 *            number of the user as entered
 * @members
 *  @mobile : mobile number of the user
 *  @aadhar : aadhar number of the user
 */
union choice {
    long int mobile;
    char aadhar[AADHAR_SIZE];
};

/**
 * @structure   : identity
 * @brief       : This structue is defined to store the people name and flag
 *                to which union members the values must be stored and a union
 * @members
 *  @name       : name of the people
 *  @flag       : flag used to access the union member
 *  @check      : union variable inside the structure
 */
struct identity{
    char name[NAME_LENGTH];
    int flag;
    union choice check;
};
struct identity details[ARRAY_SIZE];

int main()
{
    structure_union_input();
    return SUCCESS;
}

/**
 * @function : structure_union_input
 * @brief    : This function will get and display the structure and union
 *             members
 * @caller   : main
 */
void structure_union_input()
{
    int number, iterator;

    number = 0;
    iterator = 0;
    /* Getting values from the user */
    printf("Enter the number of entries to be stored.\n");
    number = number_valid();
    for (iterator = 1;iterator <= number;iterator++) {
        printf("Enter the name of the people in entry %d.\n",iterator);
        scanf("%[^\n]s",details[iterator].name);
        printf("Enter 1 for mobile number and 2 for aadhar number.\n");
        details[iterator].flag = choice_valid();
        switch(details[iterator].flag) {
            case 1:
                printf("Enter the mobile number.\n");
                details[iterator].check.mobile = mobile_valid();
                break;
            case 2:
                printf("Enter the aadhar number.\n");
                aadhar_valid(iterator);
                getchar();
                break;
        }
    }
    /* Printing the stored values from the user */
    for (iterator = 1;iterator <= number;iterator++) {
        printf("\nThe name of the people in the entry %d is : ",iterator);
        printf("%s\n",details[iterator].name);
        switch(details[iterator].flag) {
            case 1:
                printf("The mobile number in the entry %d is : ",iterator);
                printf("%ld\n",details[iterator].check.mobile);
                break;
            case 2:
                printf("The aadhar number in the entry %d is : ",iterator);
                printf("%s\n",details[iterator].check.aadhar);
                break;
        }
    }
}

/**
 * @function : number_valid
 * @brief    : This function will validate the input number of entries and
 *             returns it
 * @caller   : structure_union_input
 */
int number_valid()
{
    int flag, count, number, check;
    char valid;

    flag = 1;
    number = 0;
    count = 0;
    check = 0;

    do {
        if (count < COUNT) {
            count++;
            check=scanf("%d%c", &number, &valid);
            /* Checks if integer is entered or not */
            if ((check != CHECK_LENGTH) && (valid != NEWLINE) &&
                    number == SUCCESS) {
                printf("Invalid input.\n");
                printf("Please enter valid number of input to the" \
                        "structure.\n");
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
    return number;
}

/**
 * @function : choice_valid
 * @brief    : This function will validate the input choices and
 *             returns it
 * @caller   : structure_union_input
 */
int choice_valid()
{
    int count, flag, check, number;
    char valid;

    flag = 1;
    number = 0;
    count = 0;
    check = 0;

    do {
        if (count < COUNT) {
            count++;
            check=scanf("%d%c", &number, &valid);
            /* Checks if integer entered is 1 or 2 */
            if (((check != CHECK_LENGTH) && (valid != NEWLINE)) || \
                    (number < 0) || (number > 3)) {
                printf("Invalid input.\n");
                printf("Please enter valid choice of input.\n");
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
    return number;
}

/**
 * @function : mobile_valid
 * @brief    : This function will validate the input phone number and returns
 *             it
 * @caller   : structure_union_input
 */
long int mobile_valid()
{
    int flag, count, check, number_length;
    long int number, number1;
    char valid;

    flag = 1;
    number_length=0;
    number1 = 1;
    number = 0;
    count = 0;
    check = 0;

    do {
        if (count < COUNT) {
            count++;
            check=scanf("%ld%c", &number, &valid);
            number1 = number;
            /* Checks if integer is entered or not */
            if ((check != CHECK_LENGTH) && (valid != NEWLINE)) {
                printf("Invalid input.\n");
                printf("Please enter valid 10 digit phone number.\n");
                flag = 0;
            }
            else {
                while (number1 != FAILURE) {
                    number1 /= 10;
                    number_length++;
                }
                /* Checking the mobile number length */
                if (number_length != MOBILE_LENGTH) {
                    printf("Invalid input.\n");
                    printf("Please enter valid 10 digit mobile number.\n");
                    flag = 0;
                    number_length = 0;
                    continue;
                }
                else {
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
    return number;
}

/**
 * @function : aadhar_valid
 * @brief    : This function will validate the input aadhar number and returns
 *             it
 * @param1   : loop number
 * @caller   : structure_union_input
 */
void aadhar_valid(int loop)
{
    int count, flag, iterator, aadhar_length, check;

    count = 0;
    check = 1;
    iterator = 0;
    aadhar_length = 0;
    flag = 1;

    do {
        if (count < COUNT) {
            count++;
            scanf("%[^\n]s", details[loop].check.aadhar);
            for (iterator = 0;details[loop].check.aadhar[iterator] != NEWLINE; \
                    iterator++) {
                /* Checking if number is entered or not */
                if (details[loop].check.aadhar[iterator] >= NUM_MIN && \
                        details[loop].check.aadhar[iterator] <= NUM_MAX) {
                    aadhar_length++;
                    check = 1;
                    continue;
                }
                else {
                    check = 0;
                    break;
                }
            }
            /* Checking aadhar number length */
            if ((FAILURE == check) && (aadhar_length != AADHAR_LENGTH)) {
                printf("Invalid input.\n");
                printf("Enter 12 digit valid aadhar number.\n");
                flag = 0;
                aadhar_length = 0;
                continue;
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
}
