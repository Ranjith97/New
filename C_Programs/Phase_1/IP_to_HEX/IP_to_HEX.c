/* *
 * @file         : IP_to_HEX.c
 * @brief        : Get an IP address (dotted format) from the user,
 *                 store and print it in 4 byte HEX format.
 * @author       : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c) : 2012-2013 , VVDN Technologies Pvt. Ltd. Permission is hereby
 *                 granted to everyone in VVDN Technologies to use the Software
 *                 without restriction, including without limitation the rights
 *                 to use, copy, modify, merge, publish, distribute, distribute
 *                 with modifications.
 */

#include<stdio.h>
#include<stdlib.h>

#define NEWLINE '\n'
#define ARRAY_SIZE 15
#define COUNT 3
#define PERIOD '.'
#define NUM_MIN '0'
#define NUM_MAX '9'
#define PERIOD_COUNT 3
#define TRUE 1
#define NULL_CHARACTER '\0'
#define MAC_MIN 0
#define MAC_MAX 255
#define SUCCESS 0
#define FAILURE 0

int main()

{
    char ip_address[ARRAY_SIZE];
    int count, flag, period_count;
    int first_octet, iterator, second_octet, third_octet, fourth_octet;

    count = 0;
    flag = 0;
    period_count = 0;
    first_octet = 0;
    second_octet = 0;
    third_octet = 0;
    fourth_octet = 0;
    iterator = 0;

    printf("Enter the IP address\n"); /* Asking the user to enter IP address */
    do {
        if (count < COUNT) {
            count++;
            scanf("%15[^\n]", ip_address);
            for (iterator = 0;ip_address[iterator] != NULL_CHARACTER; \
                iterator++) {
                if (!(((ip_address[iterator] >= NUM_MIN) && \
                      (ip_address[iterator] <= NUM_MAX)) || \
                      ((ip_address[iterator] == PERIOD) && \
                       (ip_address[0] != NUM_MIN)))) {
                    flag = 1;
                    break;
                }
                if (ip_address[iterator] == PERIOD) {
                    if (ip_address[iterator+1] == PERIOD){
                        flag = 0;
                    }
                    else {
                    period_count++; /* Counts the number of dots */
                    }
                }
            }
            if (flag == TRUE) {
                printf("Enter the IP address correctly.\n");
                flag = 1;
            }
            else if (period_count != PERIOD_COUNT) {
                printf("Malligned IP address.\n");
                flag = 1;
            }
            else {
                sscanf(ip_address,"%d.%d.%d.%d", &first_octet, &second_octet, \
                      &third_octet, &fourth_octet);
                /* Checks if IP address is valid */
                if((first_octet >= MAC_MIN && first_octet <= MAC_MAX) && \
                   (second_octet >= MAC_MIN && second_octet <= MAC_MAX) && \
                   (third_octet >= MAC_MIN && third_octet <= MAC_MAX) && \
                   (fourth_octet >= MAC_MIN && fourth_octet <= MAC_MAX)) {
                    printf("The IP address %d.%d.%d.%d in 4 byte ",first_octet, \
                            second_octet, third_octet, fourth_octet);
                    printf("HEX format is %x.%x.%x.%x \n", first_octet, \
                            second_octet, third_octet, fourth_octet);
                }
                else {
                    printf("Invalid IP address\n");
                    flag = 0;
                }
            }
        }
        else {
            printf("Program is terminated due to repeated false inputs.\n");
            exit(FAILURE);
        }
        while (getchar() != NEWLINE);
    }while (flag == SUCCESS);
    return SUCCESS;
}
