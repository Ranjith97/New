/**
 * @file            : List.h
 * @brief           :
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013, VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define NAME_LENGTH 20
#define INT_LENGTH 3
#define DOB_LENGTH 4
#define MONTH_MAX 13
#define DOB_MIN 0
#define DATE_MAX 32
#define YEAR_MIN 60
#define YEAR_MAX 98
#define DOMAIN_LENGTH 2
#define SUCCESS 0
#define FAILURE 0
#define TRUE 1
#define COUNT 3
#define NEWLINE '\n'
#define CHECK_INTEGER_LENGTH 2
#define OPTION_MAX 6
#define MIN 0
#define DOMAIN_MAX 4

/**
 * @structure      : Employee
 * @brief          : This structure is defined to store the employee details
 *                   like employee name, DOB, experience, domain and the id of
 *                   the employee in the format a doubly linked list.
 * @members
 *  @name          : Employee name
 *  @DOB           : Date of birth of the employee
 *  @experience    : Experience of the employee
 *  @domain        : Domain of the employee
 *  @id            : ID of the employee
 *  @prev          : contains previous element address
 *  @next          : contains next element address
 */
struct Employee {
    char* name;
    int* DOB;
    int experience;
    char* domain;
    int id;
    struct Employee *prev;
    struct Employee *next;
};
typedef struct Employee employee_t;

int input(employee_t *head);
void insert_begin();
void delete_start();
void insert_end();
void delete_end();
void delete_position(int position);
void insert_position(int position);
void delete_id(int data);
void print_reverse();
void display();
void name_valid();
void DOB_valid();
int integer_valid();
int domain_valid();
int option_valid();

employee_t *details, *head;
int flag, count, check, loop, position;
char valid;
