#include <iostream>   
using namespace std;  
#define N 100   
int a[N][N];  
int b[N];  
  
void copy(int n)  
  
{     
    int m=n/2;    
    for(int i=0;i<m;i++)       
        for(int j=0;j<m;j++)           
        {             
            //�����Ͻ�С���ֵ�����Ӧ�����Ͻ�С���ֵ             
            a[i][j+m]=a[i][j]+m;              
            //�����Ͻ�С���ֵ�����Ӧ�����½�С���ֵ             
            a[i+m][j]=a[i][j+m];              
            //�����Ͻ�С���ֵ�����Ӧ�����½�С���ֵ             
            a[i+m][j+m]=a[i][j];              
        }         
}  
void copyodd(int n)              // n/2Ϊ����ʱ�ĺϲ��㷨   
{   int m=n/2;    
    for(int i=0;i<m;i++)       
    {         
        b[i]=m+i;         
        b[m+i]=b[i];          
    }     
    for(i=0;i<m;i++)       
    {         
        //�����Ͻ�С���ֵ�����Ӧ�����½�С���ֵ         
        for(int j=0;j<m+1;j++)             
        {             
            if(a[i][j]>=m)                 
            {                 
                a[i][j]=b[i];                 
                a[m+i][j]=(b[i]+m)%n;                 
            }             
            else a[m+i][j]=a[i][j]+m;             
        }  
        //�����Ͻ�С���ֵ�����Ӧ�����ϽǺ����½�С���ֵ         
        for(j=1;j<m;j++)           
        {  
            a[i][m+j]=b[i+j];             
            a[b[i+j]][m+j]=i;             
        }         
    }     
}  
  
bool odd(int n)  
{  
    return n&1;  
}  
  
void makecopy(int n)  
{  
    if((n/2)>1&&odd(n/2))  
        copyodd(n);  
    else  
        copy(n);  
}  
  
void tourna(int n)  
{  
    if(n==1)  
    {  
        a[0][0]=0;  
        return;  
    }  
    if(odd(n))  
    {  
        tourna(n+1);  
        return;  
    }  
    tourna(n/2);  
    makecopy(n);  
}  
void main()  
{  
    int n,i,j; 
	printf("������Ҫ�μӱ������˶�Ա����:");
    scanf("%d",&n);
	printf("\n");
    tourna(n);  
    if(!odd(n))  
    {  
        for (i=0; i<n;i++)  
        {  
        if(i==0)  
            printf("�˶�Ա���: ");   
        else  
            if(i<10)
			    printf("������ %d��: ",i);
			else
				printf("������%d��: ",i);
        for(j=0; j<n;j++)  
            printf("%d ",a[i][j]);
		printf("\n");            
        }  
    }  
    else  
    {  
        for (i=0; i<=n-1;i++)  
        {  
            if(i==0)  
                printf("�˶�Ա���: ");  
            else  
                if(i<10)
			    printf("������ %d��: ",i);
			else
				printf("������%d��: ",i);  
            for(j=0; j<=n-1;j++)
				printf("%d ",a[i][j]);
			printf("\n");
        }  
    } getchar(); getchar();
}  