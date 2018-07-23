/**
 * @file            : Command_line.c
 * @brief           : This program will get command line arguments as input and
 *                    do the functions as entered by the user
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013 , VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */

#include"Command_line.h"

int main ( int argc, char *argv[] )
{
    int do_reverse = -1, do_length = -1, do_replace = -1, do_compare = -1;
    int do_concat = -1, do_help = -1, option = 0, name1 = -1, name2 = -1;
    int name3 = -1, long_index = 0;

    static struct option long_option[] = {
        {"help", no_argument, 0, 'h'},
        {"str1", required_argument, 0, 'a'},
        {"str2", required_argument, 0, 'b'},
        {"str3", required_argument, 0, 'c'},
        {"length", no_argument, 0, 'l'},
        {"reverse", no_argument, 0, 'r'},
        {"replace", no_argument, 0, 'e'},
        {"concat", no_argument, 0, 'o'},
        {"compare", no_argument, 0, 'p'},
        {0, 0, 0, 0}
    };
    while ((option = getopt_long(argc, argv, ":hlreopa:b:c:", long_option,
                    &long_index)) != FALSE) {
        switch(option) { /* Checking for command line argument condition */
            case 'a': name1 = 0;
                      strcpy(str1, optarg);
                      break;
            case 'b': name2 = 0;
                      strcpy(str2, optarg);
                      break;
            case 'c': name3 = 0;
                      strcpy(str3, optarg);
                      break;
            case 'l': do_length = 0;
                      break;
            case 'r': do_reverse = 0;
                      break;
            case 'e': do_replace = 0;
                      break;
            case 'o': do_concat = 0;
                      break;
            case 'p': do_compare = 0;
                      break;
            case 'h': do_help = 0;
                      break;
            case ':': fprintf(stderr, "%s: option '-%c' requires an argument\n",
                              argv[0], optopt);
                      exit(FAILURE);
            case '?': fprintf(stderr, "%s: option '-%c' is invalid: ignored\n",
                              argv[0], optopt);
                      printf("Try -h/--help for entry of correct options.\n");
                      exit(FAILURE);
        }
    }
    if ((do_length == SUCCESS) && (name1 == SUCCESS)) {
        printf("The length of the string is %d.\n", length(str1));
    }
    else if ((do_reverse == SUCCESS) && (name1 == SUCCESS)) {
        reverse(str1);
    }
    else if ((do_replace == SUCCESS) && (name1 == SUCCESS) && \
            (name2 == SUCCESS) && (name3 == SUCCESS)) {
        if ((length(str2) == TRUE) && (length(str3) == TRUE)) {
            replace(str1, str2[0], str3[0]);
        }
        else {
            printf("str2 and str3 requires only 1 character.\n");
            exit(FAILURE);
        }
    }
    else if ((do_concat == SUCCESS) && (name1 == SUCCESS) && \
            (name2 == SUCCESS)) {
        concat(str1, str2);
    }
    else if ((do_compare == SUCCESS) && (name1 == SUCCESS) && \
            (name2 == SUCCESS)) {
        compare(str1, str2);
    }
    else if ((do_help == SUCCESS)) {
        printf("-r/--reverse -l/--length -o/--concat -p/--compare " \
                "-e/--replace\n");
        exit(FAILURE);
    }
    else {
        printf("There is missing operands or commands for the input and you can"
                " try -h/--help.\n");
        exit(FAILURE);
    }
    return SUCCESS;
}


