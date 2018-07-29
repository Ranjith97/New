/**
 * @file            : insert.c
 * @brief           :
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
    num = 0;
    check = 0;
    flag = 0;

    do {
        check = 0;
        printf("Enter MAC address to be added: ");
        flag = scanf("%2x:%2x:%2x:%2x:%2x:%2x%c", &mac[0], &mac[1], &mac[2],
                &mac[3], &mac[4], &mac[5], &valid);
        if ((flag == 7) && (valid == '\n') && (mac[0] >= 0) && (mac[1] >= 0) \
                && (mac[2] >= 0) && (mac[3] >= 0) && (mac[4] >= 0) && \
                (mac[5] >= 0)) {
            check = 1;
            break;
        }
        else {
            printf("The entered MAC id is not correct.\n");
        }
        while (getchar() != '\n');
    }while (check == SUCCESS);
        temp = (char*) calloc(1, 12 * sizeof(char));
        for (iter = 0;iter < MAC_SIZE;iter++) {
            sprintf(arr, "%x", mac[iter]);
            strcat(temp, arr);
        }
        sscanf(temp, "%ld", &mac_num);
        element = mac[0] + mac[5];
        free(temp);
        pos = element % HFN;
        while (hash[pos] != INT_MIN) {
            if (hash[pos] == INT_MAX) {
                break;
            }
            pos = (pos + 1) % HFN;
            num++;
            if (num == SIZE) {
                break;
            }
        }
        if(num == SIZE) {
            printf("Hash table was full of elements\nNo Place to insert this" \
                    " element\n\n");
        }
        else {
            hash[pos] = mac_num;
            printf("The MAC is inserted successfully.\n\n");
        }
}
