#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 4
void main()
{
	char sign;
	int t;//�ж��ǲ��ҵ���t==0��ʱ���Ҳ�����
	int i,j,min,temp,a[n],m=n;
	int search(int* b);
	printf("Please input the nums:\n");
	for(i=0;i<n;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
				min=j;
			temp=a[i];
			a[i]=a[min];
			a[min]=temp;
			min=i;
		}

	}
	for(i=0;i<n;i++)
		{
			printf("%4d",a[i]);
		}
	printf("\n");
	sign='Y';
	while(sign=='Y')
	{
		 t=search(a);
         if(t==0)
         {
            printf("�Ҳ���������\n");
         }
         else
		 {
            printf("�ҵ��˸����֣��������������е��±��� %d\n",t);
         }
         printf("continue or not?(Y/N)\n");
		 scanf("%c",&sign);
	}
}

int search(int* a)
{
        int start=0,end=n-1,num,mid;//start�ǳ�ʼλ�ã�end ������λ��
        printf("Please intput number to look for:");
	    scanf("%d",&num);
		while(start<=end)
		{
		    mid=(start+end)/2;
			if(num==a[mid])
			{
				return mid;//�ҵ��Ļ��������ҵ���λ��
			}
		    else if(num>a[mid])
				{
					start=mid+1;
				}
			else
			{
			    end=mid-1;
			}
		}
		return 0;
}
