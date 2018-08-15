/**
 * @file            : List.c
 * @brief           : This program will create a doubly linked list and do the
 *                    operations like insertion, deletion (both all cases),
 *                    printing in reversed order and displaying the contents
 *                    of the list based upon the user input
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013, VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */
#include"List.h"

int main()
{
    int option, data = 0, position = 0;

    /* Getting the input values from the user */
	do {
		printf("\nEnter 1 to Insert at begin");
		printf("\nEnter 2 to Insert at a position");
		printf("\nEnter 3 to Insert at end");
		printf("\nEnter 4 to delete by id number");
		printf("\nEnter 5 to print elements in reverse");
		printf("\nEnter 6 to display elements");
		printf("\nEnter any other option to exit\n\n");
		scanf("%d", &option);

        /* Checking the entered value from the user for correct input */
		switch(option) {
			case 1:
				insert_begin();
				break;
			case 2:
				printf("\nEnter the position to insert : ");
				scanf("%d", &position);
				insert_position(position);
				break;
			case 3:
				insert_end();
				break;
			case 4:
				printf("\nEnter the id number to delete : ");
				scanf("%d", &data);
				delete_id(data);
				break;
			case 5:
				print_reverse();
				break;
			case 6:
				display();
				break;
			default:
                printf("Wrong option has been entered\nProgram is exiting.\n");
				exit(FAILURE);
		}
	}while (TRUE);
    /* Freeing the allocated memories */
    free(new_node->domain);
    free(new_node->DOB);
    free(new_node->name);
    free(new_node);
    free(head);
	return SUCCESS;
}
