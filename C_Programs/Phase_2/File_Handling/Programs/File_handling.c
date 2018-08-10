/**
 * @file            : File_handling.c
 * @brief           : This program will read the input as command line argument
 *                    from the user and add or read or delete the given entries
 *                    into or from a file based on the user input.
 * @Copyright(c)    : 2012-2013 , VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */

#include"File_handling.h"

int main ( int argc, char *argv[] )
{
    int do_option = -1, port = -1, long_index = 0, option = 0;
    char tcp_name[NAME_LENGTH], uid[ID_LENGTH], ip_address[IP_LENGTH];

    static struct option long_option[] = {
        {"add", no_argument, 0 , 'a'},
        {"read", no_argument, 0, 'l'},
        {"delete", no_argument, 0 , 'r'},
        {"id", required_argument, 0, 'd'},
        {"name", required_argument, 0, 'n'},
        {"ip", required_argument, 0, 'i'},
        {"port", required_argument, 0 ,'p'},
        {0, 0, 0, 0}
    };
    while ((option = getopt_long(argc, argv, ":arli:n:p:d:", long_option,
                    &long_index)) != FALSE) {
        switch(option) {
            case 'a': do_option = 0;
                      break;
            case 'l': do_option = 1;
                      break;
            case 'r': do_option = 2;
                      break;
            case 'd': if ((id_valid(optarg)) == SUCCESS && \
                              (strlen(optarg) == ID_LENGTH - 1)) {
                          do_option = 3;
                          strncpy(uid, optarg, strlen(optarg) + 1);
                          break;
                      }
                      else {
                          printf("The entered id is not correct.\n");
                          exit(FALSE);
                      }
            case 'n': do_option = 4;
                      strncpy(tcp_name, optarg, strlen(optarg) + 1);
                      break;
            case 'i': if (ip_valid(optarg) == SUCCESS) {
                          do_option = 5;
                          strncpy(ip_address, optarg, strlen(optarg) + 1);
                          break;
                      }
                      else {
                          printf("The entered ip is not correct.\n");
                          exit(FALSE);
                      }
            case 'p': if (port_valid(optarg) == SUCCESS) {
                          port = atoi(optarg);
                          break;
                      }
                      else {
                          printf("The port number is not correct.\n");
                          exit(FALSE);
                      }
            case ':': fprintf(stderr, "%s: option '-%c' requires an argument\n",
                              argv[0], optopt);
                      break;
            default: fprintf(stderr, "%s: option '-%c' is invalid: ignored\n",
                             argv[0], optopt);
                     break;
        }
    }
    if ((do_option == SUCCESS) && (do_option == 3) && (do_option == 4) && \
            (do_option == 5) && (port != FALSE)) {
        add_list(uid, tcp_name, ip_address, port);
    }
    else if((do_option == 1) && (do_option == 5) && (port != FALSE)) {
        read_list(ip_address, port);
    }
    else if((do_option == 2) && (do_option == 4) && (do_option == 5) && \
            (port != FALSE)) {
        del_list(tcp_name, ip_address, port);
    }
    else {
        printf("There is error in argument passing or there is error in the"
                " command.\n");
        printf("./exe_file -a -d uuid -n name -i ip -p port->adding entry.\n");
        printf("./exe_file -l -i ip -p port->reading entry.\n");
        printf("./exe_file -r -n name -i ip -p port->deleting entry.\n");
        exit(FALSE);
    }
    return 0;
}


