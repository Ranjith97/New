/**
 * @file            : search.c
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
 * @function : search
 * @param1   : hash table
 * @brief    : This function will search for the MAC in the hash table and
 *             prints the MAC if it is present in the table
 * @caller   : hash main function
 */
void search(int (*hash)[MAC_SIZE])
{
	int count = 0, count_delim = 0, flag, num = 0, check = 0, mac[MAC_SIZE],\
                pos, element, iter;
	char buffer[MACID_SIZE];

	do {
		check = 0;
        count = 0;
        count_delim = 0;
		printf("Enter MAC address to be searched: ");
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
                if (flag == MAC_SIZE) {
                    printf("Element found at index %d\n\n", pos);
                    break;
                }
                /* Traversing to next position if the entered MAC is not found
                 * at present position */
                else if ((hash[pos][0] == INT_MAX) || \
                        (hash[pos][0] != INT_MIN)) {
                    pos = (pos+1) % HASH_SIZE;
                }
            }
            if (--num == HASH_SIZE) {
                printf("Element not found in hash table\n\n");
            }
}
