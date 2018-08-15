/**
 * @file            : Dynamic_memory_allocation.c
 * @brief           : This program will get the employee details from the user
 *                    and creates a database and prompts the user for different
 *                    operations that can be performed.
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013 , VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */

#include"Dynamic_memory_allocation.h"

int main()
{
    input();
    output();
    free(details->domain);
    free(details->DOB);
    free(details->name);
    free(details);
    return SUCCESS;
}



