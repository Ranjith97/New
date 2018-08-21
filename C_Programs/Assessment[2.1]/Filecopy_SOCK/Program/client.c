/**
 * @file            : client.c
 * @brief           : This program will create a client socket and pass the file
 *                    to copied from the server and copies the file from server
 *                    if the file is present
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2018, VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */

#include<stdio.h>
#include<sys/socket.h>
#include<unistd.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>

#define SUCCESS 0
#define FAILURE -1
#define PORT 8800
#define LENGTH 100

int main ( int argc, char *argv[] )
{
    struct sockaddr_in client;
    int res = 0, filelen;
    FILE *fp;
    char src[10], dest[10], message[10], content[LENGTH];

    if (argc != 3) {
        printf("There is error in passing the arguments.\n");
    }
    memcpy(src, argv[2], strlen(argv[1])); /* Copying source filename */
    memcpy(dest, argv[3], strlen(argv[2])); /* Copying destination filename */
    printf("%s %s\n", src, dest);
    /* Creating socket */
    if((res = socket(AF_INET, SOCK_STREAM, 0))< 0) {
        printf("Socket creation failed.\n");
        exit(FAILURE);
    }
    client.sin_family = AF_INET;
    client.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &client.sin_addr) <= 0) {
        printf("The entered ip address is incorrect.\n");
        exit(FAILURE);
    }
    /* Connecting to the server */
    if (connect(res, (struct sockaddr*) &client, sizeof(client)) < 0) {
        printf("Conncetion to server has failed.\n");
        exit(FAILURE);
    }
    /* Writing the source file name to server */
    write(res, src, htonl(strlen(src)));
    read(res, message, 2);
    if (strcmp(message, "NO") == 0) {
        printf("There is no such file present.\n");
        exit(FAILURE);
    }
    /* Opening destination file to append data from the server */
    if ((fp = fopen(dest, "a")) == NULL) {
        perror("Error opening dest file.\n");
        exit(FAILURE);
    }
    /* Writing the contents to destination file */
    while ((filelen = recv(res, content, LENGTH, 0)) > 0) {
        fwrite(content, sizeof(char), filelen, fp);
        if ((filelen == 0) || (filelen == LENGTH)) {
            break;
        }
    }
    fclose(fp);
    close(res);
    return SUCCESS;
}
