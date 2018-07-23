/**
 * @file            : Callback.c
 * @brief           : Write a program that will find the sum, minimum, maximum
 *                    values from a given input set of integers(variable number
 *                    of inputs) using callback functions.
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013 , VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */

#include<stdio.h>

#define ARRAY_SIZE 20
#define SUCCESS 0
#define NEWLINE '\n'
#define SPACE ' '
#define CHECK_LENGTH 2

/* Declaring the needed functions */
void sum (int *array, int number);
void minimum (int *array, int number);
void maximum (int *array, int number);
void callback (void (*function)(int *array, int number),int *array, int number);
int valid();

int main()
{
    int number, array[ARRAY_SIZE], iterator;

    number = 0;
    iterator = 0;

    printf("Enter the number of elements.\n");
    number = valid(); /* Validating the array size */
    printf("Enter the elements.\n");
    for (iterator = 0;iterator < number;iterator++) {
        array[iterator] = valid(); /* Validating the elements of the array */
    }
    /* Calling the funnctions from main */
    callback(sum, array, number);
    callback(minimum, array, number);
    callback(maximum, array, number);

    return SUCCESS;
}

/**
 * @function    : valid
 * @brief       : This function checks if the entered number is integer or not
 *                and returns the number if it as an integer.
 * @caller      : main
 */
int valid()
{
    int count,number,flag;
    char valid;

    count = 0;
    flag = 1;
    number = 0;

    do {
        count=scanf("%d%c", &number, &valid);
        if ((count != CHECK_LENGTH) || ((valid != NEWLINE) &&
            (valid != SPACE))) {
            printf("Invalid input.\n"); /* Checking if integer is entered or
                                           not */
            printf("Enter the input again.\n");
            flag = 0;
        }
        else {
            break;
        }
        while(getchar() != NEWLINE);
    }while (flag == SUCCESS);
    return number;
}

/**
 * @function    : callback
 * @param1      : function pointer
 * @param2      : input array
 * @param3      : number of elements in the array
 * @brief       : This function takes a function pointer, input array and
 *                number of elements in the array.
 */
void callback (void (*function)(int *array, int number),int *array, int number)
{
    function (array, number);
}

/**
 * @function    : sum
 * @param1      : pointer to the array
 * @param2      : number of elements in the array
 * @brief       : This function finds the sum of the array and returns the
 *                sum of the elements in the array
 * @caller      : main
 */
void sum (int *array, int number)
{
    int iterator, sum;

    iterator = 0;
    sum = 0;

    /* Finding the sum of elements in the array */
    for (iterator = 0;iterator < number;iterator++) {
        sum += array[iterator];
    }
    printf("The sum of the elements in the array is %d.\n",sum);
}

/**
 * @function    : minimum
 * @param1      : pointer to the array
 * @param2      : number of elements in the array
 * @brief       : This function finds the minimum element in the array and
 *                returns it
 * @caller      : main
 */
void minimum (int *array, int number)
{
    int iterator, minimum;

    iterator = 0;
    minimum = array[0];

    /* Finding the min element in the array */
    for (iterator = 0;iterator < number;iterator++) {
        if (minimum > array[iterator]) {
            minimum = array[iterator];
        }
    }
    printf("The minimum value in the array is %d.\n",minimum);
}

/**
 * @function    : maximum
 * @param1      : pointer to the array
 * @param2      : number of elements in the array
 * @brief       : This function finds the maximum element in the array and
 *                returns it
 * @caller      : main
 */
void maximum (int *array, int number)
{
    int iterator, maximum;

    iterator = 0;
    maximum = array[0];

    /* Finding the max element in the array */
    for (iterator = 0;iterator < number;iterator++) {
        if (maximum < array[iterator]) {
            maximum = array[iterator];
        }
    }
    printf("The maximum value in the array is %d.\n",maximum);
}
