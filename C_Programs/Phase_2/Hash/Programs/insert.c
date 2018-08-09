/**
 * @file            : insert.c
 * @brief           : This program will get the MAC id from the user and does
 *                    insertion or deletion or searching of the MAC id in the
 *                    hash table based on the user input
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013 , VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */

#include"Hash.h"

/**
 * @function : insert
 * @param1   : hash table
 * @brief    : This function will insert the MAC to the hash table based on the
 *             hash function and linear probing method
 * @caller   : hash main function
 */
void insert(long int *hash)
{
    int count = 0, count1 = 0;
    char buffer[MACID_SIZE];

    num = 0;
    check = 0;

    do {
        check = 0;
        printf("Enter MAC address to be added: ");
        scanf("%s", buffer);
        for (iter = 0;buffer[iter] != '\0';iter++) {
            if (isxdigit(buffer[iter]) != FAILURE) {
                count++;
            }
            else if ((buffer[iter] == ':') || (buffer[iter] == '-')) {
                if ((iter == 2) || (iter == 5) || (iter == 8) || (iter == 11) ||
                        (iter == 14)) {
                    count1++;
                }
            }
        }
        if ((count != 12) && (count1 != 5)) {
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
            temp = (char*) calloc(1, 12 * sizeof(char));
            /* Converting the mac array to string */
            for (iter = 0;iter < MAC_SIZE;iter++) {
                sprintf(arr, "%x", mac[iter]);
                strcat(temp, arr);
            }
            sscanf(temp, "%ld", &mac_num);
            element = mac[0] + mac[5];
            free(temp);
            pos = element % HFN; /* Hash function */
            while (hash[pos] != INT_MIN) {
                if (hash[pos] == INT_MAX) {/* This indicaes the cell is empty */
                    break;
                }
                pos = (pos + 1) % HFN;
                num++;
                if (num == SIZE) { /* This indiactes the table is full */
                    break;
                }
            }
            if(num == SIZE) {
                printf("Hash table was full of elements\nNo Place to insert " \
                        "this element\n\n");
            }
            else { /* Inserting the element */
                hash[pos] = mac_num;
                printf("The MAC is inserted successfully.\n\n");
            }
}
