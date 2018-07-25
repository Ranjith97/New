/**
 * @file            : File_handling.c
 * @brief           :
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013 , VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */

#include"File_handling.h"

int main ( int argc, char *argv[] )
{
    int do_add, do_read, do_delete, port, id, name, ip, long_index, option;
    char tcp_name[NAME_LENGTH], uid[ID_LENGTH], ip_address[IP_LENGTH];

    do_add = -1;
    do_read = -1;
    do_delete = -1;
    port = -1;
    id = -1;
    name = -1;
    ip = -1;
    option = 0;
    opterr = 0;
    long_index = 0;
    head = NULL;

    static struct option long_option[] = {
        {"add", no_argument, 0 , 'a'},
        {"read", no_argument, 0, 'r'},
        {"delete", no_argument, 0 , 'd'},
        {"id", required_argument, 0, 'i'},
        {"name", required_argument, 0, 'n'},
        {"ip", required_argument, 0, 'p'},
        {"port", required_argument, 0 ,'o'},
        {0, 0, 0, 0}
    };
    while ((option = getopt_long(argc, argv, ":ardi:n:p:o:", long_option,
                    &long_index)) != FALSE) {
        switch(option) {
            case 'a': do_add = 0;
                      break;
            case 'r': do_read = 0;
                      break;
            case 'd': do_delete = 0;
                      break;
            case 'i': if (id_valid(optarg) == SUCCESS) {
                          id = 0;
                          strcpy(uid, optarg);
                          break;
                      }
                      else {
                          printf("The entered id is not correct.\n");
                          exit(FAILURE);
                      }
            case 'n': name = 0;
                      strcpy(tcp_name, optarg);
                      break;
            case 'p': if (ip_valid(optarg) == SUCCESS) {
                          ip = 0;
                          strcpy(ip_address, optarg);
                          break;
                      }
                      else {
                          printf("The entered ip is not correct.\n");
                          exit(FAILURE);
                      }
            case 'o': if (port_valid(optarg) == SUCCESS) {
                          port = atoi(optarg);
                          break;
                      }
                      else {
                          printf("The port number is not correct.\n");
                          exit(FAILURE);
                      }
            case ':': fprintf(stderr, "%s: option '-%c' requires an argument\n",
                              argv[0], optopt);
                      break;
            default: fprintf(stderr, "%s: option '-%c' is invalid: ignored\n",
                              argv[0], optopt);
                      break;
        }
    }
    if ((do_add == SUCCESS) && (ip == SUCCESS) && (id == SUCCESS) && \
            (name == SUCCESS) && (port != FALSE)) {
        add_list(&head, uid, tcp_name, ip_address, port);
    }
    else if((do_read == SUCCESS) && (ip == SUCCESS) && (port != FALSE)) {
        read_list(head, ip_address, port);
    }
    else if((do_delete == SUCCESS) && (name == SUCCESS) && (ip == SUCCESS) && \
            (port != FALSE)) {
        del_list(&head, tcp_name, ip_address, port);
    }
    else {
        printf("There is error in argument passing or there is error in the"
                " command.\n");
        exit(FAILURE);
    }
    return 0;
}


