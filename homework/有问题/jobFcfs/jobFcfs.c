//jobFcfs.c
#include"stdio.h"
#include<stdlib.h>
#include<conio.h>
#define getpcb(type) (type*)malloc(sizeof(type))
#define getjob(type) (type*)malloc(sizeof(type))
struct job { /* ������ҵ���ƿ�job */ 
    char name[10]; 
    char state; /*״̬   */
	int super;/*���ȼ�*/
    int ntime;  /*��Ҫ������ʱ��  */
    int rtime;  /*��ִ�е�ʱ�� */
}*j; /*readyΪ�������У�pָ�����ڲ�������ҵ���в���*/

typedef struct job JOB;

int jInput() /* ������ҵ�б���*/ 
{ 
    int i,num;
    printf("\n ��������ҵ������");
    scanf("%d",&num);
    for(i=0;i<num;i++) 
    { 
		j=getjob(JOB);
		char chEnter,filename[10];
		scanf("%s",filename);
		job work;
        printf("\n ��ҵ��No.%d:\n",i); /*����Ҫ�������ҵ��Ϣ*/
        printf("\n ������ҵ��:"); 
        scanf("%s",&j->name); 
		chEnter=getch();
        printf("\n �������ȼ�");
		scanf("%d",&j->super);
        printf("\n ������ҵ����ʱ��:"); 
        scanf("%d",&j->ntime); 
        printf("\n"); 
        j->rtime=0;j->state='w';
        insert(); /* ����insert�������������ҵ���뵽���к���*/
		return 0;
    } 
}

int jInsert()/*�տ�ʼʱ����Ҫ�������ҵ*/
{
	FILE *fp;
    if((fp=fopen(filename,"ab+"))==NULL)
		{
			printf("�޷����ļ�");
			exit();
		}
	chEnter=getch();
	fwrite(p,sizeof(pcb),1,fp);
	fclose(fp);
	return 0;

}

int jDisp(JOB * jr) /*������ҵ��ʾ����,������ʾ��ǰ��ҵ*/ 
{ 
	static job i;
    printf("\nqname\tstate\tndtime\truntime\n");
	if((fp1=fopen(filename,"rb+"))==NULL)
		{
			printf("�޷����ļ�");
			exit();
		}
	chEnter=getch();
	fseek(fp1,i,0);
	fread(jr,sizeof(jcb),1,fp1);
    printf("%s\t",jr->name); 
    printf("|%c\t",jr->state); 
    printf("|%d\t",jr->ntime); 
    printf("|%d\t",jr->rtime); 
    printf("\n"); 
	fclose(fp);
	i++;
}


int jCheck() /* ������ҵ�鿴���� */ 
{ 
    JOB* jr; 
    printf("\n **** ��ǰ�������еĽ�����:%s",p->name); /*��ʾ��ǰ������ҵ*/ 
	pr=getjob();
	jDisp(p); 
	free(jr)��
} 


 int jDestroy() /*������ҵ��������(�������н���,��������)*/ 
{ 
    printf("\n ��ҵ [%s] �����.\n",p->name); 
}

int  jRun() /* ������ҵ��������(��ҵ����ʱ�䵽,�þ���״̬*/ 
{ 
    jDestroy(); /* ����destroy����*/ 
    
} 


typedef struct pcb PCB;
input() /* �������̿��ƿ麯��*/ 
{
	static int h=0;
    printf("\n ���̺�No.%d:\n",h); /*ִ�н��̵���Ϣ*/
    p=getpcb(PCB); 
	p=j;
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
    } 
} 


destroy() /*�������̳�������(�������н���,��������)*/ 
{ 
    printf("\n ���� [%s] �����.\n",p->name); 
    free(p); 
}

run() /* �������̾�������(��������ʱ�䵽,�þ���״̬*/ 
{ 
    destroy(); /* ����destroy����*/ 
	k++
} 

int pmain()
{
	int len;
    char ch; 
    input(); /*���������*/
    while(ready!=NULL)/*�����в�Ϊ��ʱ��ѭ�����е���*/
    { 
        h++; 
        printf("\n\n The execute number:%d \n",h); 
        input()
        check(); 
        run(); 
        printf("\n ����һ������......"); 
        ch=getchar(); 
    } 
    printf("\n\n �����Ѿ����.\n"); 
}

int main()/*������*/
{
    int len,h=0;
    char ch5,ch6; 
    input(); /*������ҵ��*/
    while(1)/*�����в�Ϊ��ʱ��ѭ�����е���*/
    { 
        
        pmain();
		if((ch6=='Y')||(ch6=='y'))
		{
			exit(0);
		}
    } 
}

