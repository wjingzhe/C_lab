#include <stdio.h>
#include <stdlib.h>

//#define NULL 0 /* ������ʧ��ʱ���ر�־ */
#define ALLOCSIZE 1000 /* ��󿪱ٴ�ȡ */
char *alloc(int n);
void free1(char *p);
char allocbuf[ALLOCSIZE]; /* ����һ���ڴ����������c����ϵͳʹ�������ڴ濪�ٺ������*/
char *allocp = allocbuf; /* ָ��ָ���һ���ɴ�����ʼ�� */
int main()
{

    char *c = alloc(3);
    printf("%ld\n",c);
    free(c);
    return 0;
    printf("%ld\n",c);
}

char *alloc(int n)
{
    if(allocp+n <= allocp+ALLOCSIZE)
    {
        allocp += n;
        return allocp-n;
    }
    else
        return(NULL);
}

void free1(char *p)
{
    if(p>=allocbuf&&p<allocbuf+ALLOCSIZE)
        allocp = p;
}
