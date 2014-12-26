#include"AVLTree.h"
bool IsAVL(BSTree T)//�ж��Ƿ�Ϊһ��ƽ�������,���򷵻�true�����򷵻�false
{
	if(T==NULL) return true;
	else if(T->lchild&&T->rchild)
		return (-2<T->bf)&&(T->bf<2)&&(T->lchild->data<T->data)&&(T->rchild->data>T->data)&&(IsAVL(T->lchild))&&(IsAVL(T->rchild));
	else if(T->rchild)
		return (-2<T->bf)&&(T->bf<2)&&(T->rchild->data>T->data)&&(IsAVL(T->rchild));
	else if(T->lchild)
		return (-2<T->bf)&&(T->bf<2)&&(T->lchild->data<T->data)&&(IsAVL(T->lchild));
	else
		return true;
}