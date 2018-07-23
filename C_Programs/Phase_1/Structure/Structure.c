/**
 * @file            : Structure.c
 * @brief           : The program will get the details of a network interface
 *                    such as Network interface name(maximum 8 characters),
 *                    SSID(Maximum 32 characters), Secrurity/Authentication
 *                    mode(NONE, WEP, WPA, WPA2), Passphrase(Maximum 64
 *                    characters), Operating channel number in 2.4G band(1-13),
 *                    Interface MAC ID. These details has to obtained for N
 *                    entries and display these entries.
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013 , VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SUCCESS 0
#define ARRAY_SIZE 10
#define COUNT 3
#define FAILURE 0
#define CHECK_MAC_LENGTH 7
#define MAC_ID_LENGTH 6
#define MAC_LENGTH 5
#define PASSPHRASE_LENGTH 64
#define SECURITY_LENGTH 5
#define SSID_LENGTH 32
#define NETWORK_NAME_LENGTH 8
#define NEWLINE '\n'
#define TRUE 1
#define CHECK_LENGTH 2

int mac[ARRAY_SIZE];

int security_valid();
void structure_input();
int number_valid();
int channel_number_valid();
int mac_validation();

/**
 * @structure      : configuration_parameters
 * @brief          : This structure is defined to store the various parameters
 *                   for a network like SSID, security, etc.
 * @members
 *  @network_name  : network name
 *  @SSID          : SSID of the network
 *  @security      : security of the network
 *  @passphrase    : passphrase of the network
 *  @channel       : opearing channel number
 *  @channel_number: interface MAC ID
 */
struct configuration_parameters {
    char network_name[NETWORK_NAME_LENGTH];
    char SSID[SSID_LENGTH];
    char security[SECURITY_LENGTH];
    char passphrase[PASSPHRASE_LENGTH];
    int channel_number;
    int MAC_ID[MAC_ID_LENGTH];
}config[ARRAY_SIZE];

int main()
{
    structure_input();
    return SUCCESS;
}

/**
 * @function : structure_input
 * @brief    : This function will get the structure members as input and print
 *             the members
 * @caller   : main
 */
void structure_input()
{
    int iterator, mac_iterator, number, switchcase;

    number = 0;
    switchcase = 0;
    iterator = 0;
    mac_iterator = 0;

    printf("Enter the number of entries to be stored in the structure.\n");
    number = number_valid();
    /* Asks the user for input configuration parameters */
    for (iterator = 1;iterator <= number;iterator++) {
        printf("Enter the network name of the entry %d.\n",iterator);
        scanf("%[^\n]s",config[iterator].network_name);getchar();
        printf("Enter the SSID of the entry %d.\n",iterator);
        scanf("%[^\n]s",config[iterator].SSID);
        printf("Enter 1 for No security, 2 for WEP security, 3 for WPA"\
                " security and 4 for WPA2 security.\n");
        switchcase = security_valid();
        switch (switchcase) {
            case 1:
                strcpy(config[iterator].security,"NONE");
                break;
            case 2:
                strcpy(config[iterator].security,"WEP");
                break;
            case 3:
                strcpy(config[iterator].security,"WPA");
                break;
            case 4:
                strcpy(config[iterator].security,"WPA2");
                break;
        }
        printf("Enter the passphrase of the entry %d.\n",iterator);
        scanf("%[^\n]s",config[iterator].passphrase);
        printf("Enter the channel number of the entry %d.\n",iterator);
        config[iterator].channel_number = channel_number_valid();
        printf("Enter the interface MAC ID of the entry %d.\n",iterator);
        if (TRUE == mac_validation()) {
            for (mac_iterator = 0;mac_iterator < MAC_ID_LENGTH; \
                    mac_iterator++) {
                config[iterator].MAC_ID[mac_iterator] = mac[mac_iterator];
            }
        }
        printf("\n");
    }
    /* Prints the stored parameters in the structure */
    for (iterator = 1;iterator <= number;iterator++) {
        printf("The network name of the entry %d is :",iterator);
        printf("%s\n",config[iterator].network_name);
        printf("The SSID of the entry %d is :",iterator);
        printf("%s\n",config[iterator].SSID);
        printf("The security of the %d network is :",iterator);
        printf("%s\n",config[iterator].security);
        printf("The passphrase of the entry %d is :",iterator);
        printf("%s\n",config[iterator].passphrase);
        printf("The opearting channel number of the entry %d is :",iterator);
        printf("%d\n",config[iterator].channel_number);
        printf("The MAC ID of the entry %d is :",iterator);
        for (mac_iterator = 0;mac_iterator < MAC_ID_LENGTH; \
                mac_iterator++) {
            if (mac_iterator != MAC_LENGTH) {
                printf("%2x:",config[iterator].MAC_ID[mac_iterator]);
            }
            else {
                printf("%2x",config[iterator].MAC_ID[mac_iterator]);
            }
        }
    }
}

/**
 * @function : security_valid
 * @brief    : This function will validate the given seurity parameter and
 *             return it
 * @caller   : structure_input
 */
int security_valid()
{
    int flag, count, number, check;
    char valid;

    flag = 1;
    number = 0;
    count = 0;
    check = 0;

    do {
        if (count < COUNT) {
            count++;
            check=scanf("%d%c", &number, &valid);
            /* Checking if integer is entered between 1 and 4 */
            if (((check != CHECK_LENGTH) && (valid != NEWLINE)) || \
                    (number < 0) || (number > 5)) {
                printf("Invalid input.\n");
                printf("Please enter valid security input.\n");
                flag = 0;
            }
            else {
                break;
            }
        }
        else {
            printf("Program is terminated due to repeated false inputs.\n");
            exit(FAILURE);
        }
        while (getchar() != NEWLINE);
    }while (flag == SUCCESS);
    return number;
}

/**
 * @function : number_valid
 * @brief    : This function will validate the input number of entries and
 *             returns it
 * @caller   : structure_input
 */
int number_valid()
{
    int flag, count, number, check;
    char valid;

    flag = 1;
    number = 0;
    count = 0;
    check = 0;

    do {
        if (count < COUNT) {
            count++;
            check=scanf("%d%c", &number, &valid);
            /* Checks if integer is entered or not */
            if ((check != CHECK_LENGTH) && (valid != NEWLINE)) {
                printf("Invalid input.\n");
                printf("Please enter valid number of input to the" \
                        "structure.\n");
                flag = 0;
            }
            else {
                break;
            }
        }
        else {
            printf("Program is terminated due to repeated false inputs.\n");
            exit(FAILURE);
        }
        while (getchar() != NEWLINE);
    }while (flag == SUCCESS);
    return number;
}

/**
 * @function : channel_number_valid
 * @brief    : This function will validate the input interface channel number
 *             and returns it
 * @caller   : structure_input
 */
int channel_number_valid()
{
    int flag, count, number, check;
    char valid;

    flag = 1;
    number = 0;
    count = 0;
    check = 0;

    do {
        if (count < COUNT) {
            count++;
            check=scanf("%d%c", &number, &valid);
            /* Checks if integer is entered between 1 and 13 */
            if (((check != CHECK_LENGTH) && (valid != NEWLINE)) || \
                    (number < 0) || (number > 14)) {
                printf("Invalid input.\n");
                printf("Please enter valid channel number.\n");
                flag = 0;
            }
            else {
                break;
            }
        }
        else {
            printf("Program is terminated due to repeated false inputs.\n");
            exit(FAILURE);
        }
        while (getchar() != NEWLINE);
    }while (flag == SUCCESS);
    return number;
}

/**
 * @function : mac_validation
 * @brief    : This function will validate the input MAC ID and returns it
 * @caller   : structure_input
 */
int mac_validation()
{
    int flag, count,  check;
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
            if ((check != CHECK_MAC_LENGTH) || (valid != NEWLINE) || \
                 (mac[0] < FAILURE) || (mac[1] < FAILURE) || \
                 (mac[2] < FAILURE) || (mac[3] < FAILURE) || \
                 (mac[4] < FAILURE) || (mac[5] < FAILURE)) {
                printf("Invalid input.\n");
                printf("Please enter valid MAC input.\n");
                flag = 0;
            }
            else {
                return 1;
                break;
            }
        }
        else {
            printf("Program is terminated due to repeated false inputs.\n");
            exit(FAILURE);
        }
        while (getchar() != NEWLINE);
    }while (flag == SUCCESS);
    return SUCCESS;
}
