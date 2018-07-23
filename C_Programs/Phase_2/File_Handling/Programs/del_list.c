/**
 * @file            : del_list.c
 * @brief           :
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013 , VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */

#include"File_handling.h"

void del_list(linked_t **head, char *tcp_name, char *ip_address, int port)
{
    FILE *fp, *fp1;
    temp = *head;
    flag = 1;
    fp = fopen("tcpserver.txt", "r");
    fp1 = fopen("sample.txt", "a");
    if (fp == NULL)
    {
        fprintf(stderr, "Error opening file.\n");
        exit(FAILURE);
    }
    while(fread(&temp, sizeof(temp), 1, fp)) {
        if ((strcmp(temp->ip, ip_address) == SUCCESS) && \
            (temp->server_port == port) && \
            (strcmp(temp->name, tcp_name) == SUCCESS)) {
            flag = 0;
        }
        else {
            fwrite(&temp, sizeof(linked_t), 1, fp1);
        }
    }
    if (flag == SUCCESS) {
        printf("There is no such data present in the list.\n");
        exit(FAILURE);
    }
    fclose(fp);
    fclose(fp1);
    remove("tcpserver.txt");
    rename("sample.txt", "tcpserver.txt");
    printf("The data is removed successfully.\n");
}
