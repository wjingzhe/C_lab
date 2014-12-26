#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;

template<class T>
T* WarShall(T a[],int m,int n,int l)
{
	if(--l!=0)
	{
		T *b = WarShall(a,m,n,l);
		for(int k = 0;k<n;k++)
		{
			for(int i = 0;i<n;i++)
			{
				for(int j = 0;j<n;j++)
				{
					
					if(b[i*n+j]==1||(b[i*n+k]==1&&b[k*n+j]==1))//�жϱ�������ͨ·������ǰһ������ɼ����ͨ·
					{
						a[i*n+j] = 1;
					}
				}
			}
		}
	}//if �ݹ����

	return a;
}

void main()
{
	int n=0;
	cout<<"Make sure your file named \"warshallInput.txt\" had stored the adjacency matrix and then enter the dimension:";
	cin>>n;
	int* a = new int[n*n];
	ifstream fin("warshallInput.txt");
	char c;
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n+1;j++)
		{
			fin.read(reinterpret_cast<char *>(&c),sizeof(char));
			if(j<n) //����ÿ�еĻ��з�
			{
				a[i*n+j] = (int)c-48;//�ַ�ת����int�͡�
				cout<<a[i*n+j]<<" ";
			}
		}
		cout<<endl;
	}
	cout<<endl<<"Its adjacency matrix is:"<<endl;
	fin.close();

	WarShall(a,0,n,n);

	ofstream os("graph.txt");
	for(i = 0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			os<<a[i*n+j]<<" ";//���ļ��б����ڽӾ���
			cout<<a[i*n+j]<<" ";//��ʾ
		}
		os<<'\n';
		cout<<endl;
	}
	os.close();
	cin>>c;
}