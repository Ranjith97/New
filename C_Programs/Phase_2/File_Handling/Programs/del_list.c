/**
 * @file            : del_list.c
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
 * @function       : del_list
 * @param1         : tcp name
 * @param2         : ip address
 * @param3         : port number
 * @brief          : This function will check if the given entry is present in
 *                   the list or not and deletes that particular entry if it is
 *                   present
 * @caller         : main
 */
void del_list(char *tcp_name, char *ip_address, int port)
{
    FILE *fp1;

    port1 = 0;
    uid[0] = '\0';
    uname[0] = '\0';
    ip_addr[0] = '\0';

    temp = calloc(1, sizeof(linked_t));
    flag = 1;
    fp = fopen("tcpserver.txt", "r");
    fp1 = fopen("sample.txt", "a");
    if (fp == NULL)
    {
        fprintf(stderr, "Error opening file.\n");
        exit(FAILURE);
    }
    /* Checking if the entry is present in the list */
    while(fgets(str, STR_LENGTH, fp) != SUCCESS) {
        sscanf(str,"uuid = %s name = %s ip = %s port = %d\n", uid, uname, \
                ip_addr, &port1);
        temp->uuid = (char*)calloc(1, (strlen(uid) + 1)*sizeof(char*));
        strcpy(temp->uuid, uid);
        temp->name = (char*)calloc(1, (strlen(uname) + 1)*sizeof(char*));
        strcpy(temp->name, uname);
        temp->ip = (char*)calloc(1, (strlen(ip_addr) + 1)*sizeof(char*));
        strcpy(temp->ip, ip_addr);
        temp->server_port = port1;
        if ((strcmp(temp->ip, ip_address) == SUCCESS) && \
                (temp->server_port == port) && \
                (strcmp(temp->name, tcp_name) == SUCCESS)) {
            flag = 0;
        }
        /* Writing the contents of the file which not matches with the entry
         * to another file */
        else {
            fprintf(fp1, "uuid = %s name = %s ip = %s port = %d\n", temp->uuid,\
                    temp->name, temp->ip, temp->server_port);
        }
    }

    if (flag != SUCCESS) {
        printf("There is no such data present in the list.\n");
        fclose(fp);
        fclose(fp1);
        remove("tcpserver.txt");
        rename("sample.txt", "tcpserver.txt");
        free(temp);
        exit(FAILURE);
    }
    fclose(fp);
    fclose(fp1);
    remove("tcpserver.txt");
    rename("sample.txt", "tcpserver.txt");
    printf("The data is removed successfully.\n");
    free(temp);
}
