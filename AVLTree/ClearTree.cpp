#include"AVLTree.h"
#include<malloc.h>
void ClearTree(BSTree &T)//����T��Ϊ�գ�������T
{	                        
	if(T) 
	{
		ClearTree(T->lchild);                          //����T��������
	    ClearTree(T->rchild);                          //����T��������
		free(T); 
		T=NULL; 
	}
}