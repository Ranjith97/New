/**
 * @file			: main.c
 * @brief			: Write a program to get two, 2D matrices A and B of any
 *                    order from the user. Get any of the arithmetic
                      operator(+, -, *) from the user. Perform the arithemtic
                      operation on A and B(A+B, A-B, A*B).
 * @author			: Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013 , VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */


#include<stdio.h>

int main()
{
	int i,j,k,row1,row2,colomn1,colomn2,count=0,flag;
	int Mat_A[10][10],Mat_B[10][10],res[10][10];
    char op,ch;
	while (1) {
		/* Asking the user to enter the operation to be performed */
		printf("Enter the operation to be done.\n"
	           "+ for addition, - for subtraction and "
			   "* for subtraction.\n");
		scanf("%c",&op);
		while (getchar() !='\n');
		if (op == '+' || op == '-' || op == '*') { /* Verifying if user had
												   entered correct operation */
			break;
		}
		else {
			printf("Enter Valid Input.\n");
		}
	}
l:	while(1) {
		/* Reading rows and colomns of the matrices from user */
		printf("Enter the rows and colomns of the matrices.\n");
		count=scanf("%d %d %d %d%c",&row1,&row2,&colomn1,&colomn2,&ch);
		if (count != 5 || ch != '\n') {
			printf("Invalid input.\n"); /* Checking if integer is entered or
										   not */
		}
		else {
			break;
		}
		while(getchar() != '\n');
	}
	/* Checking if matrix addition or subtraction can be done */
	if ((op == '+' || op == '-') && (row1 != row2 && colomn1 != colomn2)) {
		printf("Addition or Subtraction operation can not be done.\n");
		goto l;
	}
	/* Checking if matrix multiplication can be done */
	else if (op == '*' && row2 != colomn1) {
		printf("Multiplication can not be done.\n");
		goto l;
	}
	do {
		printf("Enter the Matrix A elements.\n");
		flag=1;
		for (i=0;i<row1;i++) { /* Reading Matrix A elements */
			for (j=0;j<colomn1;j++) {
				count=scanf("%d%c",&Mat_A[i][j],&ch);
				if (!(count ==2 && (ch == '\n' || ch == ' '))) {
                	flag=0;
					printf("Invalid input.\n");
			    	while (getchar() != '\n');
					break;
				}
			}
			if (flag == 0) {
				break;
			}
		}
	}while (flag==0);
	do {
    	printf("Enter the Matrix B elements.\n");
		flag=1;
		for (i=0;i<row2;i++) { /* Reading Matrix B elements */
			for (j=0;j<colomn2;j++) {
				count=scanf("%d%c",&Mat_B[i][j],&ch);
				if (!(count ==2 && (ch == '\n' || ch == ' '))) {
				flag=0;
				printf("Invalid input.\n");
				while (getchar() != '\n');
				break;
				}
		}
			if (flag == 0) {
				break;
			}
		}
	}while (flag ==0);
	switch (op) {
		case '+':
			/* Matrix addition operation */
			for (i=0;i<row1;i++) {
				for (j=0;j<colomn1;j++) {
					res[i][j]=Mat_A[i][j] + Mat_B[i][j];
					}
				}
			break;
		case '-':
            /* Matrix subtraction operation */
			for (i=0;i<row1;i++) {
				for (j=0;j<colomn1;j++) {
					res[i][j]=Mat_A[i][j] - Mat_B[i][j];
					}
				}
			break;
		case '*':
			/* Matrix multiplication operation */
            for (i=0;i<row1;i++) {
				for (j=0;j<colomn2;j++) {
					res[i][j]=0;
					for (k=0;k<row2;k++) {
					res[i][j]+=Mat_A[i][k] * Mat_B[k][j];
					}
				}
			}
			break;
	}
    /* Printing the result */
	printf("The result is :\n");
	for (i=0;i<row1;i++) {
		for (j=0;j<colomn2;j++) {
			printf("%d\t",res[i][j]);
		}
		printf("\n");
	}
    return 0;
}




