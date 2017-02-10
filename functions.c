#include"functions.h"
#include<stdio.h>
#include<ctype.h>

int checkint(char a[])														//UDF to check integer input
{
	int c=1,i=0;
	while(a[i]!='\0' && c==1)
	{
	if(a[i]<'0' || a[i]>'9')												//checking integer
		c=0;
	i++;
	}
	printf(" ");
	return c;														//returning answer
}


int inrange(int n,int lb,int ub)												//UDF to find if no. is in range
{	printf(" ");
	if(!(n>=lb && n<=ub))													//checking range
	{
		return 0;
	}
	else
		return 1;													//returning answer
}


int lengthis(char a[],int input_l)
{
	int l;
	for(l=0;a[l]!='\0';l++);												//find length
	printf(" ");
	if(l==input_l)														//check length
		return 1;
	else
		return 0;													//returning answer
}


int isdate(char a[])														//UDF to check date format
{
	int c=1,d,m,y;
	if(!(a[2]=='/' && a[5]=='/'))												//check format
		c=0;

	d= (int) ((a[0]-48)*10 + (a[1]-48));
	m= (int) ((a[3]-48)*10 + (a[4]-48));											//calculate d, m and y
	y= (int) ((a[6]-48)*1000 + (a[7]-48)*100 + (a[8]-48)*10 + (a[9]-48));

	if(a[10] != '\0')
		c=0;

	if(d<1 || m<1 || y<1 || m>12)
		c=0;

	if((m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) && d>31)							//checking conditions for
		c=0;														//d,m,y based on input

	else if((m==4 || m==6 || m==9 || m==11) && d>30)
		c=0;
	else if((m==2 && ((y%4==0) && (y%100 !=0 || (y%100==0 && y%400==0)))) && d>29)						//for leap year
		c=0;
	else if((m==2 && (!(y%4==0) && (y%100 !=0 || (y%100==0 && y%400==0)))) && d>28)
		c=0;
	printf(" ");
	return c;														//returning answer
}


int isname(char n[])														//UDF to check name input
{
	int c=1,i;

	for(i=0 ; n[i]!='\0' && c==1 ; i++)
	{
		if(!(((n[i]>='a' && n[i]<='z') || (n[i]>='A' && n[i]<='Z')) || n[i]==' '))					//checking name
			c=0;
	}
	printf(" ");
	return c;														//returning answer
}


int isphonenum(char a[30],int input_l)												//UDF to check entered phone no validity
{
	int l=0,i;
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]>='0' && a[i]<='9')											//counting length
			l++;
	}
	printf(" ");
	if(l==input_l)														//checking
		return 1;
	else
		return 0;													//returning answer
}


int isisbn(char a[])														//UDF to check ISBN code
{
	int c=1,i,sum=0,check,l=1;
	if(a[13]!='\0')
		c=0;
	if(a[1]!='-' || a[4]!='-' || a[11]!='-')										//checking validity
		c=0;
	check=a[12]-48;
	for(i=0;i<11;i++)
	{
		if(a[i]!='-')
		{
				sum+=(a[i]-48)*l;
				l++;
		}
	}
	if((sum%11)!=check)
		c=0;
	printf(" ");
	return c;														//returning answer
}

int isroll(char a[])														//UDF to check roll no. validity
{
	int i,c=1;
	if(!((a[0]>='0' && a[0]<='9') && (a[1]>='0' && a[1]<='9') && (a[5]>='0' && a[5]<='9') && (a[6]>='0' && a[6]<='9') && (a[7]>='0' && a[7]<='9')))
		c=0;
	if(toupper(a[2])!='U')
		c=0;
	if(toupper(a[3])!='C' && toupper(a[3])!='E' && toupper(a[3])!='M')							//checking different conditions
		c=0;
	if(toupper(a[3])=='C' && (toupper(a[4])!='S' && toupper(a[4])!='C'))
		c=0;
	if(toupper(a[3])=='E' && toupper(a[4])!='C')
		c=0;
	if(toupper(a[3])=='M' && (toupper(a[4])!='M' && toupper(a[4])!='E'))
		c=0;
		
	printf(" ");
	return c;														//returning answer
		
}
