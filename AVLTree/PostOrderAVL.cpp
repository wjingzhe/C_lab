#include<malloc.h>
#include<math.h>
#include"AVLTree.h"
bool PostOrderAVL(BSTree T,bool (*Visit)(float e),float *BSTData,int &i)//�������ʷ���true��������ĳ���ڵ����ʧ���򷵻�false������ֹ���ʡ�
{
	if(T)
	{
		if(PostOrderAVL(T->rchild,Visit,BSTData,i)) 
		{	
			if(PostOrderAVL(T->lchild,Visit,BSTData,i))
			{
				if(Visit(T->data))
				{
					BSTData[i++] = T->data;
					return true;
				}
				else 
					return false;
			}
			else
				return false;
		}//if_��
		return false;
	}//if_T
	else
		return true;
}

float* PostOrderTraverseAVL(BSTree T,bool (*Visit)(float e),int &n) //����������������ʷ���float���飬����ӡƽ��������������С�
{
	float *BSTData = (float*)malloc(sizeof(float)*(int)pow(2,GetDepthAVL(T)));//�������������Ϊ2^n����nΪ�߶�
	n = 0;
	if(PostOrderAVL(T,Visit,BSTData,n))
		return BSTData;
	else
		return NULL;
}


float* PostOrderTraverseAVL(BSTree T,int &n)   //����������������ʷ���float���飬�Լ����鳤��
{
	n = 0;
	float *BSTData = (float*)malloc(sizeof(float)*(int)pow(2,GetDepthAVL(T)));//�������������Ϊ2^n����nΪ�߶�
	if(PostOrderAVL(T,Nothing,BSTData,n))
		return BSTData;
	else
		return NULL;
}
