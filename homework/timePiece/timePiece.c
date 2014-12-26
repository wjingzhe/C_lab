//timepiece.c
#include "stdio.h"
#define getpch(type) (type*)malloc(sizeof(type)) 


struct pcb { /* ������̿��ƿ�PCB */ 
    char name[10]; 
    char state; /*״̬   */
    int ntime;  /*��Ҫ������ʱ��  */
    int rtime;  /*��ִ�е�ʱ�� */
    struct pcb* link; /*��һ�����̿��ƿ�ĵ�ַ */
    }*ready=NULL,*p; /*readyΪ�������У�pָ�����ڲ����Ľ��̽��в���*/

typedef struct pcb PCB;

insert()/*�տ�ʼʱ����Ҫ����Ľ���*/
{
    PCB *cur=ready,*nextpcb;
    if(ready==NULL)/*��������Ϊ��ʱ���������һ������ʱ*/
        ready=p;
    else/*�������в�Ϊ��*/
    {
		nextpcb=ready->link;
        while(nextpcb!=NULL)/*�ҵ����е����λ��*/
        {
            cur=nextpcb;
            nextpcb=nextpcb->link;
        }
        cur->link=p;/*�ѽ��̲��뵽�������*/

    }

}

input() /* �������̿��ƿ麯��*/ 
{ 
    int i,num;
    printf("\n ��������̸�����");
    scanf("%d",&num);
    for(i=0;i<num;i++) 
    { 
        printf("\n ���̺�No.%d:\n",i); /*����Ҫ����Ľ��̵���Ϣ*/
        p=getpch(PCB); 
        printf("\n ���������:"); 
        scanf("%s",p->name); 
        printf("\n �����������ʱ��:"); 
        scanf("%d",&p->ntime); 
        printf("\n"); 
        p->rtime=0;p->state='w'; 
        p->link=NULL; 
        insert(); /* ����insert����������Ľ��̲��뵽���к���*/
    } 
}


disp(PCB * pr) /*����������ʾ����,������ʾ��ǰ����*/ 
{ 
    printf("\nqname\tstate\tndtime\truntime\n");
    printf("%s\t",pr->name); 
    printf("|%c\t",pr->state); 
    printf("|%d\t",pr->ntime); 
    printf("|%d\t",pr->rtime); 
    printf("\n"); 
}


check() /* �������̲鿴���� */ 
{ 
    PCB* pr; 
    printf("\n **** ��ǰ�������еĽ�����:%s",p->name); /*��ʾ��ǰ���н���*/ 
    disp(p); 
    pr=ready; 
    printf("\n ****��ǰ��������״̬Ϊ:\n"); /*��ʾ��������״̬*/ 
    while(pr!=NULL) 
    { 
        disp(pr); 
        pr=pr->link; 
    } 
} 


destroy() /*�������̳�������(�������н���,��������)*/ 
{ 
    printf("\n ���� [%s] �����.\n",p->name); 
    free(p); 
}

run() /* �������̾�������(��������ʱ�䵽,�þ���״̬*/ 
{ 
    (p->rtime)++; 
    if(p->rtime>=p->ntime) 
        destroy(); /* ����destroy����*/ 
    else 
    { 
        p->state='w'; 
        insert(); /*����insert����*/
    } 
} 


main()/*������*/
{
    int len,h=0;
    char ch; 
    input(); /*���������*/
    while(ready!=NULL)/*�����в�Ϊ��ʱ��ѭ�����е���*/
    { 
        h++; 
        printf("\n The execute number:%d \n",h); 
        p=ready; 
        ready=p->link; 
        p->link=NULL; 
        p->state='R'; 
        check(); 
        run(); 
        printf("\n\n ����һ������......"); 
        ch=getchar(); 
    } 
    printf("\n\n �����Ѿ����.\n"); 
}
