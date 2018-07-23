/**
 * @file            : Command_line.h
 * @brief           : This program will get command line arguments as input and
 *                    do the functions as entered by the user
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013 , VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */


#include<stdio.h>
#include<stdlib.h>
#include<getopt.h>
#include<ctype.h>
#include<string.h>

#define SUCCESS 0
#define FAILURE 0
#define NEWLINE '\n'
#define NULL_CHARACTER '\0'
#define FALSE -1
#define TRUE 1

int length(char *str);
void reverse(char *str);
void compare(char *str1, char *str2);
void concat(char *str1, char *str2);
void replace(char *str1, char str2, char str3);

int str_len, iter;
char str1[20], str2[20], str3[1];
