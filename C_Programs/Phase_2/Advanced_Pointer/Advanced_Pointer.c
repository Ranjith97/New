/**
 * @file            : Advanced_Pointer.c
 * @brief           : This program will get the MAC and IP address from the
 *                    user and create a session key with maximum 15 characters
 *                    which contains first 2 octets of MAC, last two octets of
 *                    IP address and the remaining with pre definned pattern.
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013 , VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAC_ARRAY 6
#define IP_ARRAY 4
#define SUCCESS 0
#define NEWLINE '\n'
#define CHECK_MAC_LENGTH 7
#define CHECK_IP_LENGTH 5
#define COUNT 3
#define NUM_MIN 0
#define NUM_MAX 255
#define FAILURE 0

int *mac_valid();
int *ip_valid();
void concatenate(int *mac, int *ip);

int main()
{
    int *mac, *ip;
    /* Getting the MAC and IP address from the user */
    printf("Enter the MAC address.\n");
    mac = mac_valid(); /* MAC validation function */
    printf("Enter the IP address.\n");
    ip = ip_valid(); /* IP validation function */
    concatenate(mac, ip); /* Function to print the session key */
    return SUCCESS;
}

/**
 * @function : mac_valid
 * @brief    : This function will validate the input MAC ID
 * @caller   : main
 * @return   : returns the mac array with its address
 */
int *mac_valid()
{
    static int mac[MAC_ARRAY];
    int flag, count, check;
    char valid;

    flag = 1;
    count = 0;
    check = 0;

    do {
        if (count < COUNT) {
            count++;
            check=scanf("%2x:%2x:%2x:%2x:%2x:%2x%c", &mac[0], &mac[1],
                    &mac[2], &mac[3], &mac[4], &mac[5], &valid);
            /* Checking if the MAC ID is correctly entered */
            if (!((check == CHECK_MAC_LENGTH) && (valid == NEWLINE))) {
                printf("Invalid input.\n");
                printf("Please enter valid MAC input.\n");
                flag = 0;
            }
            else {
                return mac; /* Returning the MAC address if it's entered
                               correctly */
                break;
            }
        }
        else {
            /* Breaking the program if the user enters MAC wrongly for more than
             * 3 times */
            printf("Program is terminated due to repeated false inputs.\n");
            exit(FAILURE);
        }
        while (getchar() != NEWLINE);
    }while (flag == SUCCESS);
    return SUCCESS;
}

/**
 * @function : ip_valid
 * @brief    : This function will validate the input IP ID
 * @caller   : main
 * @return   : returns the ip array with its address
 */
int *ip_valid()
{
    static int ip[IP_ARRAY];
    int flag, count, check, iterator;
    char valid;

    flag = 1;
    iterator = 0;
    count = 0;
    check = 0;

    do {
        if (count < COUNT) {
            count++;
            flag = 1;
            check = scanf("%d.%d.%d.%d%c", &ip[0], &ip[1], &ip[2], &ip[3],
                    &valid);
            /* Check if the IP address is entered correctly */
            if (!((check == CHECK_IP_LENGTH) && (valid == NEWLINE))) {
                printf("Invalid input.\n");
                printf("Please enter valid IP input.\n");
                flag = 0;
            }
            else {
                flag = 1;
                break;
            }
        }
        else {
            /* Breaking the program if the user enters IP wrongly for more than
             * 3 times */
            printf("Program is terminated due to repeated false inputs.\n");
            exit(FAILURE);
        }
        for (iterator = 0;iterator < IP_ARRAY;iterator++) {
            if (!((ip[iterator] > NUM_MIN) && (ip[iterator] < NUM_MAX))) {
                flag = 0;
                break;
            }
        }
        while (getchar() != NEWLINE);
    }while (flag == SUCCESS);
    return ip; /* Returning the IP address if it's entered correctly */
}

/**
 * @function : concatenate
 * @param1   : mac array
 * @param2   : ip array
 * @brief    : This function will print the session key based on the entered
 *             MAC address and IP address
 * @caller   : main
 */
void concatenate(int *mac, int* ip)
{
    char pattern[7] = "12345";
    printf("The predefined pattern is 12345.\n");
    printf("\nThe session key is %2x%2x%d%d%s.\n", mac[0], mac[1], ip[2],
           ip[3], pattern);
}
