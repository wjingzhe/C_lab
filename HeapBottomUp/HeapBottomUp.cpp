#include<iostream>
#include<time.h>
#include<cstdlib> 
#include<vector>
#include<math.h>
using namespace std;

void InitHeap(int a[],int n)//��ʼ����ʵ�ֶѹ���
{
	for(int i=n/2;i>=1;i--)
	{
		int k = i,j = 0;
		int v = a[k];
		bool heap = false;
		while(!heap&&2*k<=n)//ʵ�ָ�ĸ����
		{
			j = 2*k;
			if(j<n)//������������
			{
				if(a[j]<a[j+1]) 
				{
					j = j+1;
				}
			}

			if(v>=a[j])
			{
				heap = true;
			}
			else 
			{
				a[k] = a[j];
				k = j;
			}
		}//while
		a[k] = v;
	}//for

}

void DispHeap(int a[],int m,int n)//����ʽ��ʾ
{   
	int i = m,k = log(i)/log(2),j;
	if(i<n)
	{
		cout<<endl;
		for(j=0;j<k;j++)
		{
			cout<<" ";
		}
		cout<<a[i];
		DispHeap(a,2*i,n);
		if(2*i<n)
		{
			DispHeap(a,2*i+1,n);
		}
		return;
	}
}



int* InsertNode(int a[],int &n,int elem)//�����½�㣬��������
{
	n++;
	int* b = new int[n]();
	b[0] = n;
	for(int count = 0;count<n-1;count++)
	{
		b[count] = a[count];
	}
	b[n-1] = elem;
	InitHeap(b,n);
	return b;
}

int SearchNode(int a[],int m,int n,int elem)//���ң����Ȳ��ҵ��±꣬�������ظ����
{
	int index = -1;
	int i = m;
	if(i<n)
	{
		if(a[i] == elem) 
		{
			index = i;
			return index;
		}
		else if(a[i]<elem) 
		{
			return index;
		}
		else if(2*i<=n)
		{
			i = 2*i;
			index = SearchNode(a,i,n,elem);//����������
			if(index==-1&&i<n)
			{
				i = i+1;
				index = SearchNode(a,i,n,elem);//����������
			}
		}
	}
	return index;
}

void DestroyHeap(int a[],int n)//���ٶ�
{
	for(int i = 1;i<n;)
	{	
		cout<<a[i]<<"--";
		a[i] = a[--n];
		InitHeap(a,n);
	}
}


void main()
{
	time_t timep; 
    struct tm *p;

	//ʱ�亯��
    char *wday[]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};   			                  
    time(&timep); 
	p=gmtime(&timep);

	bool flag = true;//ѭ������

	int n = 0;
	int* a;
	int* temp;
	cout<<"Press to enter..";
	
	do{	
		getchar();
		system("cls");
		char num;
		int elem,i,index;
		cout<<"\n-------------"<<endl;
		cout<<"1.��ʼ��"<<endl;
		cout<<"2.������"<<endl;
		cout<<"3.ɾ�����"<<endl;
		cout<<"4.���ҽ��"<<endl;
		cout<<"5.��ʾ��"<<endl;
		cout<<"6.���ٶ�"<<endl;
		cout<<"0.�˳�"<<endl;
		cout<<"����������ѡ���Ӧ������";
		cin>>num;
		switch (num){
		case '1'://��ʼ�� 
			system("cls");
			cout<<"�������������";
			cin>>n;
			n++;
			a = new int[n]();//a[0]������
			a[0] = n;
			cout<<"��������Ӧ��㣨�Կո�ֿ�����";
			for(i = 1;i<n;i++)
			{
				cin>>a[i];
			}
			InitHeap(a,n-1);
		    DispHeap(a,1,n);
			break;

		case '2'://����
			system("cls");
			int elem;
			cout<<"������Ҫ����Ľ�㣨���֣���";
			cin>>elem;
			temp = a;
			a = InsertNode(a,n,elem); //��n������в����½��
			delete(temp);
			DispHeap(a,1,n);
			break;

		case '3'://ɾ�� 
			system("cls");
			cout<<"������Ҫɾ���Ľ�㣨���֣���";
			cin>>elem;
			index = SearchNode(a,1,n,elem); 
			if(index!=-1)
			{
				for(i = index;i>1;)
				{
					i = i/2;
					a[index] = a[i];
					index = i;
				}
				n--;
				a[1] = a[n];
				InitHeap(a,n);
				cout<<endl<<elem<<"�ѱ�ɾ��";
				
			}else
			{
				cout<<"�����ڽ��"<<elem;
			}
			DispHeap(a,1,n);
			break;

		case '4'://����
			system("cls"); 
			cout<<"������Ҫ���ҵĽ�㣨���֣���";
			cin>>elem;
			index = SearchNode(a,1,n,elem);
			if(index==-1)
			{
				cout<<"�����ڽ��"<<elem;
			}else
			{
				cout<<elem<<"��λ��Ϊ:��"<<int(log(index)/log(2))+1<<"��,��"<<index-int(pow(2,log(index)/log(2)))+1<<"��";
			}
			DispHeap(a,1,n);
			break;

		case '5': 
			system("cls");
			DispHeap(a,1,n);
			break;

		case '6':
			system("cls");
			DestroyHeap(a,n);
			delete(a);
			break;

		case '0':
			flag = false;
			system("cls"); 
			break;
		}//switch

		getchar();
	}while(flag);

	cout<<1900+p->tm_year<<"��"<<1+p->tm_mon<<"��"<<p->tm_mday<<"��"; 
    cout << p->tm_hour << ":" <<p->tm_min << ":" <<p->tm_sec <<" " ;
}