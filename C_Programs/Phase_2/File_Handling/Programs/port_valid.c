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
    int port_no = 0, flag = 1, iter;

    for (iter = 0;port[iter] != NULL_CHARACTER;iter++) {
        if (!(isalpha(port[iter]) == SUCCESS)) {
            return FALSE;
        }
        else {
            flag = 0;
        }
    }
    if (flag == SUCCESS) {
        port_no = atoi(port);
        if ((port_no <= PORT_MIN) || (port_no > PORT_MAX)) {
            return FALSE;
        }
        else {
            return SUCCESS;
        }
    }
    else {
        return FALSE;
    }
}


