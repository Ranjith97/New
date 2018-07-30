/**
 * @file            : Hash.h
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

void input();
void insert_at_begin();
void insert_at_end();
void delete_at_end();
void delete_at_position(int position);
void name_valid(int iterator);
void DOB_valid(int iterator);
int integer_valid();
int domain_valid();
int option_valid();
