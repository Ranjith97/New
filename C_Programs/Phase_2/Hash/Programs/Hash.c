/**
 * @file            : Hash.c
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

int main()
{
    long int hash[SIZE];
    int choice;

    printf("The size of the hash table is %d.\n", SIZE);
    printf("The hash function is (first octet+last octet)/%d.\n", HFN);
    for (iter = 0;iter < SIZE;iter++) {
        hash[iter]=INT_MIN;
    }
    do {
        printf("Enter your choice\n");
        printf("1-> Insert\n2-> Delete\n3-> Searching\n0-> Exit\n");
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
            default:
                if (choice != SUCCESS) {
                    printf("Enter correct choice\n");
                    break;
                }
        }
    } while (choice != SUCCESS);

    return SUCCESS;
}
