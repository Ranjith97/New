/**
 * @file            : del.c
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
 * @function : del
 * @param1   : hash table
 * @brief    : This function will delete the given MAC from the hash table
 * @caller   : hash main function
 */
void del(int (*hash)[MAC_SIZE])
{
    int count = 0, count_delim = 0, flag, mac[MAC_SIZE], pos, element, iter,\
                num = 0, check = 0;
    char buffer[MACID_SIZE];

    do {
        check = 0;
        count = 0;
        count_delim = 0;
        printf("Enter MAC address to be deleted: ");
        scanf("%s", buffer);
        /* Checking if valid MAC is entered or not */
        for (iter = 0;buffer[iter] != '\0';iter++) {
            if (isxdigit(buffer[iter]) != SUCCESS) {
                count++;
            }
            else if ((buffer[iter] == ':') || (buffer[iter] == '-')) {
                if ((iter == 2) || (iter == 5) || (iter == 8) || (iter == 11) ||
                        (iter == 14)) {
                    count_delim++;
                }
            }
        }
        if ((count != 12) && (count_delim != 5)) {
            printf("The entered MAC id is not correct.\n");
            check = 0;
        }
        else {
            sscanf(buffer, "%2x:%2x:%2x:%2x:%2x:%2x", &mac[0], &mac[1], &mac[2],
                    &mac[3], &mac[4], &mac[5]);
            /* Checking if valid MAC is entered or not */
            if ((mac[0] >= 0) && (mac[1] >= 0) && (mac[2] >= 0) && (mac[3] >= 0)
                    && (mac[4] >= 0) && (mac[5] >= 0)) {
                check = 1;
                break;
            }
            else {
                printf("The entered MAC id is not correct.\n");
                continue;
            }
        }
        while (getchar() != '\n');
    }while (check == SUCCESS);
            element = mac[0] + mac[5];
            pos = element % HASH_SIZE; /* Hash function */
            while (num++ != HASH_SIZE) {
                flag = 0;
                /* Checking if the entered MAC is equal to that present in the
                 * table */
                for (iter = 0;iter < MAC_SIZE;iter++) {
                    if (hash[pos][iter] == mac[iter]) {
                        flag++;
                    }
                    else {
                        break;
                    }
                }
                /* This indicates the table is empty */
                if (hash[pos][0] == INT_MIN) {
                    printf("Element not found in hash table.\n\n");
                    break;
                }
                else if (flag == MAC_SIZE) {
                    for (iter = 0;iter < MAC_SIZE;iter++) {
                        /* This indicates the mac is deleted */
                        hash[pos][iter] = INT_MAX;
                    }
                    printf("Element deleted.\n\n");
                    break;
                }
                else {
                    pos = (pos+1) % HASH_SIZE; /* Progressing to next cell */
                }
            }
            if(--num == HASH_SIZE) {
                printf("Element not found in hash table.\n\n");
            }
}
