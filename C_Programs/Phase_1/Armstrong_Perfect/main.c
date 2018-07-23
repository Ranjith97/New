/**
 * @file			: main.c
 * @brief			: This program will check if the number entered by the
 *                    user is armstrong and perfect number.
 * @author			: Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013 , VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */

#include<stdio.h>
#include<stdlib.h>

int Armstrong (int); /* Declaration of Armstrong function */
int Perfect (int); /* Declaration of Perfect function */
int power (int,int); /* Declaration of Power function */

int main()
{
    int number,count=0,check;
    char ch;
    while(1) {
        /* Checking if the number of times loop running is less than 3 */
        if (count < 3) {
            count++;
            printf("Enter the number to be checked.\n");
            check=scanf("%d%c",&number,&ch);
            if (check != 2 && ch != '\n') { /* Checking if number is entered */
                printf("Invalid input.\n");
            }
        else {
            break;
        }
        }
        else {
            printf("Program is terminated due to repeated false inputs.\n");
            exit(0);
        }
        while (getchar() != '\n');
    }
    /* Calling Armstrong function and checking return value */
    if (Armstrong(number)) {
        printf("The number %d is Armstrong number.\n",number);
    }
    else {
        printf("The number %d is not an Armstrong number.\n",number);
    }
    /* Calling Perfect function and checking return value */
    if (Perfect(number)) {
        printf("The number %d is Perfect number.\n",number);
    }
    else {
        printf("The number %d is not a Perfect number.\n",number);
    }

    return 0;
}

int power (int temp,int count)
{
    int i,res=1;
    for (i=0;i<count;i++) { /* For finding temp^count */
        res*=temp;
    }
    return res;
}

int Armstrong (int number)
{
    int sum=0,temp=0,count=0,temp1=number;
    while (number != 0) { /* Finding number of digits in the number */
        count++;
        number/=10;
    }
    number=temp1;
    while (number != 0) { /* Doing the Armstrong number operation */
        temp=number%10;
        sum+=power(temp,count);
        number/=10;
    }
    return (sum == temp1); /* Return 1 if sum=number */
}

int Perfect(int number)
{
    int i,sum=0;
    for (i=1;i<number;i++) { /* Doing the Perfect number operation */
        if (number % i == 0) {
            sum+=i;
        }
    }
    return (sum == number);  /* Return 1 if sum=number */
}
