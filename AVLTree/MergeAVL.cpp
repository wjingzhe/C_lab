#include<malloc.h>
#include"AVLTree.h"
#include<iostream>
using namespace std;

BSTree MergeAVL(BSTree &p,BSTree &q) // �ϲ�����ƽ�������
{
	int i = 0,j = 0;
	bool taller = false;
	float *BSTData = InOrderTraverseAVL(q,i);
	for(j = 0;j<i;j++)
	{
		if(!InsertAVL(p,BSTData[j],taller))
			cout<<"������ͬ��Ԫ��"<<endl;
	}
	ClearTree(q);
	return p;	
}