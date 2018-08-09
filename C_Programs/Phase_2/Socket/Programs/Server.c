#include<unistd.h>
#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<pthread.h>
#include<string.h>

#define PORT 1200

char buffer[1024] = "";

void* clients(void *socket) {

	int new_socket = *(int *)socket;

	while(1) {

		send(new_socket, buffer, htonl(strlen(buffer)) , 0 );
		sleep(1);
	}

    memset(buffer, 0, 1024);
	printf("Hello message sent\n");
	pthread_exit(0);
}

void* clientListen(void *socket) {
	int new_socket = *(int *)socket;
	while(1) {
		read( new_socket , buffer, 1024);
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
	pthread_t thread_id[10][2];
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

	// Forcefully attaching socket to the port 8080
	if (bind(server_fd, (struct sockaddr *)&address,
				sizeof(address))<0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	int i = 0;
	while(1) {
		if (listen(server_fd, 3) < 0)
		{
			perror("listen");
			exit(EXIT_FAILURE);
		}
		if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
						(socklen_t*)&addrlen))<0)
		{
			perror("accept");
			exit(EXIT_FAILURE);
		}
		pthread_create(&thread_id[i++][0],NULL,clients,&new_socket);
		pthread_create(&thread_id[i++][1],NULL,clientListen,&new_socket);

	}
	return 0;
}
