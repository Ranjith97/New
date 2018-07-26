/**
 * @file            : File_handling.h
 * @brief           :
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013 , VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */

#include<stdio.h>
#include<getopt.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

/**
 * @structure      : Node
 * @brief          : This structure will has the uuid, name, ip address and
 *                   server port.
 * @members
 *  @uuid          : The uuid name
 *  @name          : The name of the tcpclient
 *  @ip            : The ip address of the tcpclient
 *  @server_port   : The port number to which the client is connected
 */
typedef struct Node linked_t;
struct Node {
    char* uuid;
    char* name;
    char* ip;
    int server_port;
};
linked_t *head, *temp, *new_node, *loop;

#define SUCCESS 0
#define FAILURE 0
#define NEWLINE '\n'
#define IP_LENGTH 15
#define NAME_LENGTH 10
#define ID_LENGTH 36
#define FALSE -1
#define HYPHEN_LENGTH 4
#define HYPHEN '-'
#define UUID_LENGTH 36
#define NULL_CHARACTER '\0'
#define PORT_MIN 0
#define PORT_MAX 1081
#define PERIOD '.'
#define PERIOD_COUNT 3
#define NUM_MAX '9'
#define NUM_MIN '0'
#define MAC_MIN 0
#define MAC_MAX 255

void add_list(linked_t **head, char* id, char* tcp_name, char* ip_address, \
              int port);
void del_list(linked_t **head, char* tcp_name, char* ip_address, int port);
void read_list(linked_t *head, char* ip_address, int port);
int ip_valid(char* ip_address);
int port_valid(char* port);
int id_valid(char* id);

int iter, flag, check, count;
char valid;
