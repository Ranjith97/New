/**
 * @file            : thread.c
 * @brief           : This program will accept the string as command line
 *                    argument and convert the number if input is 0, output will
 *                    be 9, if input is 1, output will be 8 and so on and
 *                    convert the uppercase letter to lower case and vice versa.
 *                    There will three threads of which 1st thread will take
 *                    care 0th, 3rd, 6th... offsets, 2nd thread will take care
 *                    1st, 4th, 7th offset and thread 3 will take care 2nd, 5th,
 *                    7th... offsets and the three threads will run
 *                    simultaneously.
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2018, VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */

#include<stdio.h>
#include<ctype.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define SUCCESS 0
#define FAILURE -1
#define LENGTH 100
sem_t bin1_sem, bin2_sem, bin3_sem;
int iter;
char string[LENGTH];

void digit_fun(char arg)
{
    int num = (int)arg;
    switch (num) {
        case 0:
            printf("%d", (9 - num));
            break;
        case 1:
            printf("%d", (9 - num));
            break;
        case 2:
            printf("%d", (9 - num));
            break;
        case 3:
            printf("%d", (9 - num));
            break;
        case 4:
            printf("%d", (9 - num));
            break;
        case 5:
            printf("%d", (9 - num));
            break;
        case 6:
            printf("%d", (9 - num));
            break;
        case 7:
            printf("%d", (9 - num));
            break;
        case 8:
            printf("%d", (9 - num));
            break;
        case 9:
            printf("%d", (9 - num));
            break;
    }
}

void *thread1_fun(void *arg)
{
    while (string[iter] != '\0') {
        sem_wait(&bin1_sem);
        if ((isdigit(string[iter]))) {
            digit_fun(string[iter]);
        }
        else if (!(islower(string[iter]))) {
            printf("%c", toupper(string[iter]));
        }
        else if (!(isupper(string[iter]))) {
            printf("%c", tolower(string[iter]));
        }
        else {
            printf("%c", string[iter]);
        }
        iter++;
        sem_post(&bin2_sem);
    }
    sem_post(&bin2_sem);
    pthread_exit(NULL);
}
void *thread2_fun(void *arg)
{
    while (string[iter] != '\0') {
        sem_wait(&bin2_sem);
        if ((isdigit(string[iter]))) {
            digit_fun(string[iter]);
        }
        else if (!(islower(string[iter]))) {
            printf("%c", toupper(string[iter]));
        }
        else if (!(isupper(string[iter]))) {
            printf("%c", tolower(string[iter]));
        }
        else {
            printf("%c", string[iter]);
        }
        iter++;
        sem_post(&bin3_sem);
    }
    sem_post(&bin3_sem);
    pthread_exit(NULL);
}
void *thread3_fun(void *arg)
{
    while (string[iter] != '\0') {
        sem_wait(&bin3_sem);
        if ((isdigit(string[iter]))) {
            digit_fun(string[iter]);
        }
        else if (!(islower(string[iter]))) {
            printf("%c", toupper(string[iter]));
        }
        else if (!(isupper(string[iter]))) {
            printf("%c", tolower(string[iter]));
        }
        else {
            printf("%c", string[iter]);
        }
        iter++;
        sem_post(&bin1_sem);
    }
    sem_post(&bin1_sem);
    pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
    pthread_t thread1, thread2, thread3;
    sem_init(&bin1_sem, 0, 0);
    sem_init(&bin2_sem, 0, 0);
    sem_init(&bin3_sem, 0, 0);
    memset(string, '\0', LENGTH);

    if (argc < 2) {
        printf("There is no string passed.\n");
        exit(FAILURE);
    }
    for (iter = 1;iter <= argc - 1;iter++) {
        strcpy(string, argv[iter]);
        strcpy(string, " ");
        printf("%s\n", string);
    }
    iter = 0;
    pthread_create(&thread1, NULL, thread1_fun, NULL);
    pthread_create(&thread2, NULL, thread2_fun, NULL);
    pthread_create(&thread3, NULL, thread3_fun, NULL);
    sem_post(&bin1_sem);
    sleep(1);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    sem_destroy(&bin1_sem);
    sem_destroy(&bin2_sem);
    sem_destroy(&bin3_sem);
    printf("\nSuccessfully completed the conversion of input.\n");
    return SUCCESS;
}
