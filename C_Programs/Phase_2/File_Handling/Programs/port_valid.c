/**
 * @file            : port_valid.c
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

int port_valid(char *port)
{
    int port_no;

    port_no = 0;
    flag = 1;

    for (iter = 0;port[iter] != NULL_CHARACTER;iter++) {
        if (!(isalpha(port[iter]) == SUCCESS)) {
            printf("There is a character in the port number.\n");
            exit(FAILURE);
        }
        else {
            flag = 0;
        }
    }
    if (flag == SUCCESS) {
        port_no = atoi(port);
        if ((port_no <= PORT_MIN) || (port_no > PORT_MAX)) {
            printf("The entered port number is not valid.\n");
            exit(FAILURE);
        }
        else {
            return SUCCESS;
        }
    }
    else {
        return FALSE;
    }
}


