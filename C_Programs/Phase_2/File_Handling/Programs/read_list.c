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

    temp = malloc(sizeof(linked_t));
    temp = head;
    flag = 1;
    fp = fopen("tcpserver.txt", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error opening file.\n");
        exit(FAILURE);
    }
    while(fread(temp, sizeof(linked_t), 1, fp)) {
   // int t1 = (fread(&temp, sizeof(linked_t), 1, fp));
 //   printf("%d\n", t1);
    printf("%s\n",temp->uuid);
          printf("%d\n",temp->server_port);
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
