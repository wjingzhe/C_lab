#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINEMAX 20
int main()
{
    void sort(char * * p);
    int i;
    char * * p,*pstr[5],str[5][LINEMAX];
    for(i = 0;i < 5;i++)
        pstr[i] = str[i]; /* ����i���ַ������׵�ַ����ָ������pstr�ĵ�i��Ԫ�� */

    printf("input 5 strings:\n");

    for(i = 0;i < 5;i++)//����5���ַ���
    {
        scanf("%s",pstr[i]);
    }
    p = pstr;
    sort(p);
    printf("string sorted:\n");
    for(i = 0;i < 5;i++)
        printf("%s\n",pstr[i]);
    return 0;
}

void sort(char * * p) /* ð�ݷ���5���ַ��������� */
{
    int i,j;
    char *temp;
    for(i = 0;i < 5;i++)
    {
        for(j = i+1;j < 5;j++)
        {
            if(strcmp(*(p+i),*(p+j))>0) /* �ȽϺ󽻻��ַ�����ַ*/
            {
                temp = *(p+i);
                *(p+i) = *(p+j);
                *(p+j) = temp;
            }
        }
    }
}
