/**
 * @file            : ip_valid.c
 * @brief           : This program will read the input as command line argument
 *                    from the user and add or read or delete the given entries
 *                    into or from a file based on the user input.
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013 , VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */
#include"File_handling.h"
int ip_valid(char *ip_address)
{
    int first_octet = 0, second_octet = 0, third_octet = 0, fourth_octet = 0, \
                      period_count = 0;

    for (iter = 0;ip_address[iter] != NULL_CHARACTER;iter++) {
        if (!(((ip_address[iter] >= NUM_MIN) && (ip_address[iter] <= NUM_MAX)) \
                    || ((ip_address[iter] == PERIOD)))) {
            return FALSE;
        }
        if (ip_address[iter] == PERIOD) {
            if (ip_address[iter+1] == PERIOD){
                return FALSE;
            }
            else {
                period_count++; /* Counts the number of dots */
            }
        }
    }
    if (period_count != PERIOD_COUNT) {
        return FALSE;
    }
    else {
        sscanf(ip_address,"%d.%d.%d.%d", &first_octet, &second_octet, \
                &third_octet, &fourth_octet);
        /* Checks if IP address is valid */
        if(!((first_octet >= IP_MIN && first_octet <= IP_MAX) && \
                    (second_octet >= IP_MIN && second_octet <= IP_MAX) && \
                    (third_octet >= IP_MIN && third_octet <= IP_MAX) && \
                    (fourth_octet >= IP_MIN && fourth_octet <= IP_MAX))) {
            return FALSE;
        }
        else {
            return SUCCESS;
        }
    }
    return FALSE;
}
