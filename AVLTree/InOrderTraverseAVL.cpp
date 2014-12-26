#include<malloc.h>
#include<math.h>
#include"AVLTree.h"
bool InOrderAVL(BSTree T,bool(*Visit)(float e),float *BSTData,int &i)//�������ʷ���true��������ĳ���ڵ����ʧ���򷵻�false������ֹ���ʡ�
{
	if(T)
	{
		if(InOrderAVL(T->rchild,Visit,BSTData,i))
		{
			if(Visit(T->data))
			{
				BSTData[i++] = T->data;
				if(InOrderAVL(T->lchild,Visit,BSTData,i)) 
					return true;
				else 
					return false;
			}
			else 
				return false;
			//if_else_Visit	
		}
		else
			return false;
	}//if_T
	else
		return true;
}

float* InOrderTraverseAVL(BSTree T,bool (*Visit)(float e),int &n) //����������������ʷ���һ��float�����飬����ӡƽ��������������С�
{
	float *BSTData = (float*)malloc(sizeof(float)*(int)pow(2,GetDepthAVL(T)));//�������������Ϊ2^n����nΪ�߶�
	n = 0;
	if(InOrderAVL(T,Visit,BSTData,n))
		return BSTData;
	else
		return NULL;
}

float* InOrderTraverseAVL(BSTree T,int &n) //����������������ʷ���һ��float�����飬���鳤�ȡ�
{
	n = 0;
	float *BSTData = (float*)malloc(sizeof(float)*(int)pow(2,GetDepthAVL(T)));//�������������Ϊ2^n����nΪ�߶�
	if(InOrderAVL(T,Nothing,BSTData,n))
		return BSTData;
	else
		return NULL;
}