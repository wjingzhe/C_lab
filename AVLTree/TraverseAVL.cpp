#include"AVLTree.h"
#include<stdio.h>
int TraverseAVL(BSTree T)
{
	//��������0�����󷵻�-1��������ʾ����1
	if(!T)  	
	{
		printf("T is an empty tree.");
		return 0;//����
	}
	else 
	{
		return DispAVL(T,1);//������ʾ
	}
}