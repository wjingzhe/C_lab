#include<stdio.h>
#include<string.h>
void main()
{
	char string[20];
	char str[3][20];
	int i;
	for(i=0;i<3;i++)
		gets(str[i]);
	if(strcmp(str[0],str[1])>0)
		strcpy(string,str[0]);
	else 
		strcpy(string,str[1]);
	if(strcmp(str[2],string)>0)
		strcpy(string,str[2]);
	printf("\nthe largest string is : \n%s\n",string);
	printf("%c",str[1][1]);
}