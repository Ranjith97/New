/**
 * @file            : add_list.c
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
 * @function       : add_list
 * @param1         : uuid
 * @param2         : tcp name
 * @param3         : ip address
 * @param4         : port number
 * @brief          : This function will add the uuid, name, ip address and
 *                   server port number to the file and also checks if the
 *                   given entry is already present in the list or not
 * @caller         : main
 * @return value   : an integer value which shows the status of the function
 */
int add_list(char* id, char* tcp_name, char* ip_address, int port)
{
    FILE *fp;
    char uid[ID_LENGTH], str[STR_LENGTH];

    temp = NULL;
    uid[0] = '\0';

    /* Checking if there is already a file present or else it would create the
     * file and then proceeds */
    fp=fopen("tcpserver.txt", "r");
    if (fp == NULL) {
        printf("There is no file called tcpserver.txt so it's creating that"\
                " file and continuing with the program execution.\n\n");
        system("touch tcpserver.txt");
    }
    else {
        fclose(fp);
    }
    fp=fopen("tcpserver.txt", "a+");
    /* Checking if the new entry is already present in the list or not */
    while(fgets(str, STR_LENGTH, fp) != SUCCESS) {
        sscanf(str,"uuid = %s\n",uid);
        if(strcmp(uid, id) == SUCCESS) {
            printf("There is already an element with this uuid.\n");
            fclose(fp);
            return FALSE;
        }
    }
    temp = calloc(1, sizeof(linked_t));
    if (temp == NULL)
    {
        printf("Failed to insert element. Out of memory");
        free(temp);
        fclose(fp);
        return FALSE;
    }
    /* Dynamically allocating memory and copying data from temproary variables
     * to structure member*/
    temp->server_port = port;
    temp->uuid = (char*)calloc(1, (strlen(id) + 1)*sizeof(char));
    strcpy(temp->uuid, id);
    temp->name = (char*)calloc(1, (strlen(tcp_name) + 1)*sizeof(char));
    strcpy(temp->name, tcp_name);
    temp->ip = (char*)calloc(1, (strlen(ip_address) + 1)*sizeof(char));
    strcpy(temp->ip, ip_address);

    /* Writing the given entry to the file */
    fprintf(fp, "uuid = %s name = %s ip = %s port = %d\n", temp->uuid,
            temp->name, temp->ip, temp->server_port);
    fclose(fp);
    printf("The entry is added to the file correctly.\n");
    free(temp);
    return SUCCESS;
}
