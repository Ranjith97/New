/**
 * @file            : Server.c
 * @brief           : This program will create a server that will accept the
 *                    clients and broadcasts the message sent from one client
 *                    to all of the clients
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013, VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */

#include<unistd.h>
#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<pthread.h>
#include<string.h>

#define PORT 1200

char buffer[1024] = "";

/**
 * @function       : clients
 * @brief          : This function will broadcasts the message from one client
 *                   to all other clients
 * @caller         : main function
 */
void* clients(void *socket) {

	int new_socket = *(int *)socket;

	while(1) {
        /* This will broadcasts the message */
		send(new_socket, buffer, htonl(strlen(buffer)) , 0 );
		sleep(1);
	}

    memset(buffer, 0, 1024);
	printf("Hello message sent\n");
	pthread_exit(0);
}

/**
 * @function       : clientListen
 * @brief          : This function will read from one client and saves it one
 *                   buffer
 * @caller         : main function
 */
void* clientListen(void *socket) {
	int new_socket = *(int *)socket;
	while(1) {
        /* This read from the clients */
		read(new_socket, buffer, 1024);
		sleep(1);
        memset(buffer, 0, 1024);
	}
	pthread_exit(0);
}


int main(int argc, char const *argv[])
{
	int server_fd, new_socket;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	pthread_t thread_id[10][2]; /* Initialization of thread */
    /* Creating a new socket */
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}

	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
				&opt, sizeof(opt)))
	{
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons( PORT );

	/* Forcefully attaching socket to the port 8080 */
	if (bind(server_fd, (struct sockaddr *)&address,
				sizeof(address))<0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	int i = 0;
	while(1) {
        /* Creating a queue for the server */
		if (listen(server_fd, 3) < 0)
		{
			perror("listen");
			exit(EXIT_FAILURE);
		}
        /* Accepting the connections from the clients */
		if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
						(socklen_t*)&addrlen))<0)
		{
			perror("accept");
			exit(EXIT_FAILURE);
		}
        /* Creating the two threads for listening and writing */
		pthread_create(&thread_id[i++][0],NULL,clients,&new_socket);
		pthread_create(&thread_id[i++][1],NULL,clientListen,&new_socket);
	}
	return 0;
}
