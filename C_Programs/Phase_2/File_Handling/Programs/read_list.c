/**
 * @file            : read_list.c
 * @brief           :
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013 , VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */
#include"File_handling.h"

void read_list(linked_t *head, char *ip_address, int port)
{
    FILE *fp;
    char id[50], tcp_name[10], ip1[20], str[100];
    int port1;

    temp = malloc(sizeof(linked_t));
    temp = head;
    flag = 1;
    fp = fopen("tcpserver.txt", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error opening file.\n");
        exit(FAILURE);
    }
    while(fgets(str,100,fp) != 0) {
        sscanf(str,"uuid = %s name = %s ip = %s port no = %d\n", id, tcp_name,
                ip1, &port1);
        temp->server_port = port1;
        temp->uuid = (char*) calloc(1, (strlen(id) + 1) * sizeof(char*));
        strcpy(temp->uuid, id);
        temp->name = (char*) calloc(1, (strlen(tcp_name) + 1) * sizeof(char*));
        strcpy(temp->name, tcp_name);
        temp->ip = (char*) calloc(1, (strlen(ip1) + 1) * sizeof(char*));
        strcpy(temp->ip, ip1);
        if ((strcmp(temp->ip, ip_address) == SUCCESS) && \
                (temp->server_port == port)) {
            printf("UUID = %s\nName = %s\nIP address = %s\nServer port = %d\n",\
                    temp->uuid, temp->name, temp->ip, temp->server_port);
            flag = 0;
        }
    }
    if (flag != SUCCESS) {
        printf("There is no such data present in the list.\n");
        exit(FAILURE);
    }
    fclose(fp);
}
