/**
 * @file            : Server.c
 * @brief           : This program will create a client which sends message to
					  the server and reads the message from server and print
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013, VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */

#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<pthread.h>
#include<arpa/inet.h>
#include<string.h>
#define PORT 1200

char buffer[1024] = "Hei all";
char hello[100] = "Hello";

/**
 * @function       : sendthread
 * @brief          : This is a thread which will write the message to the server
 * @caller         : main function
 */
void* sendThread (void* arg) {
	int sock = *(int *)arg;
	int isFirst = 1;
	while(1) {
		strcpy(hello,"");
		if(isFirst == 0) {
			getchar();
		}
		isFirst = 0;
		scanf("%[^\n]s",hello);
		/* Writing the message to the server */
		write(sock,hello,htonl(strlen(hello)));
		hello[0] = '\0';
	}
	pthread_exit(0);

}

/**
 * @function       : listenThread
 * @brief          : This is a thread which will listen from the server and
 *                   prints the message
 * @caller         : main function
 */
void* listenThread (void* arg) {
	int sock = *(int *)arg;
	while(1) {
		strcpy(buffer,"");
        /* This will read from the server */
		read(sock, buffer, 1024);
		sleep(1);
		printf("%s\n",buffer);
	}
	pthread_exit(0);
}

int main(int argc, char const *argv[])
{
	int sock = 0;
	pthread_t tid1,tid2;
	struct sockaddr_in serv_addr;
    /* Creating a socket */
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}
	memset(&serv_addr, '0', sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	// Convert IPv4 and IPv6 addresses from text to binary form
	if(inet_pton(AF_INET, "192.168.101.148", &serv_addr.sin_addr)<=0)
	{
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	}
    /* Conecting to the server */
	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}
    /* Creating the threads */
	pthread_create(&tid1,NULL,listenThread,&sock);
	pthread_create(&tid2,NULL,sendThread,&sock);
    /* Joining the threads */
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	return 0;
}
