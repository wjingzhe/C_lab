#include<malloc.h>
#include<math.h>
#include"BST.h"
bool InOrderTraverseAVL(BSTree T,bool(*Visit)(float e),float *BSTData,int &i)//�������ʷ���true��������ĳ���ڵ����ʧ���򷵻�false������ֹ���ʡ�
{
	if(T)
	{
		if(InOrderTraverseAVL(T->lchild,Visit,BSTData,i))
			if(Visit(T->data))
			{
				BSTData[i++] = T->data;
				if(InOrderTraverseAVL(T->rchild,Visit,BSTData,i)) 
					return true;
			}

		return false;
	}
	else
		return true;
}

float* InOrderAVL(BSTree T,bool (*Visit)(float e),int &n) //����������������ʷ���һ��float�����飬����ӡƽ��������������С�
{
	float *BSTData = (float*)malloc(sizeof(float)*(int)pow(2,GetHeightAVL(T)));//�������������Ϊ2^n����nΪ�߶�
	n = 0;
	if(InOrderTraverseAVL(T,Visit,BSTData,n))
		return BSTData;
	else
		return NULL;
}

float* InOrderAVL(BSTree T,int &n) //����������������ʷ���һ��float�����飬���鳤�ȡ�
{
	n = 0;
	float *BSTData = (float*)malloc(sizeof(float)*(int)pow(2,GetHeightAVL(T)));//�������������Ϊ2^n����nΪ�߶�
	if(InOrderTraverseAVL(T,Nothing,BSTData,i))
		return BSTData;
	else
		return NULL;
}