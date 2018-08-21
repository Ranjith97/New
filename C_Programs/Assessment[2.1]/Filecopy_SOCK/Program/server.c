/**
 * @file            : server.c
 * @brief           : This program acts as a server and gets a filename as input
 *                    and searches for the file in its system and copies the
 *                    file to the client if the file is present or sends an
 *                    error message that the file is not present
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2018, VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */

#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>

#define SUCCESS 0
#define PORT 8800
#define FAILURE -1
#define BUF_SIZE 10
#define LENGTH 100

int main()
{
    struct sockaddr_in server, client;
    int res, client_fd, opt = 1, filelen, clientlen;
    char filename[10], message[10], content[LENGTH];
    FILE *fp;

    /* Creating a socket */
    if ((res = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Socket creation failed.\n");
        exit(FAILURE);
    }
    if (setsockopt(res, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, \
                sizeof(opt))) {
        perror("Setsockopt falied.\n");
        exit(FAILURE);
    }
    server.sin_family = AF_INET;
    server.sin_port = PORT;
    server.sin_addr.s_addr = INADDR_ANY;
    /* Binding the socket with domain, ip, port */
    if (bind(res, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("Bind of socket failed.\n");
        exit(FAILURE);
    }
    /* Creating the listening queue to the server */
    if (listen(res, 1) < 0) {
        perror("Listen falied.\n");
        exit(FAILURE);
    }
    clientlen = sizeof(client);
    /* Accepting the client connection */
    if ((client_fd = accept(res, (struct sockaddr*)&client, \
                (socklen_t*)&clientlen)) < 0) {
        perror("Accept failed.\n");
        exit(FAILURE);
    }
    /* Reading the filename from the client */
    read(client_fd, filename, BUF_SIZE);
    /* Checking if the file is present */
    if ((fp = fopen(filename, "r")) == NULL) {
        strcpy(message, "NO");
        sleep(1);
        write(client_fd, message, strlen(message));
        exit(FAILURE);
    }
    /* Sending the contents of the file to the client */
    while ((filelen = fread(content, sizeof(char), LENGTH,fp)) > 0) {
        if (send(client_fd, content, filelen, 0) < 0) {
            perror("Send failed.\n");
            exit(FAILURE);
        }
        memset(content, '\0', LENGTH);
    }
    fclose(fp);
    close(client_fd);
    return SUCCESS;
}
