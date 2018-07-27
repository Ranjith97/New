/**
 * @file            : add_list.c
 * @brief           :
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
 */
void add_list(char* id, char* tcp_name, char* ip_address, int port)
{
    temp = NULL;
    new_node = NULL;
    uid[0] = '\0';

    new_node = calloc(1, sizeof(linked_t));
    temp = calloc(1, sizeof(linked_t));
    if (new_node == NULL)
    {
        printf("Failed to insert element. Out of memory");
        free(temp);
        free(new_node);
        exit(FAILURE);
    }
    new_node->server_port = port;
    new_node->uuid = (char*)calloc(1, (strlen(id) + 1)*sizeof(char));
    strcpy(new_node->uuid, id);
    new_node->name = (char*)calloc(1, (strlen(tcp_name) + 1)*sizeof(char));
    strcpy(new_node->name, tcp_name);
    new_node->ip = (char*)calloc(1, (strlen(ip_address) + 1)*sizeof(char));
    strcpy(new_node->ip, ip_address);

    fp=fopen("tcpserver.txt", "a+");
    if (fp == NULL) {
        fprintf(stderr,"Error opening file.\n");
        free(temp);
        free(new_node);
        exit(FAILURE);
    }
    /* Checking if the new entry is already present in the list or not */
    if (fgets(str, STR_LENGTH, fp) == SUCCESS) return;
    while(fgets(str, STR_LENGTH, fp) != SUCCESS) {
        sscanf(str,"uuid = %s\n",uid);
        temp->uuid = (char*)calloc(1, (strlen(uid) + 1)*sizeof(char*));
        strcpy(temp->uuid, uid);
        if(strcmp(temp->uuid, new_node->uuid) == SUCCESS) {
            printf("There is already an element with this uuid.\n");
            free(temp);
            free(new_node);
            exit(FAILURE);
        }
    }
    /* Writing the given entry to the file */
    fprintf(fp, "uuid = %s name = %s ip = %s port = %d\n", new_node->uuid,
            new_node->name, new_node->ip, new_node->server_port);
    fclose(fp);
    printf("The entry is added to the file correctly.\n");
    free(temp);
    free(new_node);
}
