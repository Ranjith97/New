/**
 * @file            : read_list.c
 * @brief           : This program will read the input as command line argument
 *                    from the user and add or read or delete the given entries
 *                    into or from a file based on the user input.
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013 , VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */
#include"File_handling.h"

/**
 * @function       : read_list
 * @param1         : ip_address entered by the user
 * @param2         : port number entered by the user
 * @brief          : The function will check if the given ip_address and port
 *                   number is present in the list or not and prints the details
 *                   if the entry is present in the list
 * @caller         : main
 * @return value   : an integer value which shows the status of the function
 */
int read_list(char *ip_address, int port)
{
    FILE *fp;
    int port1 = 0, flag;
    char uid[ID_LENGTH], uname[NAME_LENGTH], ip_addr[IP_LENGTH], \
        str[STR_LENGTH];
    uid[0] = '\0';
    uname[0] = '\0';
    ip_addr[0] = '\0';

    temp = calloc(1,sizeof(linked_t));
    flag = 1;
    fp = fopen("tcpserver.txt", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error opening file.\n");
        fclose(fp);
        return FALSE;
    }
    while(fgets(str, STR_LENGTH, fp) != SUCCESS) {
        sscanf(str,"uuid = %s name = %s ip = %s port = %d\n", uid, uname,
                ip_addr, &port1);
        temp->server_port = port1;
        temp->uuid = (char*) calloc(1, (strlen(uid) + 1) * sizeof(char*));
        strcpy(temp->uuid, uid);
        temp->name = (char*) calloc(1, (strlen(uname) + 1) * sizeof(char*));
        strcpy(temp->name, uname);
        temp->ip = (char*) calloc(1, (strlen(ip_addr) + 1) * sizeof(char*));
        strcpy(temp->ip, ip_addr);
        /* Checking for the given ip_address and port no in the list */
        if ((strcmp(temp->ip, ip_address) == SUCCESS) && \
                (temp->server_port == port)) {
            printf("UUID = %s\nName = %s\nIP address = %s\nServer port = %d\n",\
                    temp->uuid, temp->name, temp->ip, temp->server_port);
            flag = 0;
        }
    }
    if (flag != SUCCESS) {
        printf("There is no such data present in the list.\n");
        free(temp);
        fclose(fp);
        return FALSE;
    }
    fclose(fp);
    free(temp);
    return SUCCESS;
}
