/*
 *
 * @file          : hashing.c
 * @brief         : 
 * @Author        : Praveenkumar Naik (praveenkumarnaik.vvdntech.in).
 * @copyright	  : (C), VVDN Technologies Pvt. Ltd.
 */

#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

/*
   This is code for linear probing in open addressing. If you want to do quadratic probing and double hashing which are also
   open addressing methods in this code when I used hash function that (pos+1)%hFn in that place just replace with another function.
   */

/*  
int hexadecimal_to_decimal(int x)
{
	int decimal_number, remainder, count = 0;
	while(x > 0)
	{
		remainder = x % 10;
		decimal_number = decimal_number + remainder * pow(16, 4);
		x = x / 10;
		count++;
	}
	return decimal_number;
}
*/
void insert(long int ary[],int hFn, int size){
	long int element;
	int pos,n=0;
	int i;

	int mac[6];
	int scan_val=0;  /*To store return value of scanf*/
	int executed=0;  /*To know whether valid MAC address is entered*/
	char ch;

	do {
		executed = 0;
		printf("Enter MAC address to:");
		scan_val = scanf("%2x:%2x:%2x:%2x:%2x:%2x%c",&mac[0],&mac[1],&mac[2],
				&mac[3],&mac[4],&mac[5],&ch);
		if((scan_val == 7) && (ch == '\n') && (mac[0] >= 0) && (mac[1] >= 0)  &&
				(mac[2] >= 0) && (mac[3] >= 0) && (mac[4] >= 0) && (mac[5] >= 0)){
			executed=1;

			break;
		}
		while(getchar() != '\n');
	} while(executed == 0 );



	char arr[5];
	char *dup = (char*) malloc(12*sizeof(char));
	long int mac_in_num = 0xffffffffffff;
	for(i=0;i<6;i++) {
		printf("%x\n",mac[i]);
		sprintf(arr,"%x",mac[i]);
		strcat(dup,arr);
	}
	sscanf(dup,"%lx",&mac_in_num);
	printf("ee:%lx\n",mac_in_num);
	element = mac_in_num;
	pos = element%hFn;
	printf("\nposition is:%d\n",pos);
	while(ary[pos]!= INT_MIN) {  // INT_MIN and INT_MAX indicates that cell is empty. So if cell is empty loop will break and goto bottom of the loop to insert element
		if(ary[pos]== INT_MAX)
			break;
		pos = (pos+1)%hFn;
		n++;
		if(n==size)
			break;      // If table is full we should break, if not check this, loop will go to infinite loop.
	}

	if(n==size)
		printf("Hash table was full of elements\nNo Place to insert this element\n\n");
	else
		ary[pos] = element;    //Inserting element
}

void delete(long int ary[],int hFn,int size){
	/*
	   very careful observation required while deleting. To understand code of this delete function see the note at end of the program
	   */
	long int element;
	int n=0,pos;

	int i;
	int mac[6];
	int scan_val=0;  /*To store return value of scanf*/
	int executed=0;  /*To know whether valid MAC address is entered*/
	char ch;

	do {
		executed = 0;
		printf("Enter MAC address to:");
		scan_val = scanf("%2x:%2x:%2x:%2x:%2x:%2x%c",&mac[0],&mac[1],&mac[2],
				&mac[3],&mac[4],&mac[5],&ch);
		if((scan_val == 7) && (ch == '\n') && (mac[0] >= 0) && (mac[1] >= 0)  &&
				(mac[2] >= 0) && (mac[3] >= 0) && (mac[4] >= 0) && (mac[5] >= 0)){
			executed=1;

			break;
		}
		while(getchar() != '\n');
	} while(executed == 0 );
	char arr[5];
	char *dup = (char*) malloc(12*sizeof(char));
	long int mac_in_num = 0xffffffffffff;
	for(i=0;i<6;i++) {
		printf("%x\n",mac[i]);
		sprintf(arr,"%x",mac[i]);
		strcat(dup,arr);
	}
	sscanf(dup,"%lx",&mac_in_num);
	printf("ee:%lx\n",mac_in_num);
	element = mac_in_num;




//	printf("Enter element to delete\n");
//	scanf("%ld",&element);

	pos = element%hFn;

	while(n++ != size){
		if(ary[pos]==INT_MIN){
			printf("Element not found in hash table\n");
			break;
		}
		else if(ary[pos]==element){
			ary[pos]=INT_MAX;
			printf("Element deleted\n\n");
			break;
		}
		else{
			pos = (pos+1) % hFn;
		}
	}
	if(--n==size)
		printf("Element not found in hash table\n");
}

void search(long int ary[],int hFn,int size){
	long int element;
	int pos,n=0;
	int i;
	int mac[6];
	int scan_val=0;  /*To store return value of scanf*/
	int executed=0;  /*To know whether valid MAC address is entered*/
	char ch;

	do {
		executed = 0;
		printf("Enter MAC address to:");
		scan_val = scanf("%2x:%2x:%2x:%2x:%2x:%2x%c",&mac[0],&mac[1],&mac[2],
				&mac[3],&mac[4],&mac[5],&ch);
		if((scan_val == 7) && (ch == '\n') && (mac[0] >= 0) && (mac[1] >= 0)  &&
				(mac[2] >= 0) && (mac[3] >= 0) && (mac[4] >= 0) && (mac[5] >= 0)){
			executed=1;

			break;
		}
		while(getchar() != '\n');
	} while(executed == 0 );
	char arr[5];
	char *dup = (char*) malloc(12*sizeof(char));
	long int mac_in_num = 0xffffffffffff;
	for(i=0;i<6;i++) {
		printf("%x\n",mac[i]);
		sprintf(arr,"%x",mac[i]);
		strcat(dup,arr);
	}
	sscanf(dup,"%lx",&mac_in_num);
	printf("ee:%lx\n",mac_in_num);
	element = mac_in_num;
//	printf("Enter element you want to search\n");
//	scanf("%ld",&element);
	pos = element%hFn;

	while(n++ != size){
		if(ary[pos]==element){
			printf("Element found at index %d\n",pos);
			break;
		}
		else
			if(ary[pos]==INT_MAX ||ary[pos]!=INT_MIN)
				pos = (pos+1) %hFn;
	}
	if(--n==size) printf("Element not found in hash table\n");
}

void display(long int ary[],int size){
	int i;

	printf("Index\tValue\n");

	for(i=0;i<size;i++)
		printf("%d\t%lx\n",i,ary[i]);
}

//int sum_value = 0;
int main(){
	int size,hFn,i,choice;
//	int sum_value = 0;
//	int mac[6];
	printf("Enter size of hash table\n");
	scanf("%d",&size);

	long int ary[size];



	printf("Enter hash function [if mod 10 enter 10]\n");
	scanf("%d",&hFn);

//	sum_value = hexadecimal_to_decimal(mac[0]) +  hexadecimal_to_decimal(mac[1])
//		+ hexadecimal_to_decimal(mac[2]) + hexadecimal_to_decimal(mac[3])
///		+  hexadecimal_to_decimal(mac[4]) +  hexadecimal_to_decimal(mac[5]);


	for(i=0;i<size;i++)
		ary[i]=INT_MIN; //Assigning INT_MIN indicates that cell is empty

	printf("\n%lx,%lx\n",LONG_MAX,LONG_MAX);
	do{
		printf("Enter your choice\n");
		printf(" 1-> Insert\n 2-> Delete\n 3-> Display\n 4-> Searching\n 0-> Exit\n");
		scanf("%d",&choice);

		switch(choice){
			case 1:
				insert(ary,hFn,size);
				break;
			case 2:
				delete(ary,hFn,size);
				break;
			case 3:
				display(ary,size);
				break;
			case 4:
				search(ary,hFn,size);
				break;
			default:
				if(choice!=0)
					printf("Enter correct choice\n");
					break;
		}
	}while(choice);

	return 0;
}

