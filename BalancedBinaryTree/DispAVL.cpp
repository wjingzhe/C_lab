#include"BST.h"
#include<stdio.h>
int DispAVL(BSTree T,int i)//�԰�͹������������������������ʽ����ӡ��ʾ
{
	if(T) //����������ӡ����
	{
		DispAVL(T->rchild,i+1); //����������ȴ�ӡ������
		int j = 0;
		printf("\n");
		for(;j<2*i-1-1;j++) //ǰ2*i-2��Ϊ��
			printf("   ");
		printf("%6.1f",T->data); //��2*i-1��Ϊ���������
		DispAVL(T->lchild,i+1); //��ӡ������
	}
	return 1;
}