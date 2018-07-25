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
    char id[50], tcp_name[10], ip1[20];int port1;

    temp = malloc(sizeof(linked_t));
    temp = head;
    flag = 1;
    fp = fopen("tcpserver.txt", "r");
    fseek(fp, SEEK_SET, 0);
    if (fp == NULL)
    {
        fprintf(stderr, "Error opening file.\n");
        exit(FAILURE);
    }
    //while(fread(temp, sizeof(linked_t), 1, fp)) {
    while(fscanf(fp, "uuid = %s name = %s ip = %s port no = %d\n", id, tcp_name, ip1, &port1)) {
        if (feof(fp)) {
            printf("%s %s %s %d\n", id, tcp_name, ip1, port1);
            if ((strcmp(ip1, ip_address) == SUCCESS) && \
                    (port1 == port)) {
                printf("UUID = %s\nName = %s\nIP address = %s\nServer port = %d\n",\
                        id, tcp_name, ip1, port1);
                flag = 0;
            }
        }
    }
    if (flag != SUCCESS) {
        printf("There is no such data present in the list.\n");
        exit(FAILURE);
    }
    fclose(fp);
}
