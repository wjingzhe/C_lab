#include"BST.h"
#include<math.h>
#include<malloc.h>
#include<stdlib.h>

bool CreateAVL(BSTree &T)//ֻ������T��Ϊ����,�򹹽�һ�ÿ���AVL��������true
{
	//����ո���
	ClearTree(T);
	return true; 
}

bool CreateAVL(BSTree &T,int n)//ֻ������T��Ϊ����,���������һ�ú���n����Ч���ݵ�AVL��������ʾ������true
{
	//��ո���
	ClearTree(T);
	int i;
	float *temp = (float *)malloc(sizeof(float)*n);
	for(i = 0;i<n;i++)
	{
		bool taller = false;
		temp[i]= rand()%100;
		if(!InsertAVL(T,temp[i],taller)) i--;//������ͬ���ݣ��������������
	}
	return true; 
}


bool CreateAVL(BSTree &T,float *a,int n)   //�����������������������鳤�ȣ�����һ��AVL��,ȫ��Ԫ�ؾ�Ϊ�����򷵻�false
{
	bool flag;
	int i = 0;
	bool taller = false;
	for(i = 0;i<n;i++)
	{
		taller = false;
		flag = InsertAVL(T,a[i],taller)||flag;
	}
	return flag;
}