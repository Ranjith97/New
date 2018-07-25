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

void add_list(linked_t **head, char* id, char* tcp_name, char* ip_address, \
              int port)
{
    FILE *fp;
    linked_t *temp1, *temp2;

    temp = NULL;
    temp1 = NULL;
    temp2 = NULL;
    new_node = NULL;

	new_node = calloc(1,sizeof(linked_t));
	if (new_node == NULL)
	{
		printf("Failed to insert element. Out of memory");
        exit(FAILURE);
	}
    printf("%s %s %s %d\n", id, tcp_name, ip_address, port);
    new_node->server_port = port;
    new_node->uuid = (char*)calloc(1, (strlen(id) + 1)*sizeof(char));
    //new_node->uuid = strdup(id);
    strcpy(new_node->uuid, id);
    new_node->name = (char*)calloc(1, (strlen(tcp_name) + 1)*sizeof(char));
    //new_node->name = strdup(tcp_name);
    strcpy(new_node->name, tcp_name);
    new_node->ip = (char*)calloc(1, (strlen(ip_address) + 1)*sizeof(char));
    //new_node->ip = strdup(ip_address);
    strcpy(new_node->ip, ip_address);
    new_node->next = *head;
    *head = new_node;

    if (head == NULL) return;
    temp = *head;
    while(temp)
    {
        temp1 = temp->next;
        while(temp1)
        {
            temp2 = temp1;
            temp1 = temp1->next;
            if(strcmp(temp->uuid, temp2->uuid) == SUCCESS) {
                printf("There is already an element with this uuid.\n");
                exit(FAILURE);
            }
        }
        temp = temp->next;
    }

    loop = *head;
    fp=fopen("tcpserver.txt", "a");
    /*while(loop) {
        fwrite(head, sizeof(linked_t), 1, fp);
        loop = loop->next;
        } */
    for (; new_node != NULL; new_node = new_node->next) {
        fprintf(fp, "uuid = %s name = %s ip = %s port no = %d\n", new_node->uuid,
                new_node->name, new_node->ip, new_node->server_port);
    }
    fclose(fp);
    printf("The list is entered correctly.\n");
}
