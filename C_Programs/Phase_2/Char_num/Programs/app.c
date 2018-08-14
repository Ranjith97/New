/**
 * @file            : app.c
 * @brief           : This program will pass 2 numbers from user app to module
 *                    and receives the result of addition, subtraction,
 *                    multiplication and division of those numbers from module
 *                    to user app
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013 , VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<ctype.h>
#include<stdlib.h>
#include<fcntl.h>

#define BUF_SIZE 100
#define NUM_SIZE 2
#define SUCCESS 0
#define FALSE -1

int main()
{
    int fd, iter, digit = 0;
    char number[BUF_SIZE], num[BUF_SIZE];

    memset(number, '\0', BUF_SIZE);
    memset(num, '\0', BUF_SIZE);
    fd = open("/dev/mydriver", O_RDWR); /* Opening the driver file */

    for (iter = 0;iter < NUM_SIZE;iter++) {
        printf("Enter the number.\n");
        scanf("%s", num);
        digit = atoi(num);
        if ((isdigit(digit) != SUCCESS) || (digit == 0)) {
            printf("The entered character is not a number or it is a zero.\n");
            exit(FALSE);
        }
        strcat(number, num);
        strcat(number, " ");
    }
    write(fd, number, sizeof(number)); /* Writing the string to module */
    memset(number, '\0', BUF_SIZE);
    read(fd, number, sizeof(number)); /* Reading the string from module */
    printf("%s\n", number);
    return SUCCESS;
}
