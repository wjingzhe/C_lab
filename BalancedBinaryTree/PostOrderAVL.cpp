#include<malloc.h>
#include<math.h>
#include"BST.h"
bool PostOrderTraverseAVL(BSTree T,bool (*Visit)(float e),float *BSTData,int &i)//�������ʷ���true��������ĳ���ڵ����ʧ���򷵻�false������ֹ���ʡ�
{
	if(T)
	{
		if(PostOrderTraverseAVL(T->rchild,Visit,BSTData,i)) 
			if(Visit(T->data))
			{	
				BSTData[i++] = T->data;
				if(PostOrderTraverseAVL(T->lchild,Visit,BSTData,i))
					return true;
			}
		return false;
	}
	else
		return true;
}

float* PostOrderAVL(BSTree T,bool (*Visit)(float e),int &n) //����������������ʷ���float���飬����ӡƽ��������������С�
{
	float *BSTData = (float*)malloc(sizeof(float)*(int)pow(2,GetHeightAVL(T)));//�������������Ϊ2^n����nΪ�߶�
	n = 0;
	if(PostOrderTraverseAVL(T,Visit,BSTData,n))
		return BSTData;
	else
		return NULL;
}


float* PostOrderAVL(BSTree T,int &n)   //����������������ʷ���float���飬�Լ����鳤��
{
	n = 0;
	float *BSTData = (float*)malloc(sizeof(float)*(int)pow(2,GetHeightAVL(T)));//�������������Ϊ2^n����nΪ�߶�
	if(PostOrderTraverseAVL(T,Nothing,BSTData,n))
		return BSTData;
	else
		return NULL;
}
