#include "stdio.h"
#include "conio.h"

#define getpch(type,size) (type*)malloc(sizeof(type)*size)
#define MINSIZE sizeof(FQ)*2

int memsize;/*ģ����ڴ��С*/
char *memfirst; /*ģ����ڴ���ռ���׵�ַ*/
int frees=-1;/*freeָ��ģ���ڴ�Ŀ��з������׵�ַ*/



struct fq/*�������Ľṹ*/
{
    int link;  /*ָ��ǰһ�����з�������ߺ�һ�����з�����*/
    int size;  /*���з����Ĵ�С*/
}*p=NULL;

typedef struct fq FQ;

int insert(int first,int fqsize)/*������з���ʱ������з���*/
{
    int tmp,tmp1,a;
    if(frees<0)/*���з���Ϊ��*/
    {
        frees=first;
        p=(FQ*)(memfirst+first);/*�ڿ��з������ײ�����¼�ÿ��з�������Ϣ��ǰ��ָ��*/
        p->link=-1; /*��Ϊ�ǵ�һ��,ǰ��ָ��Ϊ-1*/
        p->size=fqsize;
        /*printf("%d",(char*)p-memfirst); */
        p=(FQ*)(memfirst+first+fqsize-sizeof(FQ)); /*�ڿ��з�����β������¼�ÿ��з�������Ϣ��ǰ��ָ��*/
        p->size=fqsize;
        p->link=-1; /*��Ϊ�ǵ�1��,���Ժ���ָ��ҲΪ-1*/
        return 1;
    }
    else
    {
        if(first<frees) /*Ҫ����Ŀ��з����׵�ַС�������з������׵�ַ*/
        {
            if(first+fqsize>frees)/*�ж��Ƿ����ص�����*/
            {
                printf("���з����в����ص�!");
                return -1;
            }
            if(first+fqsize==frees)/*Ҫ����Ŀ��з����պÿ��Ժ���ǰ��ķ����ϲ�,�ͺ���ǰ��ķ����ϲ�*/
            {
                p=(FQ*)(memfirst+frees);
                p=(FQ*)(memfirst+frees+p->size)-1;
                p->size=p->size+fqsize;
                tmp=p->size;
                p=(FQ*)(memfirst+first);
                p->size=tmp;
                p->link=-1;
                frees=first;
                return 1;
            }
            p=(FQ*)(memfirst+first);/*������ܺϲ��Ͱ�������з������뵽��ǰ��*/
            p->size=fqsize;
            p->link=-1;
            p=(FQ*)(memfirst+first+fqsize)-1;
            p->size=fqsize;
            p->link=frees;
            p=(FQ*)(memfirst+frees);
            p->link=first+fqsize-sizeof(FQ);
            frees=first;
            return 1;
        }
        else/*���з�������Ӧ�ò��뵽��ǰ��*/
        {
            tmp=frees;
            p=(FQ*)(memfirst+frees);
            p=(FQ*)(memfirst+frees+p->size)-1;
            tmp1=p->link;
            while(first>tmp1&&tmp1!=-1)/*�ҵ�Ӧ�ò����λ��*/
            {
                p=(FQ*)(memfirst+tmp1);
                p=(FQ*)((char*)p+p->size)-1;
                tmp=tmp1 ;
                tmp1=p->link;
            }
            if(tmp1==-1)/*Ҫ����Ŀ��з����������п��з���*/
            {
                p->link=first;
                tmp=(char*)p-memfirst;
                p=(FQ*)(memfirst+first);
                p->size=fqsize;
                p->link=tmp;
                p=(FQ*)(memfirst+first+p->size)-1;
                p->size=fqsize;
                p->link=-1;
                return 1;
            }
            else
            {
                if(first+fqsize==tmp1)
                {
                    p=(FQ*)(memfirst+tmp1);
                    a=p->link;/*����ǰһ���з�����β��*/
                    p=(FQ*)(memfirst+tmp1+p->size)-1;
                    p->size=p->size+fqsize;
                    fqsize=p->size;/*���浱ǰ�Ĵ�С*/
                    p=(FQ*)(memfirst+first);
                    p->size=fqsize;
                    p->link=a;
                    p=(FQ*)(memfirst+a);
                    p->link=first;
                    return 1;
                }
                p->link=first;
                tmp=(char*)p-memfirst;
                p=(FQ*)(memfirst+first);
                p->size=fqsize;
                p->link=tmp;
                p=(FQ*)(memfirst+first+p->size)-1;
                p->size=fqsize;
                p->link=tmp1;
                tmp=(char*)p-memfirst;
                p=(FQ*)(memfirst+tmp1);
                p->link=tmp;
                return 1;

            }

        }
    }
    return -1;
}

make()/*��ʼ�����з�����*/
{
    int first,fqsize;
    char yn;
    printf("�������ڴ�Ŀռ��С���ֽ�Ϊ��λ����");
    scanf("%d",&memsize);
    memfirst=getpch(char,memsize);
    printf("======���濪ʼ������з���========\n");
    while(1)
    {
        printf("��������з������׵�ַ��");
        scanf("%d",&first);
        if(first<0)/*�ж��׵�ַ�Ƿ�Ϸ�*/
        {
            printf("�׵�ַ����С��0!����������!\n");
            continue ;
        }
        printf("��������з����Ĵ�С��");
        scanf("%d",&fqsize);
        if(fqsize<MINSIZE)
        {
            printf("���з�����С����С��%d!����������!\n",MINSIZE);
            continue ;
        }
        insert(first,fqsize);/*����insert�����Ŀ��з�������*/
        getchar();
        printf("�Ƿ����������з�����(Y/N)?");
        scanf("%c",&yn);
        if(yn!='y'&&yn!='Y') break;
    }
}       


display()/*��ʾĿǰ�Ŀ��з���״̬*/
{
    int next;
    FQ * hou;
    printf("======��ǰ���з�����״̬========\n�׵�ַ  \t��С\n");
    if(frees==-1) return ;
    p=(FQ*)(memfirst+frees);
    hou=(FQ*)((char*)p+p->size)-1;
    next=hou->link ;
    while(next!=-1)
    {
        printf("%d\t\t%d\n",(char*)p-memfirst,p->size);
        p=(FQ*)(memfirst+hou->link);
        hou=(FQ*)((char*)p+p->size)-1;
        next=hou->link;
    }
    printf("%d\t\t%d\n",(char*)p-memfirst,p->size);

}


int freemem()/*�����ڴ�*/
{
    char yn;
    int first,size,res;
    FQ *tmp1,tmp2;
    printf("������Ҫ���յ��ڴ����ַ:");
    scanf("%d",&first);
    printf("������Ҫ���յ��ڴ�Ĵ�С:");
    scanf("%d",&size);
    res=insert(first,size);
    if(res==1)
    {
        printf("��ַΪ:%d,��СΪ:%d���ڴ��ѳɹ�����!\n",first,size);
        return 1;
    }
    return -1;
}


int requestmen()/*�����ڴ�*/
{
    int size;
    FQ *tmp,*tmp1;
    printf("������Ҫ������ڴ��С:");
    scanf("%d",&size);
    if(size<0||size>memsize)
    {
        printf("Ҫ������ڴ��С̫���̫С!\n");
        return ;
    }
    p=(FQ*)(memfirst+frees);
    tmp=p;
    p=(FQ*)((char*)p+p->size)-1;
    if(p->size>=size)
    {
        if(p->size-size>=2*sizeof(FQ))/*���ʣ��ռ����2����FQ�Ĵ�С,�Ͱ�ǰ�沿�ַ����ȥ*/
        {
            p->size=p->size-size;
            size=p->size;/*�����µĿ��з�����С*/
            tmp1=(FQ*)((char*)(++p)-size);
            tmp1->size=size;
            tmp1->link=-1;
            frees=(char*)tmp1-memfirst;
            return (char*)tmp-memfirst;
        }
        else/*���ʣ��ռ�С��2����FQ�Ĵ�С,�Ͱ��������з��������ȥ*/
        {
            frees=p->link;
            return (char*)tmp-memfirst;
        }
    }
    while(p->size<size&&p->link!=-1)
    {
        p=(FQ*)(memfirst+p->link);
        tmp=p;
        p=(FQ*)((char*)p+p->size)-1;
    }
    if(p->size>=size)
    {
       if(p->size-size>=2*sizeof(FQ))
       {
            p->size=p->size-size;
            size=p->size;/*�����µĿ��з�����С*/
            tmp1=(FQ*)((char*)(++p)-size);
            tmp1->size=size;
            tmp1->link=tmp->link;
            p=(FQ*)(memfirst+tmp->link);
            p->link=(char*)tmp1-memfirst;
            return  (char*)tmp-memfirst;
       }
       else
       {
            tmp1=(FQ*)(memfirst+tmp->link);
            tmp1->link=p->link;
            tmp1=(FQ*)(memfirst+p->link);
            tmp1->link=tmp->link;
            return  (char*)tmp-memfirst;
       }
    }
    else
    {
        if(p->link==-1)
        {
            printf("û���㹻����ڴ�ɷ���!\n");
            return -1;
        }
    }
    return -1;
}

main()
{
    char yn;
    int res;
    make();
    display();
    while(1)
    {
        getchar();
        printf("�Ƿ�����ڴ�(Y/N)?");
        scanf("%c",&yn);
        if(yn=='y'||yn=='Y')
        {
            res=requestmen();
            if(res==-1) printf("����ʧ��!\n");
            else
            {
                printf("����ɹ�!�������ַΪ:%d\n",res);
                display();
            }

        }
        else
        {
            getchar();
            printf("�Ƿ�����ڴ�(Y/N)?");
            scanf("%c",&yn);
            if(yn=='y'||yn=='Y')
            {
                freemem();
                display();
            }
            else
            {
                getchar();
                printf("�Ƿ��˳�(Y/N)?");
                scanf("%c",&yn);
                if(yn=='y'||yn=='Y') break;
            }
        }
    }
}
