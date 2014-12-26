#include<stdio.h>
#include<malloc.h>
#define LH 1;
#define EH 0;
#define RH -1;

typedef struct BSTNode
{
	int data;
	int bf;
	struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

void R_Rotate(BSTree &p)
{
	//����*pΪ���Ķ�������������������
	//����֮��pָ���µ�������㣬
	//����ת����֮ǰ���������ĸ��ڵ�
	BSTNode *lc = p->lchild;    //lcָ��*p�������������
	p->lchild = lc->rchild;    //lc���������ҽ�Ϊ*p��������
	lc->rchild = p;
	p = lc;    //pָ���µĸ����
}//R_Rotate

void L_Rotate(BSTree &p)
{
	//����*pΪ���Ķ�������������������
	//����֮��pָ���µ�������㣬
	//����ת����֮ǰ���������ĸ��ڵ�
	BSTNode *rc = p->rchild;
	p->rchild = rc->lchild;
	rc->lchild = p;
	p = rc;
}//L_Rotate

void LeftBalance(BSTree &T)
{

	BSTNode *lc = T->lchild;
	switch(lc->bf)
	{
	case LH:
		T->bf = lc->bf = EH;;
		R_Rotate(T);
		break;
	case RH:
		BSTNode *rd = lc->rchild;
		switch(rd->bf)
		{
		case LH:T->bf = RH; lc->bf = EH;break;
		case EH:T->bf = lc->bf = EH;break;
		case LH:T->bf = EH; lc->bf = LH;break;
		}//swtich(rd->bf)
		rd->bf = EH;
		L_Rotate(T->lchild);
		R_Rotate(T);
	}//switch(lc->bf)

}//LeftBalance

void RightBalance(BSTree &T)
{

	BSTNode *lc = T->lchild;
	switch(lc->bf)
	{
	case LH:
		T->bf = lc->bf = EH;;
		R_Rotate(T);
		break;
	case RH:
		BSTNode *rd = lc->rchild;
		switch(rd->bf)
		{
		case LH:T->bf = RH; lc->bf = EH;break;
		case EH:T->bf = lc->bf = EH;break;
		case LH:T->bf = EH; lc->bf = LH;break;
		}//swtich(rd->bf)
		rd->bf = EH;
		L_Rotate(T->lchild);
		R_Rotate(T);
	}//switch(lc->bf)

}//RightBalance


int InsertAVL(BSTree &T,int e,bool &taller)
{
	if(!T)
	{
		T = (BSTree)malloc(sizeof(BSTNode));
		T->data = e;
		T->lchild = T->rchild = NULL;
		T->bf = EH;
		taller = true;
		return 1;
	}
	else {
		if(e == T->data)
		{//�Ѵ��ں�e��ͬ�ؼ��ֵĽ��
			taller = false;return 0;
		}
		if(e<T->data)
		{
			if(!InsertAVL(T->lchild,e,taller)) 
				return 0;
			if(taller)
			{
				switch(T->bf)
				{
				case LH:
					LeftBalance(T);
					taller = false;
					break;
				case EH:
					T->bf = LH;
					taller = true;
					break;
				case RH:
					T->bf = EH;
					talller = false;
					break;
				}//switch(T->bf)
			}
		}//if
		else {
			if(!InsertAVL(T->rchild,e,taller))
				return 0;
			if(taller)
			{
				switch(T->bf)
				{
				case LH:
					T->bf = EH;
					taller = false;
					break;
				case EH:
					T->bf = RH;
					talller = true; 
					break;
				case RH:
					RightBalance(T);
					talller = false;
					break;
				}//switch(T->bf)
			}
		}//else
		
	}//else

	return 1;
}//InsertAVL

