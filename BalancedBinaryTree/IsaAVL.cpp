#include"BST.h"
bool IsaAVL(BSTree T)//�ж��Ƿ�Ϊһ��ƽ�������,���򷵻�true�����򷵻�false
{
	if(T==NULL) return true;
	else if(!T->lchild)
		return (-2<T->bf)&&(T->bf<2)&&(T->rchild->data>T->data)&&(IsaAVL(T->rchild));
	else if(!T->rchild)
		return (-2<T->bf)&&(T->bf<2)&&(T->lchild->data<T->data)&&(IsaAVL(T->lchild));
	else if(T->rchild&&T->rchild)
		return (-2<T->bf)&&(T->bf<2)&&(T->lchild->data<T->data)&&(T->rchild->data>T->data)&&(IsaAVL(T->lchild))&&(IsaAVL(T->rchild));
	else return false;
}