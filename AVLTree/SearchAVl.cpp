#include"AVLTree.h"
bool SearchAVL(BSTree T,float key,BSTree f,BSTree &p)
{
	//����ָ��T��ָ������������еݹ�ز�����ؼ��ֵ���key������
	//�����ҳɹ�����ָ��pָ�������Ԫ�ؽ�㲢����true��
	//����ָ��pָ�����·���Ϸ��ʵ����һ����㲢����false��ָ��fָ��T��˫�ף����ʼֵΪNULL
	if(!T)
	{p = f;return false;}
	else if(key==T->data) {p = T;return true;}
	else if(key<T->data) return SearchAVL(T->lchild,key,T,p);
	else return SearchAVL(T->rchild,key,T,p);
}//SearchAVL