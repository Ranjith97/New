/**
 * @file            : Saddle_point_ranjith.c
 * @brief           : This program will find the saddle points in an array
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013 , VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */


#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 0
#define FAILURE 0
#define TRUE 1
#define COUNT 3
#define ARRAY_LENGTH 5
#define CHECK_LENGTH 2
#define NEWLINE '\n'
#define SPACE ' '

void input_check();
int element_validation();

int main()
{
    input_check();
    return SUCCESS;
}

void input_check()
{
    int iterator1, iterator2, check, Matrix[ARRAY_LENGTH][ARRAY_LENGTH], \
        flag, row, colomn, iterator3, maximum;

    iterator1 = 0;
    iterator2 = 0;
    check = 0;
    flag = 0;
    row = 0;
    colomn = 0;
    iterator3 = 0;
    maximum = 0;

    printf("Enter the matrix elements.\n");
    for (iterator1 = 0;iterator1 < ARRAY_LENGTH;iterator1++) {
        for (iterator2 = 0;iterator2 < ARRAY_LENGTH;iterator2++) {
            Matrix[iterator1][iterator2] = element_validation();
        }
    }
    for (iterator1 = 0;iterator1 < ARRAY_LENGTH;iterator1++) {
        row = 0;
        colomn = 0;
        for (iterator2 = 0;iterator2 < ARRAY_LENGTH;iterator2++) {
            maximum = Matrix[0][0];
            if (maximum <= Matrix[iterator1][iterator2]) {
                maximum = Matrix[iterator1][iterator2];
                colomn = iterator2;
            }
        }
        flag = 0;
        for (iterator3 = 0;iterator3 < ARRAY_LENGTH;iterator3++) {
            if (maximum > Matrix[iterator3][colomn]) {
                break;
            }
            else if (maximum <= Matrix[iterator3][colomn]){
                flag = 1;
                row = iterator1;
            }
        }
        if (TRUE == flag) {
            printf("The saddle point is in row %d and colomn %d.\n", \
                    row, colomn);
            check = 1;
        }
    }
    if (TRUE != check) {
        printf("There is no saddle point.\n");
    }
}

int element_validation()
{
    int number, count, check, flag;
    char valid;

    number = 0;
    flag = 1;
    count = 0;
    check = 0;

    do {
        if (count < COUNT) {
            count++;
            check = scanf("%d%c", &number, &valid);
            if ((check != CHECK_LENGTH) && ((valid != NEWLINE) ||
                 valid != SPACE)) {
                printf("Invalid input.\n\n");
                printf("Enter the matrix element in integer format.\n");
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
