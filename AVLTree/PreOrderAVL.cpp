#include<malloc.h>
#include<math.h>
#include"AVLTree.h"
bool PreOrderAVL(BSTree T,bool (*Visit)(float e),float *BSTData,int &i)//�������ʷ���true��������ĳ���ڵ����ʧ���򷵻�false������ֹ���ʡ�
{
	if(T)
	{
		if(Visit(T->data))
		{
			BSTData[i++] = T->data;
			if(PreOrderAVL(T->rchild,Visit,BSTData,i))
			{
				if(PreOrderAVL(T->lchild,Visit,BSTData,i)) 
					return true;
				else
					return false;
			}
			else
				return false;
		}//if_Visit
		else 
			return false;
	}
	else
		return true;
}

float* PreOrderTraverseAVL(BSTree T,bool (*Visit)(float e),int &n) //ǰ��������������ʷ���һ��float�����飬����ӡƽ��������������С�
{
	float *BSTData = (float*)malloc(sizeof(float)*(int)pow(2,GetDepthAVL(T)));//�������������Ϊ2^n����nΪ�߶�
	n = 0;
	if(PreOrderAVL(T,Visit,BSTData,n))
		return BSTData;
	else
		return NULL;
}

float* PreOrderTraverseAVL(BSTree T,int &n)  //ǰ��������������ʷ���һ��float�����飬���鳤��
{
	n = 0;
	float *BSTData = (float*)malloc(sizeof(float)*(int)pow(2,GetDepthAVL(T)));//�������������Ϊ2^n����nΪ�߶�
	if(PreOrderAVL(T,Nothing,BSTData,n))
		return BSTData;
	else
		return NULL;
}