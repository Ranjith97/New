/**
 * @file            : id_valid.c
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

int id_valid(char* id)
{
    int hyphens[HYPHEN_LENGTH] = {9, 14, 19, 24}, counter, iter;
    char valid;

    if (strlen(id) != UUID_LENGTH) {
        return FALSE;
    }
    for (iter = 0, counter = 0; iter < UUID_LENGTH; iter ++) {
        valid = id[iter];
        if (iter == hyphens[counter] - 1) {
            if (valid != HYPHEN) {
                return FALSE;
            }
            else {
                counter++;
            }
        }
        else {
            if (isxdigit(valid) == SUCCESS) {
                return FALSE;
            }
        }
    }
    return SUCCESS;
}
