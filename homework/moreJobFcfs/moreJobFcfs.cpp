#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define getjcb(type) (type*)malloc(sizeof(type))
//#define NULL 0
 int j=0;
int n,i;           //��Ҫ�������ҵ����
float T1=0,T2=0;  //��ʼ����תʱ��,��Ȩ��תʱ��.
int times=0;      //��ʼ����ʼ����ʱ��
int freemem=100,taple=5;   //Ԥ���ڴ�Ĵ�СΪ100k,taple����Ϊ5��.

struct jcb      //��ҵ���ƿ�
{
 char username[10];   //�û���
 char name[10];  //��ҵ��
 int reachtime;   //��ҵ����ʱ��
 int starttime;    //��ҵ��ʼʱ��
 int runtime;    //�Ѿ������˵�ʱ��
 int needtime;       //��ҵ��Ҫ���е�ʱ��
 int freem;       //��ҵҪռ�õ��ڴ�
 int taples;    //��ҵ����taple 
 int finishtime;       //��ҵ���ʱ��
 //float cycletime;       //��ҵ��תʱ��
 //float cltime;           //��ҵ��Ȩ��תʱ��
 char state;            //��ҵ״̬
 struct jcb *next;      //�ṹ��ָ��
}*ready=NULL,*start=NULL,*p,*q,*r,*s,*t;
typedef struct jcb JCB;



void inital()           //������ҵ���ƿ����,�Ƚ����ų������ȷ����ģʽ����
{
	int i;
	printf("\n������ҵ��:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p=getjcb(JCB);
		printf("\n�����û���:");
		scanf("%s",p->username);
		printf("������ҵ��:");
		scanf("%s",p->name);
		p->reachtime=i;
		printf("��ҵĬ�ϵ���ʱ��:%d",i);
		printf("\n������ҵҪ���е�ʱ��:");
		scanf("%d",&p->needtime);
		printf("������ҵ����Ҫռ�õ��ڴ�:");
		scanf("%d",&p->freem);
		if(p->freem>freemem)
		{
			printf("������������ҵ����Ҫռ�õĺ����ڴ�:");
			scanf("%d",&p->freem);
		}
		printf("������ҵ��������taple :");
		scanf("%d",&p->taples);
		if(p->taples>taple)
		{
			printf("taple���㣬���������루0-5��:");
			scanf("%d",&p->taples);
		}
		p->runtime=0;
		p->state='W';
		p->next=NULL;
		if(ready==NULL)  ready=q=p;    //�Ƚ��䰴������Ⱥ�˳���ųɺ�����
		else{
			q->next=p;
			p->next=NULL;
			q = p; 
		}
	}
}

int count()     //�����ڴ�����ҵ�ĸ���
{
int i=0; JCB* pr=start;
while(pr!=NULL)
{
i++;
pr=pr->next;
}
return(i);
}


void apply()             //�ѷ�����������ҵ�����ڴ�,�������Ƿ�����Դ,
{
  int len;
  p=ready;
  while(p!=NULL)
    {

        if((p->freem<=freemem)&&(p->taples<=taple))
        {
            freemem-=p->freem;
            taple-=p->taples;
            r=p;
            p=p->next;
            
            if(r==ready)          //�Ƚ����������ľ�����ҵ�Ӻ󱸶����з������
            {
                ready=r->next;
                r->next=NULL;
            }
            else
            {
                q=ready;
                while(q->next!=r)  
				{q=q->next;}
                q->next=r->next;
            }
            if(start==NULL)  {start=s=r;}        // ����嵽start����,
            else
			{
               	s->next=r;
				r->next=NULL;
				s=r;
            }
        }
        else
        {
            p=p->next;

        }
    }
   len=count();
    printf("\n\t��ʱ��%d����ҵ���ڴ�\n\n",len);
}


void disp(JCB * pr) /*������ҵ��ʾ����  */

{
printf("|%s\t",pr->username);
printf("|%s\t",pr->name);
printf("|%c\t",pr->state);
printf("|%d\t",pr->reachtime);
printf("|%d\t",pr->needtime);
printf("|%d\t",pr->runtime);
printf("|%d\t",pr->freem);
printf("|%d\t",pr->taples);
printf("\n");

}





void check()      //��ʾ��ҵ״��
{

    printf("\n��ҵ%s�����%d����ҵ���������,����ɺ�����:",q->name,j);
    j++;
    printf("\n�û���--��ҵ��--״̬--����ʱ��-����ʱ-����ʱ-��ռ�ڴ�-��taple ���� \n");
    disp(q);
    s=start;
    printf("\n\t\t---------��ǰ�����ڴ����ҵ״̬---------");
    printf("\n�û���--��ҵ��--״̬--����ʱ��-����ʱ-����ʱ-��ռ�ڴ�-��taple ���� \n");
	if(s==NULL)
	{s=start;}
	else 
	{
		while(s->next!=NULL)
		{
			disp(s);
			s=s->next;
		}
	}
	disp(s);
    r=ready;
    printf("-\n\n\t\t---------��ǰ����ҵ������ҵ��״̬----------");
    printf("\n�û���--��ҵ��--״̬--����ʱ��-����ʱ-����ʱ-��ռ�ڴ�-��taple ���� \n");
    while(r!=NULL)
   {
     disp(r);
     r=r->next;
   }
}

                
                
void running()         //������ҵ
{
    for(t=start;t!=NULL;)
    {
        start=t->next;
        q=t;
        q->next=NULL;
        q->state='R';
        q->runtime++;
        t=start;
        times++;
        if(q->runtime==q->needtime)
        {
            q->finishtime=times;
            q->starttime=q->finishtime-q->needtime;
           // q->cycletime=(float)q->finishtime-q->reachtime;
           // q->cltime=(q->cycletime)/(q->needtime);
           // T1+=q->cycletime;
           // T2+=q->cltime;
            freemem+=q->freem;
            taple+=q->taples;
            check();     //����check()��ʾ�������е�,�������Լ��󱸵���ҵ��Ϣ
            free(q);    //�ͷ���ҵ
			getch();
            apply();    //������ҵ
            getch();
        }
        else
        {
			if(start!=NULL)
			{
			for(s=start;s->next!=NULL;)
			 {s=s->next;}
             s->next=q;
			 s=q;
			}
			else
			{
				start=q;
				printf("\n�û���--��ҵ��--״̬--����ʱ��-����ʱ-����ʱ-��ռ�ڴ�-��taple ���� \n");
			    disp(s);
				if(ready==NULL)
					printf("\nEnd of some work!Good luck!\n");
			}
			if(start==NULL&&ready!=NULL)
				apply();
        }
		
    }
}
            

                
void main()       //������
{
  printf("\n\n\t\t---------I hope to get a high mark!:)-----------\t\t\n");
  printf("\n\t\t.�����������ҵFCFS������ʾ.\n");
  inital();
  apply();
  running();
}

