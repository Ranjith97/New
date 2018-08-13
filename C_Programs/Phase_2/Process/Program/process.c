/*
 * @file       		: process.c
 * @brief      		: This file contains souce code for creating 5 child
 *                    processes from a single parent, then generate object file
 *                    for a 5 different C files in each child. And then link
 *                    the 5 object files in 6th child and execute that file in
 *                    7th child.
 * @author     		: Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013, VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define ARRAY_SIZE 20
#define SUCCESS 0
#define FAILURE -1

int main()
{
    pid_t pid[7];
    int iter, status;
    char *var[ARRAY_SIZE], temp1[ARRAY_SIZE];

    /* Get 5 file names from user */
    for (iter = 0; iter < 5; iter++) {
        printf("Enter the file name: ");
        scanf("%s",temp1);
        var[iter] = (char*) calloc (strlen(temp1) , sizeof(char));
        memcpy (var[iter], temp1, strlen(temp1));
    }
    /* Creates first child process and create the object file for 1st source
     * file */
    pid[0] = fork();
    if (pid[0] == SUCCESS) {
        printf("Child1\n");
        char *arg[] = {"gcc", "-c", var[0], NULL};
        execvp (arg[0], arg);
    }
    else if (pid[0] == FAILURE) {
        perror("ERROR\n");
    }
    else {
        /* Creates second child process and create the object file for 2nd
         * source file */
        pid[1] = fork();
        if (pid[1] == SUCCESS) {
            printf("Child2\n");
            char *arg[] = {"gcc", "-c", var[1], NULL};
            execvp (arg[0], arg);
        }
        else if (pid[1] == FAILURE) {
            perror("ERROR\n");
        }
        else {
            /* Creates third child process and create the object file for 3rd
             * source file */
            pid[2] = fork();
            if (pid[2] == SUCCESS) {
                printf("Child3\n");
                char *arg[] = {"gcc", "-c", var[2], NULL};
                execvp (arg[0], arg);
            }
            else if (pid[2] == FAILURE) {
                perror("ERROR\n");
            }
            else {
                /* Creates fourth child process and create the object file for
                 * 4th source file */
                pid[3] = fork();
                if (pid[3] == SUCCESS) {
                    printf("Child4\n");
                    char *arg[] = {"gcc", "-c", var[3], NULL};
                    execvp (arg[0], arg);
                }
                else if (pid[3] == FAILURE) {
                    perror("ERROR\n");
                }
                else {
                    /* Creates fifth child process and create the object file
                     * for 5th source file */
                    pid[4] = fork();
                    if (pid[4] == SUCCESS) {
                        printf("Child5\n");
                        char *arg[] = {"gcc", "-c", var[4], NULL};
                        execvp (arg[0], arg);
                    }
                    else if (pid[4] == FAILURE) {
                        perror("ERROR\n");
                    }
                    else {
                        /* Creates sixth child process and link the object files
                         * of 5 child processes */
                        for (iter = 0; iter < 5; iter++) {
                            waitpid (pid[iter], &status, 0);
                            if (WEXITSTATUS(status) == SUCCESS) {
                                printf("Child %d exited normally\n", iter);
                            }
                            else {
                                printf("Parent & child process were killed\n");
                                kill (pid[iter] , SIGINT);
                                kill (getpid() , SIGINT);
                            }
                        }
                        pid[5] = fork();
                        if (pid[5] == SUCCESS) {
                            fflush(stdout);
                            char *arg[] = {"gcc","-o", "file", var[0], \
                                var[1], var[2], var[3], var[4], NULL};
                            execvp (arg[0], arg);
                        }
                        else if (pid[5] == FAILURE) {
                            perror("ERROR\n");
                        }
                        else {
                            wait(0);
                            /* Creates seventh child process and excute the
                             * file that is created in previous process */
                            pid[6] = fork();
                            if (pid[6] == SUCCESS) {
                                fflush(stdout);
                                system ("./file");
                            }
                            else if (pid[6] == FAILURE) {
                                perror("ERROR\n");
                            }
                            else {
                                while (wait(0) != FAILURE);
                            }
                        }
                    }
                }
            }
        }
    }
    return SUCCESS;
}
