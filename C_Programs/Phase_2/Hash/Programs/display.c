/**
 * @file            : display.c
 * @brief           : This program will get the MAC id from the user and does
 *                    insertion or deletion or searching or displaying of the
 *                    MAC id in the hash table based on the user input
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013, VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */

#include"Hash.h"

/**
 * @function : display
 * @param    : hash table
 * @brief    : This function will display the MAC id stored in the hash table
 * @caller   : hash main function
 */
void display(int (*hash)[MAC_SIZE])
{
    int loop, iter;

    printf("The MAC id in the hash table is as follows and the position which "\
            "is not occupied is represented by all zeros.\n");
    for (iter = 0;iter < HASH_SIZE;iter++) {
        printf("Position %d : ", iter);
        if ((hash[iter][0] == INT_MIN) || (hash[iter][0] == INT_MAX)) {
            printf("00:00:00:00:00:00\n");
        }
        else {
            for (loop = 0;loop < MAC_SIZE - 1;loop++) {
                printf("%x:", hash[iter][loop]);
            }
            printf("%x\n", hash[iter][5]);
        }
    }
}
