#include<malloc.h>
#include"AVLTree.h"
void LeftBalance(BSTree &T);
void RightBalance(BSTree &T);

void R_Rotate(BSTree &p)
{
	//�����ӵ����������룺������룬��Ҫ����
	//����*pΪ���Ķ�����������������������֮��pָ���µĸ����
	//����תǰ���������ĸ����

	BSTree lc = p->lchild;  //lcָ��*p���������ĸ����
	p->lchild = lc->rchild; //lc�������ҽ�Ϊ*p������������p�ɹҽ�Ϊlc��������
	lc->rchild = p;
	p = lc;//ָ���µĸ��ڵ�
}//R_Rotate

void L_Rotate(BSTree &p)
{
	//���Һ��ӵ����������룺���Ҳ��룬��Ҫ����
	//����*pΪ���Ķ�����������������������֮��pָ���µĸ����
	//����תǰ���������ĸ����

	BSTree rc = p->rchild;  //rcָ��*p���������ĸ����
	p->rchild = rc->lchild; //rc�������ҽ�Ϊ*p������������p�ɹҽ�Ϊrc��������
	rc->lchild = p;
	p = rc;//ָ���µĸ��ڵ�
}//L_Rotate

void LeftBalance(BSTree &T)
{
	//����ָ��T��ָ����Ϊ���Ķ���������ƽ�⴦��
	//������������ָ��Tָ���µĸ��ڵ�
	BSTree lc = T->lchild;  //lcָ��T�����������ڵ�
	switch(lc->bf) //���lc��ƽ��ȣ�������Ӧ��ƽ�⴦��
	{
	case LH: //�½�������T�����ӵ��������ϣ�Ҫ�����������������ƽ���ΪEH
		T->bf = lc->bf = EH;
		R_Rotate(T);
		break;

	case RH: //�½ڵ������T�����ӵ��������ϣ�Ҫ��˫������������ң�
		BSTree rd = lc->rchild;       //rdָ��T�����ӵ������������
		switch(rd->bf)          //��������޸�T�Լ�����������ƽ�����ӣ�
		{          //��Ϊrd�����ӹҽ�Ϊlc���Һ��ӣ�rd���Һ��ӹҽ�ΪT������
		case LH:
			T->bf = RH;
			lc->bf = EH;
			break;

		case EH:
			T->bf = lc->bf = EH;
			break;

		case RH:
			T->bf = EH;
			lc->bf = LH;
			break;
		}//switch(rd->bf)

		rd->bf = EH;
		L_Rotate(T->lchild); //��T��������������ƽ�⴦��
		R_Rotate(T); //��T������ƽ�⴦��
	}//switch(lc->bf)
}//LeftBalance

void RightBalance(BSTree &T)
{
	//����ָ��T��ָ����Ϊ���Ķ���������ƽ�⴦��
	//������������ָ��Tָ���µĸ��ڵ�
	BSTree rc = T->rchild;  //lcָ��T�����������ڵ�
	switch(rc->bf) //���rc��ƽ��ȣ�������Ӧ��ƽ�⴦��
	{
	case RH: //�½�������T���Һ��ӵ��������ϣ�Ҫ���������������ƽ���ΪEH
		T->bf = rc->bf = EH;
		L_Rotate(T);
		break;

	case LH:      //�½ڵ������T���Һ��ӵ��������ϣ�Ҫ��˫���������Һ���
		BSTree ld = rc->lchild;    //ldָ��T���Һ��ӵ������������
		switch(ld->bf)               //��������޸�T�Լ�����������ƽ�����ӣ�
		{//��Ϊld�����ӹҽ�Ϊlc���Һ��ӣ�rd���Һ��ӹҽ�ΪT������
		case LH:
			T->bf = EH;
			rc->bf = RH;
			break;

		case EH:
			T->bf = rc->bf = EH;
			break;

		case RH:
			T->bf = LH;
			rc->bf = EH;
			break;
		}//switch(ld->bf)

		ld->bf = EH;
		R_Rotate(T->rchild); //��T��������������ƽ�⴦��
		L_Rotate(T); //��T������ƽ�⴦��
	}//switch(lc->bf)
}//Leftbalance322


bool InsertAVL(BSTree &T,float e,bool &taller)
{
	//����ƽ��Ķ���������T�в����ں�e����ͬ�ؼ��ֵĽ�㣬�����һ������Ԫ��
	//Ϊe���½ڵ㣬������1�����򷵻�0.��������ʹ����������ʧȥƽ�⣬����ƽ����ת����
	//��������taller��ӳT�������
	if(!T)
	{
		T = (BSTree)malloc(sizeof(BSTNode));
		T->data = e;
		T->lchild = T->rchild = NULL;
		T->bf = EH;
		taller = true;
		return true;
	}//if
	else
	{
		if(e==T->data)//�Ѵ���e�����ٲ���
		{
			taller = false;
			return false;
		}//if
		else if(e<T->data)//С��T->data����T���������м�������
		{
			if(!InsertAVL(T->lchild,e,taller)) return false; // δ����
			if(taller) //�Ѳ��뵽*T�����������������������ߡ�
				switch(T->bf)//���T��ƽ���
				{
					case LH://ԭ�����������������ߣ���Ҫ����ƽ�⴦��
						LeftBalance(T);
						taller = false;
						break;
					case EH://ԭ���ȸߣ��������������߶�ʹ������
						T->bf = LH;
						taller = true;
						break;
					case RH:// ԭ�����������������ߣ����ڵȸ�
						T->bf = EH;
						taller = false;
						break;
				}//switch(T->bf)
			return true;
		}//if_else
		else //��T���������м�������
		{
			if(!InsertAVL(T->rchild,e,taller)) return false;// δ����
			if(taller) //�Ѳ��뵽*T�����������������������ߡ�
				switch(T->bf) //���T��ƽ���
				{
					case LH: //ԭ�����������������ߣ����ڵȸ�
						T->bf = EH;
						taller = false;
						break;
					case EH: //ԭ���ȸߣ��������������߶�ʹ����������
						T->bf = RH;
						taller = true;
						break;
					case RH: //ԭ�����������������ߣ���Ҫ����ƽ�⴦��
						RightBalance(T);
						taller = false;
						break;
				}//switch(T->bf)
			return true;
		}//if_else if_else
		
	}//if_else

}//InsertACL

