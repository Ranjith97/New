
/**
 * @file      : DLL.c
 * @brief     : This file contains source code to write a program that contains
 *              temporary database of SSID name, channel number in 2.4G band
 *              (Use ENUM), BSSID, bitrate, RSSI of N Access points. Use DOUBLE
 *              LINKED LIST and DMA(allocate exact memory space according to
 *              given input).
 * @author    : Tharun kumar(tharunkumar.p@vvdntech.com)
 * @Copyright : (c) 2012-2013 , VVDN Technologies Pvt. Ltd.
 *              Permission is hereby granted to everyone in VVDN Technologies
 *              to use the Software without restriction, including without
 *              limitation the rights to use, copy, modify, merge, publish,
 *              distribute, distribute with modifications.
 */


#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define SUCCESSFUL_SCAN_RETURN 2
#define SUCCESS 0

int iterator = 0;

/*ENUM used to limit options for the channel number*/
enum ChannelNumber { ONE = 1, TWO, THREE ,FOUR ,FIVE ,SIX ,SEVEN ,EIGHT ,NINE
	,TEN, ELEVEN ,TWELVE ,THIRTEEN };


struct APDetails {
	char SSIDname[30];
	enum ChannelNumber chnumber;
	int BSSID[6];
	int bps;
	int RSSI;
	struct APDetails *prev;
	struct APDetails *next;

};

typedef struct APDetails APDetails_t;
APDetails_t *head = NULL;
APDetails_t *APDetailsptr;

void insert_at_begin();
void insert_at_end();
void delete_at_end();
void delete_at_position(int);
void BPSnRSSIinput(int iterator,int BPSorRSSI);
void mac_input(int iterator);


/**
 * @function : input
 * @brief    : This function gets input from the user.
 * @caller   : insert_at_begin ,insert_at_position ,insert_at_end
 */
void input() {
	int firstTime = 0;
	int chnum;
	iterator = 0;
	printf("Enter details of AP\n");
	if(firstTime == 0) {
		while(getchar() != '\n');
		firstTime = 1;
	}
	printf("Enter SSID name:");
	scanf("%[^\n]s",(APDetailsptr + iterator)->SSIDname);
	while(getchar() != '\n');
	printf("Enter channel number:");
	scanf("%d",&chnum);
	/*If Invalid input is entered Channel number will be taken as 1*/
	switch(chnum) {
		case ONE:
			((APDetailsptr+iterator)->chnumber) = 1;
			break;
		case TWO:
			((APDetailsptr+iterator)->chnumber) = 2;
			break;
		case THREE:
			((APDetailsptr+iterator)->chnumber) = 3;
			break;
		case FOUR:
			((APDetailsptr+iterator)->chnumber) = 4;
			break;
		case FIVE:
			((APDetailsptr+iterator)->chnumber) = 5;
			break;
		case SIX:
			((APDetailsptr+iterator)->chnumber) = 6;
			break;
		case SEVEN:
			((APDetailsptr+iterator)->chnumber) = 7;
			break;
		case EIGHT:
			((APDetailsptr+iterator)->chnumber) = 8;
			break;
		default:
			((APDetailsptr+iterator)->chnumber) = 1;

	}
	while(getchar() != '\n');
	mac_input(iterator);
	BPSnRSSIinput(iterator,0);
	BPSnRSSIinput(iterator,1);

	iterator++;
}


/**
 * @function : mac_input
 * @param1   : iterator
 * @brief    : This function is used to take MAC address as input
 * @caller   : input
 */
void mac_input(int iterator) {
	int scan_val = 0;  /*To store return value of scanf*/
	int executed = 0;  /*To know whether valid MAC address is entered*/
	char ch;
	/*MAC validation*/
	do {
		executed = 0;
		printf("Enter valid BSSID number in form a:b:c:d:e:f:-");
		scan_val = scanf("%2x:%2x:%2x:%2x:%2x:%2x%c",
				&((APDetailsptr+iterator)->BSSID[0]),
				&((APDetailsptr+iterator)->BSSID[1]),
				&((APDetailsptr+iterator)->BSSID[2]),
				&((APDetailsptr+iterator)->BSSID[3]),
				&((APDetailsptr+iterator)->BSSID[4]),
				&((APDetailsptr+iterator)->BSSID[5]),&ch);
		if((scan_val == 7) && (ch == '\n') &&
				((APDetailsptr+iterator)->BSSID[0] >= 0) &&
				((APDetailsptr+iterator)->BSSID[1] >= 0) &&
				((APDetailsptr+iterator)->BSSID[2] >= 0) &&
				((APDetailsptr+iterator)->BSSID[3] >= 0) &&
				((APDetailsptr+iterator)->BSSID[4] >= 0) &&
				((APDetailsptr+iterator)->BSSID[5] >= 0)){
			executed = 1;
			break;
		}
		while(getchar() != '\n');
	} while(executed == 0 );
}


/**
 * @function : insert_at_begin
 * @brief    : This function is used to insert element at begining of linked
 *              list.
 * @caller   : main
 */
void insert_at_begin() {
	APDetails_t *new_node = (struct APDetails*)malloc(sizeof(APDetails_t));
	APDetailsptr = new_node;
	input();
	/*If no node is present*/
	if(head == NULL) {
		new_node->prev = NULL;
		new_node->next = NULL;
		head = new_node;
	} else {
		new_node->prev = NULL;
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}
}


/**
 * @function : insert_at_position
 * @param1   : position
 * @brief    : This function position to be deleted as input and inserts element
 *              at that position.
 * @caller   : main
 */
void insert_at_position(int pos) {
	APDetails_t *temp = head;
	APDetails_t *previous = head;
	APDetails_t *next_element = head;
	APDetails_t *new_node = (APDetails_t *)malloc(sizeof(struct APDetails));
	int count = 0;
	int prev_loc = 0;
	while(temp != NULL) {
		temp = temp->next;
		count++;
	}
	previous = head;
	if(count >= pos && pos != 0) {
		while(prev_loc < pos-2) {
			previous = previous->next;
			prev_loc++;
		}
		APDetailsptr = new_node;
		input();
		next_element = previous->next;
		new_node->prev = previous;
		new_node->next = next_element;
		previous->next = new_node;
		next_element->prev = new_node;
	} else if(pos == 0) {
		insert_at_begin();
	} else if(count+1 == pos) {
		insert_at_end();
	} else {
		printf("\nSorry!There are only %d elements in the list",count);
	}
}


/**
 * @function : insert_at_end
 * @return   : status
 * @brief    : This function will insert element at end of list
 * @caller   : main
 */
void insert_at_end() {
	APDetails_t *new_node = (struct APDetails*)malloc(sizeof(APDetails_t));
	APDetailsptr = new_node;
	input();
	if(head == NULL) {
		new_node->prev = NULL;
		new_node->next = NULL;
		head = new_node;
	}else {
		APDetails_t *temp1 = head;
		while(temp1->next != NULL) {
			temp1 = temp1->next;
		}
		temp1->next = new_node;
		new_node->prev = temp1;
		new_node-> next = NULL;
	}
}



/**
 * @function : delete_at_start
 * @brief    : This function will delete element at start of list.
 * @caller   : delete_at_position
 */
void delete_at_start() {
	APDetails_t *temp = head;
	if(temp != NULL) {

		if(head->next == NULL)
		{
			head = NULL;
			return;
		}
		head = head->next;
		head->prev = NULL;
		free(temp);
	}else {
		printf("No elements in list");
	}
}


/**
 * @function : delete_at_position
 * @param1   : position
 * @brief    : This function will delete element at a particular position
 * @caller   : Delete_By_Channel_Number
 */
void delete_at_position(int position) {
	APDetails_t *temp = head;
	APDetails_t *del_ptr = head;
	APDetails_t *previous = head;
	APDetails_t *next_element = head;
	int count = 0;
	int prev_loc = 0;
	while(temp != NULL) {
		temp = temp->next;
		count++;
	}
	del_ptr = head;
	if(count >= position && position!=0) {
		while(prev_loc < position-2) {
			del_ptr = del_ptr->next;
			prev_loc++;
		}
		previous = del_ptr->prev;
		next_element = del_ptr->next;
		previous->next =next_element;
		next_element->prev = previous;
		free(del_ptr);
	} else if(position == 0) {
		delete_at_start();
	} else if(count == position) {
		delete_at_end();
	} else {
		printf("\nSorry!There are only %d elements in the list",count);
	}
}


/**
 * @function : delete_at_end
 * @brief    : This function will delete the last element in list.
 * @caller   : delete_at_position
 */
void delete_at_end() {
	APDetails_t *temp = head;
	APDetails_t *last_but_one = head;
	if(temp != NULL) {
		while(temp->next != NULL) {
			temp = temp->next;
		}

		last_but_one = temp->prev;
		last_but_one->next = NULL;
		free(temp);
	} else {
		printf("\nNo elemensts present in the list");
	}
}



/**
 * @function : print_reverse
 * @brief    : This function will print linked list in reverse order.
 * @caller   : main
 */
void print_reverse() {
	APDetails_t *temp = head;
	/*traverse to end*/
	if(temp != NULL) {
		while(temp->next != NULL) {
			temp = temp->next;
		}
		while(temp != NULL) {
		//	printf("\n%d",temp->data);

			printf("SSID NAME:%s\n",temp->SSIDname);
			printf("CHNUMBER:%d\n",temp->chnumber);
			printf("BSSID:%2x:%2x:%2x:%2x:%2x:%2x\n",
					(temp->BSSID[0]),
					(temp->BSSID[1]),
					(temp->BSSID[2]),
					(temp->BSSID[3]),
					(temp->BSSID[4]),
					(temp->BSSID[5]));
			printf("BPS:%d\n",(temp->bps));
			printf("RSSI:%d\n",(temp->RSSI));
			temp = temp->prev;
		}
	} else {
		printf("\nNo elements in list");
	}

}


/**
 * @function : display
 * @brief    : This function will display elements of linked list.
 * @caller   : main
 */
void display() {
	APDetails_t *temp = head;
	/*traverse and display elements in list*/
	while(temp != NULL) {
		printf("SSID NAME:%s\n",temp->SSIDname);
		printf("CHNUMBER:%d\n",temp->chnumber);
		printf("BSSID:%2x:%2x:%2x:%2x:%2x:%2x\n",
				(temp->BSSID[0]),
				(temp->BSSID[1]),
				(temp->BSSID[2]),
				(temp->BSSID[3]),
				(temp->BSSID[4]),
				(temp->BSSID[5]));
		printf("BPS:%d\n",(temp->bps));
		printf("RSSI:%d\n",(temp->RSSI));
		printf("\n");
		temp = temp->next;
	}
}


int main()
{
	int option;
	int input_value = 0;
	int input_position = 0;
	do {

		printf("\nEnter 1 to Insert at begin");
		printf("\nEnter 2 to Insert at a position");
		printf("\nEnter 3 to Insert at end");
		printf("\nEnter 4 to delete by channel number");
		printf("\nEnter 5 to print elements in reverse");
		printf("\nEnter 6 to display elements");
		printf("\nEnter any other option to exit\n");
		scanf("%d",&option);

		switch(option) {
			case 1:
				insert_at_begin();
				break;

			case 2:
				printf("\nEnter the position to insert");
				scanf("%d",&input_position);
				insert_at_position(input_position);
				break;

			case 3:
				insert_at_end();
				break;

			case 4:
				printf("\nEnter the channel number to delete");
				scanf("%d",&input_value);
				delete_by_channel_number(input_value);
				break;

			case 5:
				print_reverse();
				break;

			case 6:
				display();
				break;

			default:
				exit(0);
		}

	} while(1);
	return SUCCESS;
}
