/**
 * @file            : List.c
 * @brief           :
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
    int option, data = 0;
    position = 0;
    head = NULL;

	do {
		printf("\nEnter 1 to Insert at begin");
		printf("\nEnter 2 to Insert at a position");
		printf("\nEnter 3 to Insert at end");
		printf("\nEnter 4 to delete by channel number");
		printf("\nEnter 5 to print elements in reverse");
		printf("\nEnter 6 to display elements");
		printf("\nEnter any other option to exit\n");
		scanf("%d", &option);

		switch(option) {
			case 1:
				insert_begin();
				break;
			case 2:
				printf("\nEnter the position to insert");
				scanf("%d", &position);
				insert_position(position);
				break;
			case 3:
				insert_end();
				break;
			case 4:
				printf("\nEnter the id number to delete");
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
    free(details->name);
    free(details->DOB);
    free(details->domain);
    free(details->prev);
    free(details->next);
	return SUCCESS;
}
