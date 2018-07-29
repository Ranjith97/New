/**
 * @file            : Hash.h
 * @brief           : This program will get the MAC id from the user and does
 *                    insertion or deletion or searching of the MAC id in the
 *                    hash table based on the user input
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013 , VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */

#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define SIZE 20
#define HFN 20
#define MAC_SIZE 6
#define TEMP_SIZE 2
#define SUCCESS 0

void insert(long int *hash);
void del(long int *hash);
void search(long int *hash);

long int element, mac_num;
int pos, check, flag, iter, num, mac[MAC_SIZE];
char valid, arr[TEMP_SIZE], *temp;
