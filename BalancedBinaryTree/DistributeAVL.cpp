#include<malloc.h>
#include"BST.h"

BSTree DistributeAVL(BSTree p) //���Ѻ�ĵ�ɭ����������������ƽ���������ԭ����ָ��ԭ������������ԭ������������Ϊ����ֵ
{
	BSTree q = p->lchild,s = p;
	bool taller = false;
	InsertAVL(q,p->data,taller);
	p = p->rchild;
	free(s);
	return q;
}
