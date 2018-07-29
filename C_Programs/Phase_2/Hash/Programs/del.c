/**
 * @file            : del.c
 * @brief           : This program will get the MAC id from the user and does
 *                    insertion or deletion or searching of the MAC id in the
 *                    hash table based on the user input
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
void del(long int *hash)
{
    num = 0;
    check = 0;
    flag = 0;

    do {
        flag = 0;
        printf("Enter MAC address to delete :");
        check = scanf("%2x:%2x:%2x:%2x:%2x:%2x%c", &mac[0], &mac[1], &mac[2],
                &mac[3], &mac[4], &mac[5], &valid);
        if ((check == 7) && (valid == '\n') && (mac[0] >= 0) && (mac[1] >= 0) &&
                (mac[2] >= 0) && (mac[3] >= 0) && (mac[4] >= 0) && \
                (mac[5] >= 0)) {
            flag = 1;
            break;
        }
        else {
            printf("The entered MAC id is not correct.\n");
        }
        while (getchar() != '\n');
    }while (flag == SUCCESS);
        temp = (char*)calloc(1, 12 * sizeof(char*));
        for (iter = 0;iter < MAC_SIZE;iter++) {
		sprintf(arr, "%x", mac[iter]);
		strcat(temp, arr);
	}
	sscanf(temp, "%ld", &mac_num);
    free(temp);
    element = mac[0] + mac[5];
    pos = element % HFN;
    while (num++ != SIZE) {
		if (hash[pos] == INT_MIN) {
			printf("Element not found in hash table.\n\n");
			break;
		}
		else if (hash[pos] == mac_num) {
			hash[pos] = INT_MAX;
			printf("Element deleted.\n\n");
			break;
		}
		else {
			pos = (pos+1) % HFN;
		}
    }
	if(--num == SIZE) {
		printf("Element not found in hash table.\n\n");
    }
}
