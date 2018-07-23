/* *
 * @file			: main.c
 * @brief			: Print a hollow rectangle by getting the number of rows
 *                    from the user
 * @author			: Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013 , VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */


#include <stdio.h>

int main()
{
	int row,i,j,flag;
	char n[10];

l:	printf("Please enter the correct number of rows.\n");
	scanf("%s",n); /* Read the number of rows from user */
	while(getchar()!='\n');
	flag=0;
	for (i=0;n[i]!='\0';i++) {
		if (n[i] >= '0' && n[i] <= '9' && n[0] != '0'){}
		else {
			flag=1;
			break; /* Breaks the loop if any character or only zero is
		              detected */
		}
	}
	if (flag==1) {
		goto l;/* Jump to the label l */
	}
	else {
		sscanf(n,"%d",&row);
		for (i=0;i<row;i++) {
			for (j=0;j<row;j++) {
					if (i==0 || i==row-1 ||
						j==0 || j==row-1) {
						printf("*"); /* Print the first and last rows along
										with the first and last characters of
										each rows as * */
					}
					else {
						printf(" ");
					}
			}
			printf("\n"); /* Printing newline after each row */
		}
	}

	return 0;
}
