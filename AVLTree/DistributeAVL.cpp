#include<malloc.h>
#include"AVLTree.h"

bool DistributeAVL(BSTree &p,BSTree &q) //���Ѻ�ĵ�ɭ����������������ƽ���������ԭ����Ԫ�ز���ԭ������������ԭ��ָ������������ԭ������������Ϊ���������
{
	
	BSTree s = p;
	q = p->lchild;
	bool taller = false;
	InsertAVL(p->rchild,p->data,taller);
	p = p->rchild;
	free(s);
	s = NULL;
	return true;
}