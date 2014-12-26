#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define LEN sizeof(struct student)

struct student
{
    long num;
    float score;
    struct student *next;
};
int n;

struct student* creat(void)
{
    struct student *head;
    struct student *p1,*p2;
    n = 0;
    p1 = p2 =(struct student *)malloc(LEN);/*����һ���µ�Ԫ*/
    head = NULL;
    while(n<3)
    {
        n++;
        scanf("%ld,%f",&p1->num,&p1->score);
        if(n==1) head = p1;
        else p2->next = p1;
        p2 = p1;
        p1 =(struct student *)malloc(LEN);/*����һ���µ�Ԫ*/

    }
    p2->next = NULL;
    return head;
}

void print(struct student *head)
{
    struct student *p;
    printf("\nNow,these %d recoeds are:\n",n);
    p = head;
    while(p!=NULL)
    {
        printf("%ld,%f\n",p->num,p->score);
        p = p->next;
    }
}

struct student *del(struct student *head,long num)
{
    if(head==NULL) {printf("\nlist null! \n");return head;}
    struct student *p1,*p2;
    p2 = p1 = head;
    while(p1!=NULL&&num!=p1->num)
    {
        p2 = p1;
        p1 = p1->next;
    }//while
    if(p1==head)//ɾ����Ԫ��
    {
        head = p1->next;
        free(p1);
    }
    else if(p1==NULL)//�Ҳ�����Ԫ��
    {
        printf("Can't find the student whose number is %ld\n",num);
    }
    else//��ͨɾ��
    {
        p2->next = p1->next; //���ɾ������β��㣬��p1->next==NULL,���Ը���ͨɾ�����������һ����
        free(p1);
    }
    return head;
}//del

struct student *insert(struct student *head,struct student *stud)
{
    if(head==NULL) {printf("\nlist null! \n");return head;}
    struct student *p0,*p1,*p2;
    p2 = p1 = head;
    p0 = stud;
    while(p1!=NULL&&p1->num<p0->num)
    {
        p2 = p1;
        p1 = p1->next;
    }

    if(p1==NULL)//���뵽����β��
    {
        p2->next = p0;
        p0->next = NULL;
    }
    else if(p1==head)//p1->num>=p0->num����p0������Ԫ��֮ǰ
    {
        p0->next = head;
        head = p0;
    }
    else
    {
        p2->next = p0;
        p0->next = p1;

    }//if_else_if
    n++;
    return head;
}


int main()
{
    struct student *head,stu;
    long del_num;
    printf("input records:\n");
    head = creat();  /* ������������ͷָ�� */
    print(head); /* ������� */
    printf("\ninput the deleted number:");
    scanf("%ld",&del_num);/*����Ҫɾ����ѧ����*/
    head = del(head,del_num);/*ɾ��������ĵ�ַ*/
    print(head);
    printf("\ninput the inserted:");/*����Ҫ����Ľ��*/
    scanf("%ld,%f",&stu.num,&stu.score);
    head = insert(head,&stu);
    print(head);

    return 0;
}
