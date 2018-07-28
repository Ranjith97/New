/**
 * @file            : Hash.c
 * @brief           :
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

    printf("The size of the hash table is SIZE.\n");
    printf("The hash function is HFN\n");
    for (iter = 0;iter < SIZE;iter++) {
        hash[iter]=INT_MIN;
    }
    do{
        printf("Enter your choice\n");
        printf("1-> Insert\n2-> Delete\n3-> Display\n4-> Searching\n" \
               "0-> Exit\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                insert(hash);
                break;
            case 2:
                del(hash);
                break;
            case 3:
                display(hash);
                break;
            case 4:
                search(hash);
                break;
            default:
                if(choice != SUCCESS) {
                    printf("Enter correct choice\n");
                    break;
                }
        }
    }while(choice);

    return 0;
}
