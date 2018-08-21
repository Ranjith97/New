/**
 * @file            : Variable_Argument.c
 * @brief           : 
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013 , VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */
#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>

#define SUCCESS 0
#define FAILURE 0
#define COUNT 3
#define TRUE 1
#define INTEGER 0
#define NUM_MAX 25
#define NEWLINE '\n'
#define SPACE ' '
#define CHECK_LENGTH 2
#define ARRAY_SIZE 25


void input();
void armstrong(int number);
int input_validation();
int element_validation();
int power(int remainder, int count);

int array[ARRAY_SIZE];

int main()
{
    input();
    return SUCCESS;
}

void input()
{
    int number, iterator;

    number = 0;
    iterator = 0;
    printf("Enter the number of elements in the array.\n");
    number = input_validation();
    printf("\nEnter the elements in the array.\n");
    for (iterator = 0;iterator < number;iterator++) {
        array[iterator] = element_validation();
    }
    armstrong(number);
}

int input_validation()
{
    int number, count, check, flag;
    char valid;

    number = 0;
    count = 0;
    check = 0;
    flag = 1;

    do {
        if (count < COUNT) {
            count++;
            flag = 1;
            check = scanf("%d%c", &number, &valid);
            if (check != CHECK_LENGTH && valid != NEWLINE) {
                printf("Enter a valid integer to the input.\n");
                flag = 0;
            }
            else if (number > NUM_MAX) {
                printf("Enter the number within 25.\n");
                flag = 0;
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
    return number;
}

int element_validation()
{
    int number, count, check, flag;
    char valid;

    number = 0;
    count = 0;
    check = 0;
    flag = 1;

    do {
        if (count < COUNT) {
            count++;
            flag = 1;
            check = scanf("%d%c", &number, &valid);
            if (check != CHECK_LENGTH && valid != NEWLINE) {
                printf("Enter a valid integer element.\n");
                flag = 0;
            }
            else if (number <= INTEGER) {
                printf("Enter the number greater than 0.\n");
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

int power(int remainder, int count)
{
    int iterator, result;

    iterator = 0;
    result = 1;

    for (iterator = 0;iterator < count;iterator++) {
        result *= remainder;
    }
    return result;
}

void armstrong(int input)
{
    int iterator, count, flag, number, number1, sum, remainder;

    flag = 0;
    sum = 0;
    iterator = 0;
    number = 0;
    remainder = 0;
    count = 0;
    number1 = 0;

    for (iterator = 0;iterator < input;iterator++) {
        sum = 0;
        number = array[iterator];
        number1 = number;
        count = 0;
        while (number1 != FAILURE) {
            number1 /= 10;
            count++;
        }
        number1 = number;
        while (number != FAILURE) {
            remainder = number % 10;
            sum += power(remainder,count);
            number /= 10;
        }
        if (sum == number1) {
            printf("\n%d is a Armstrong number.\n", sum);
            flag = 1;
        }
    }
    if (flag != TRUE) {
        printf("\nThere are no Armstrong elements in the array.\n");
    }
}
