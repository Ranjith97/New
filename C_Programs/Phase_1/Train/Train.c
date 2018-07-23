/* *
 * @file            : Train.c
 * @brief           : Write a program to find the speed of the train.
 *                    A train X m long passes a man, running at Y km/hr in the
 *                    same direction in which the train is going, in Z seconds.
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013 , VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */

#include<stdio.h>
#include<stdlib.h>

#define NEWLINE '\n'
#define CHECK 3
#define SPEED 3.6
#define COUNT 3
#define FAILURE 0
#define SUCCESS 0

int main()
{
    int check, count, flag;
    float t_speed, t_length, m_speed, time, r_speed;

    check = 0;
    flag = 0;
    count = 0;
    t_speed = 0;
    r_speed = 0;
    m_speed = 0;
    time = 0;
    t_length = 0;

    do {
        if ( count < COUNT ) {
            count++;
            /* Storing the scanf return value */
            check = scanf(" %f %f %f", &t_length, &m_speed, &time);
            if (check != CHECK) {
                printf("Enter the train length, speed of the man and time "
                        "taken to cross the man correctly.\n");
                flag = 0;
            }
            else {
                flag = 1;
                break;
            }
        }
        else {
            printf ("Program is terminated due to repeated false inputs.\n");
            exit(FAILURE);
        }
        while (getchar() != '\n'); /* Clearing the buffer on loop */
    }while (flag == SUCCESS); /* Checking if scanf return value is equal to 3 */
    r_speed = ( t_length / time ) * SPEED;
    t_speed = r_speed + m_speed; /* Calculating the train speed */
    printf("The speed of the train is %.3f km/hr.\n", t_speed);
    return SUCCESS;
}
