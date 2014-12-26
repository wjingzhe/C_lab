#include<iostream>
#include<math.h>
using namespace std;

void InitHeap(int a[],int n)//��ʼ����ʵ�ֶѹ���
{
	for(int i=n/2;i>=1;i--)
	{
		int k = i,j = 0;
		int v = a[k];
		bool heap = false;
		while(!heap&&2*k<=n)//ʵ�ָ�ĸ����
		{
			j = 2*k;
			if(j>n)//������������
			{
				if(a[j]<a[j+1]) 
				{
					j = j+1;
				}
			}

			if(v>=a[j])
			{
				heap = true;
			}
			else 
			{
				a[k] = a[j];
				k = j;
			}
		}//while
		a[k] = v;
	}//for

}

void DispHeap(int a[],int m,int n)//����ʽ��ʾ
{
	int i = m,j;
	if(i<n)
	{
		cout<<endl;
		for(j=0;j<log(i)/log(2);j++)
		{
			cout<<" ";
		}
		cout<<a[i];
		DispHeap(a,2*i,n);
		if(2*i<n)
		{
			DispHeap(a,2*i+1,n);
		}
		return;
	}
}

void main()
{
	int a[7] = {0,2,9,7,6,5,8};
	InitHeap(a,6);
//	for(int i =1;i<7;i++)
//	{cout<<a[i]<<"--";}
	DispHeap(a,1,7);

}