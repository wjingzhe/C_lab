#include <stdio.h>
#include <stdlib.h>

/*
Last time i can't understand the codes in the book of answers.
Today i read it again,and i did.
Just because of teaching the knowledge of pointer to us,the answer in the book used a lot of pointer and variable,Although solving a simple quetion.
Now today i try to show it to my readers,some greenhands.
I will explain the complicated codes which are hard to anderstand.
*/

int main()
{
    char str[50],*pstr;//�ڱ������ߺ�ϲ����ͬ���岻ͬ���ı���ָ��ͬһ���ݡ�
    int i,j,k,m,e10,digit,ndigit,a[10],*pa;
    printf("input a string:\n");
    gets(str);//����������׳���������⣬�ַ����ᱻ�ضϣ�������ƽʱ��ҵ����ϲ������
    pstr = &str[0];//�ַ�ָ��pstr��������str�׵�ַ
    pa = &a[0];//ָ��pa��������a���׵�ַ
    ndigit = 0;
    i = 0;
    j = 0;

    while(*(pstr+i)!='\0')//δ���ַ�����β
    {
        if(*(pstr+i)>='0'&&*(pstr+i)<='9')
            j++;    //���������¼
        else
        {
            if(j>0) //j>0�����������ַ��������������������ַ�ֱ����������
            {
                digit = *(pstr+i-1)-48;//��i-1λ��ʼ����֪����i-1-j���ַ����������ַ����ȰѸ�λ��ֵ��digit
                k = 1;
                while(k<j)//��ʣ��λ�������ַ��ۼ���digit��
                {
                    e10 = 1;
                    for(m = 1;m<=k;m++)
                        e10 = e10*10;//e10��ʾ��λ��������

                    digit = digit + (*(pstr+i-1-k)-48)*e10;//�ַ����������

                    k++;
                }//while
                *pa = digit;
                pa++;
                ndigit++;
                j = 0;
            }//if

        }//if_else

        i++;//ÿ�ζ�ȡһ�����ַ�
    }//while

    if(j>0)//�����ַ����������ַ���β�����,ÿ�γ���ͬ������ʱ���Ӧ�ÿ����㷨�Ƿ������Ȼ�ǿ����޸ĵġ��ɲ�����һƪ����
    {
        digit = *(pstr+i-1)-48;
        k = 1;
        while(k<j)//��ʣ��λ�������ַ��ۼ���digit��
        {
            e10 = 1;
            for(m = 1;m<=k;m++)
                e10 = e10*10;//e10��ʾ��λ��������

            digit = digit + (*(pstr+i-1-k)-48)*e10;//�ַ����������

            k++;
        }//while
        *pa = digit;
        ndigit++;
        j = 0;
    }//if

    printf("There are %d numbers in this line.They are :\n",ndigit);
    j = 0;
    pa = &a[0];
    for(j = 0;j<ndigit;j++)
        printf("%d ",*(pa+j));
    printf("\n");

    return 0;
}
