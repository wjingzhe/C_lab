#include <stdio.h>
#include <stdlib.h>

int main()
{
    void change(int *);

    int a[5][5],*p,i,j;
    printf("Input the matrix:\n");
    for(i = 0;i<5;i++)          //�������
        for(j = 0;j<5;j++)
        {
            scanf("%d",&a[i][j]);
        }

    p = &a[0][0];
    change(p);
    printf("Now,the matrix is :\n");

    for(i = 0;i<5;i++) //�������
    {
        for(j = 0;j<5;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}//main


void change(int *p)
{
    int i,j,temp,k;
    int *pmax,*pmin;
    pmax = p;
    pmin = p;
    for(i = 0;i<5;i++)    //Ѱ�����ֵ����Сֵ�ĵ�ַ��������pmax��pmin
    {
        for(j = 0;j<5;j++)
        {
            if(*pmax<*(p+5*i+j)) pmax = p+5*i+j;
            if(*pmin>*(p+5*i+j)) pmin = p+5*i+j;
        }
    }

    //���ֵ��������Ԫ��
    temp = *(p+12);
    *(p+12) = *pmax;
    *pmax = temp;

    //��Сֵ��������Ԫ��
    temp = *pmin;
    *pmin = *p;
    *p = temp;

    //Ѱ�ҵڶ�Сֵ��ַ����pmin
    pmin = p+1;//��ԭָ��pmin��λ�ã�ָ������һ�еڶ���Ԫ��

    for(i = 0;i<5;i++)    //Ѱ�ҵڶ�Сֵ�ĵ�ַ����ֵpmin
    {
        if(i==0) j = 1;
        else j = 0;
        for(;j<5;j++)
        {
            if(*pmin>*(p+5*i+j)) pmin = p+5*i+j;
        }
    }
    temp = *pmin;
    *pmin = *(p+4);
    *(p+4) = temp;

    pmin = p+1;//��ԭָ��pmin��λ�ã�ָ������һ�еڶ���Ԫ��

    for(i = 0;i < 5;i++)    //Ѱ�ҵ���Сֵ�ĵ�ַ��������pmin
    {
        if(i == 0) {j = 1,k = 4;}
        else {j = 0,k = 5;}
        for(;j < k;j++)
        {
            if(*pmin > *(p+5*i+j)) pmin = p+5*i+j;
        }
    }//for
    temp = *pmin;
    *pmin = *(p+20);
    *(p+20) = temp;

    pmin = p+1;//��ԭָ��pmin��λ�ã�ָ������һ�еڶ���Ԫ��

    for(i = 0;i < 5;i++)    //Ѱ�ҵ���Сֵ�ĵ�ַ��������pmin
    {
        if(i == 0) {j = 1,k = 4;}
        else if(i == 4) {j = 1,k = 5;}
        else {j = 0,k = 5;}
        for(;j < k;j++)
        {
            if(*pmin > *(p+5*i+j)) pmin = p+5*i+j;
        }
    }//for
    temp = *pmin;
    *pmin = *(p+24);
    *(p+24) = temp;
}//change
