#include<malloc.h>
#include<math.h>
#include"BST.h"
bool PreOrderTraverseAVL(BSTree T,bool (*Visit)(float e),float *BSTData,int &i)//�������ʷ���true��������ĳ���ڵ����ʧ���򷵻�false������ֹ���ʡ�
{
	if(T)
	{
		if(Visit(T->data))
		{
			BSTData[i++] = T->data;
			if(PreOrderTraverseAVL(T->lchild,Visit,BSTData,i))
				if(PreOrderTraverseAVL(T->rchild,Visit,BSTData,i)) 
					return true;
		}
		return false;
	}
	else
		return true;
}

float* PreOrderAVL(BSTree T,bool (*Visit)(float e),int &n) //ǰ��������������ʷ���һ��float�����飬����ӡƽ��������������С�
{
	float *BSTData = (float*)malloc(sizeof(float)*(int)pow(2,GetHeightAVL(T)));//�������������Ϊ2^n����nΪ�߶�
	n = 0;
	if(PreOrderTraverseAVL(T,Visit,BSTData,n))
		return BSTData;
	else
		return NULL;
}

float* PreOrderAVL(BSTree T,int &n)  //ǰ��������������ʷ���һ��float�����飬���鳤��
{
	n = 0;
	float *BSTData = (float*)malloc(sizeof(float)*(int)pow(2,GetHeightAVL(T)));//�������������Ϊ2^n����nΪ�߶�
	if(PreOrderTraverseAVL(T,Nothing,BSTData,n))
		return BSTData;
	else
		return NULL;
}