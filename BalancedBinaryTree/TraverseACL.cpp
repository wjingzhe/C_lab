#include"BST.h"
#include<stdio.h>
int TraverseAVL(BSTree T,int i)
{
	//��������0�����󷵻�-1��������ʾ����1
	if(!T)  	
	{
		printf("T is an empty tree.");
		return 0;//����
	}
	else 
	{
		return DispAVL(T,i);//������ʾ
	}
}