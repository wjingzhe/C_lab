#include<stdio.h>
#include<string.h>

int main()
{
	void sort(char*str[10]);
    int i;
	char str[10][20],*p[10];
	for(i=0;i<10;i++)
	{
        p[i] = str[i];
	}
	printf("intput 10 strings:\n");
	for(i=0;i<10;i++)
	{
		scanf("%s",p[i]);
	}
	sort(p);
	printf("Now, the sequence is:\n");
	for(i=0;i<10;i++)
		printf("%s\n",p[i]);
    return 0;
}

void sort(char*p[10])
{
	int i,j;
	char *temp;
	for(i=0;i<9;i++)
		for(j=0;j<9-i;j++)
		{
			if(strcmp(*(p+j),*(p+j+1))>0)
			/* ����3�е������ǽ���s[j]ָ���һά�����������s[j+1]ָ���һά��������ݽ�������*/
			{
				temp = *(p+j);
				*(p+j) = *(p+j+1);
				*(p+j+1) = temp;
			}
		}
}
