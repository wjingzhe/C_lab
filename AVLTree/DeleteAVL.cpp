#include<malloc.h>
#include"AVLTree.h"
int DeleteAVL(BSTree &T,float key,bool &lower)
{
	//0��ʾ�����ڸ�Ԫ�أ�1��ʾ����ɾ��
	if(!T) return 0;
	else if(key==T->data)
	{
		BSTree p,q = T;
		float temp; //���T���������е����ֵ����ΪT��������
		if(!T->rchild)                                 //Ҫɾ��û���������Ľ�㣬�ؽ�����������ɾ����㣨��Ҷ�ӽ�㣩
		{
			T = T->lchild;
			free(q);
			lower = true;
		}
		else if(!T->lchild)                            //Ҫɾ��û���������Ľ�㣬�ؽ�����������ɾ����㣨��Ҷ�ӽ�㣩
		{
			T = T->rchild;
			free(q);
			lower = true;
		}
		else                                //�����������У���*p�����������ֵ��Ϊ�µĸ���㣬��p��ΪҶ�ӽ��ɾ������������������������������������������
		{
			p = T->lchild;
			while(p->rchild)
			{
				p = p->rchild;
			}
			temp = p->data;
			DeleteAVL(T,temp,lower);      //temp��ֵһ�����ڣ���ΪҶ�ӽ��
			q->data = temp;
		}
	}//else_if
	else if(key<T->data) //���������м���ɾ��
	{
		if(!DeleteAVL(T->lchild,key,lower)) return 0;
		if(lower&&--T->bf<=-2)
		{
			RightBalance(T);
			lower = false;
		}//if_lower �൱��T���������²���һ����������Ĳ�ƽ��״̬

	}//else_if
	else //���������м���ɾ��
	{
		if(!DeleteAVL(T->rchild,key,lower)) return 0;
		if(lower&&++T->bf>=2)
		{
			LeftBalance(T);
			lower = false;
		}//if_lower �൱��T���������²���һ����������Ĳ�ƽ��״̬

	}//else

	return 1;//����ɾ��
}