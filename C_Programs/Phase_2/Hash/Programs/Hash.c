/**
 * @file            : Hash.c
 * @brief           : This program will get the MAC id from the user and does
 *                    insertion or deletion or searching or displaing of the
 *                    MAC id in the hash table based on the user input
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013, VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */

#include"Hash.h"

int main()
{
    int hash[HASH_SIZE][MAC_SIZE], choice, loop, iter;

    printf("The size of the hash table is %d.\n", HASH_SIZE);
    printf("The hash function is (first octet+last octet) / %d.\n", HASH_SIZE);
    /* Initializing the hash table with INT_MIN value to show that position is
     * empty*/
    for (iter = 0;iter < HASH_SIZE;iter++) {
        for (loop = 0;loop < MAC_SIZE;loop++) {
            hash[iter][loop]=INT_MIN;
        }
    }
    do {
        printf("Enter your choice\n");
        printf("1->Insert\n2->Delete\n3->Searching\n4->Display\n0->Exit\n");
        /* Getting choice from user */
        scanf("%d",&choice);

        switch(choice){
            case 1:
                insert(hash);
                break;
            case 2:
                del(hash);
                break;
            case 3:
                search(hash);
                break;
            case 4:
                display(hash);
                break;
            default:
                if (choice != SUCCESS) {
                    printf("Enter correct choice\n");
                    break;
                }
        }
        while(getchar() != '\n');
    }while (choice != SUCCESS);
    return SUCCESS;
}
