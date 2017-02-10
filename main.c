#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include"functions.h"

main()																	//main()
{
	int i,n,l,ub,lb,c;
	char name[30],string[100],date[15],number[30];											//variables declaration

	do																//do-while loop
	{
	printf("\n");
	for(i=0;i<33;i++)
		printf("-");
	printf("\n|\tMenu\t\t\t|\n");													//printing table
	for(i=0;i<33;i++)														//and menu
		printf("-");
	printf("\n| 1 | Check Integer\t\t|\n");
	printf("| 2 | Check Range\t\t|\n");
	printf("| 3 | Check Length\t\t|\n");
	printf("| 4 | Check Date\t\t|\n");												//printing options
	printf("| 5 | Check Name\t\t|\n");
	printf("| 6 | Check Phone Number\t|\n");
	printf("| 7 | Check ISBN Code\t\t|\n");
	printf("| 8 | Check LNMIIT Roll No.\t|\n");
	printf("| 0 | Exit\t\t\t|\n");
	for(i=0;i<33;i++)														//printing table
		printf("-");

	printf("\n\nEnter your choice : ");
	scanf("%d",&c);															//input choice

	switch(c)															//switch case
	{
		case 0 : break;

		case 1 : printf("Enter any number : ");
			 	 scanf("%s",number);											//input number
			 	 if(checkint(number))											//function call
			   		printf("Valid Input\n");
			 	 else
			  		printf("Invalid Input\n");									//print message
			 	 break;

		case 2 : printf("Enter number : ");
			 	 scanf("%d",&n);											//input number
			 	 printf("Enter range (lowerbound and upperbound) : ");							//input range
			 	 scanf("%d%d",&lb,&ub);
			 	 if(inrange(n,lb,ub))											//function call
					printf("Number is in Range\n");
			 	 else
				 	printf("Number is not in range\n");								//print message
			 	 break;

		case 3 : printf("Enter string : ");
			 	 scanf("%s",string);
			 	 printf("Enter length to check : ");									//input
			 	 scanf("%d",&l);
			 	 if(lengthis(string,l))											//function call
					 printf("Length is correct\n");
			 	 else
					 printf("Incorrect length!!!\n");								//message
			 	  break;

		case 4 : printf("Enter Date in format dd/mm/yyyy (enter 2 as 02) : ");
			     scanf("%s",date);												//input

			   	 if(isdate(date))											//function call
				 printf("Correct date and format\n");
			     else
				 	printf("Incorrect date or format(dd/mm/yyyy)\n");						//message
			   	 break;

		case 5 : printf("Enter Name :");
			 getchar();
			     gets(name);												//input

			   	 if(isname(name))											//function call
			  	 	printf("Valid name\n");
			   	 else
				 	printf("Invalid name!!!\n");									//message
			     break;

		case 6 : printf("Enter phone number (may include - ) : ");
				 scanf("%s",string);											//inputs
				 printf("Enter length to check : ");
				 scanf("%d",&l);
				 if(isphonenum(string,l))										//function call
					 printf("Valid phone number\n");
				 else
				 	 printf("Invalid Phone number!!!\n");								//message
				 break;

		case 7 : printf("Enter ISBN Code : ");
				 scanf("%s",string);											//input
				 if(isisbn(string))											//function call
				 	printf("ISBN is correct\n");
				 else
				 	printf("Incorrect ISBN\n");									//message
				 break;

		case 8 : printf("Enter Roll No. in format YYBBBRRR(ex. 15UCS042) : ");
				 scanf("%s",string);											//input
				 if(isroll(string))											//function call
				 	printf("Roll No. is correct\n");
				 else
				 	printf("Incorrect roll No.\n");									//message
				 break;

		default : printf("Enter correct option!!!\n");										//default statement
	}
	if(c!=0)
	{
		printf("\nCheck again?\n0 : Exit\n1 : check again\nChoice : ");								//message to check again
		scanf("%d",&c);
		if(c!=0 && c!=1)
		{
			c=0;
			printf("Wrong Input!!! Automatic Exit...\n");									//message
		}
	}
	} while(c!=0);

}
