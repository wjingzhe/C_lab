#include<iomanip>
#include<iostream>
using namespace std;
//��from[0]��from[right-left+1]������d
template <class T>
void Copy(T d[],T from[],int left,int right)
{
	int size = right-left+1;
	for(int i = 0;i<size;)
	{
		d[left++] = from[i++];
	}
}

//�ϲ���������a[left:i],a[i+1:right]��b���õ��µ���������b
template <class T>
void Merge(T a[],T b[],int left,int m,int right)
{
	int a1bg = left,
		a1end = m,
		a2bg = m+1,
		a2end = right,
		bbg = 0;
	for(int j=0;j<right-left+1;j++)//ִ��right-left+1��ѭ��
    {
    if(a1bg>a1end){b[bbg++]=a[a2bg++];continue;}//�����һ����������������ڶ��������Ԫ�ص�b
    if(a2bg>a2end){b[bbg++]=a[a1bg++];continue;}//����ڶ������������������һ�������Ԫ�ص�b
    if(a[a1bg]<a[a2bg]){b[bbg++]=a[a1bg++];continue;}//����������鶼û�������Ƚ�Ԫ�ش�С���ѽ�С�ķ���b
    else{b[bbg++]=a[a2bg++];continue;}
    }
}

template <class T>
void MergeSort(T a[],int left,int right)
{
	T *b = new T[right-left+1];
	if(left<right)
	{
		int m = (left+right)/2;
		MergeSort(a,left,m);//����
		MergeSort(a,m+1,right);
		Merge(a,b,left,m,right);//�ϲ�
		Copy(a,b,left,right);//���ƻ�ԭ����
	}	
	
}

void main()
{
	for(char c=0;c!='y'&&c!='Y';)
	{
		int n;
		cout<<"Numbers to sort:n=";
		cin>>n;
		long *a = new long[n];
		cout<<"Input "<<n<<" number:"<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<"a["<<i<<"]=";
			cin>>a[i];
		}
		MergeSort(a,0,n-1);
		for(int j=0;j<n;j++)
		{
			cout<<a[j]<<" ";
		}
		cout<<"Do you want to exit?(y/n)";
		char c;
		cin>>c;
	}
}