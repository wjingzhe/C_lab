#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define LEN sizeof(struct node)

struct node
{
    int num;
    struct node *next;
};

int main()
{
    struct node *p1,*p2,*head;
    p2 = p1 = (struct node *)malloc(LEN);
    int i = 0;
    for(i = 0;i<13;i++)
    {
        p1->num = i;
        p1->next = NULL;
        if(i==0) head = p1;
        else p2->next = p1;
        p2 = p1;
        p1 = (struct node *)malloc(LEN);
    }//for

    p2->next = head;//���ѭ������
    free(p1);//���շ���p1����Ч�ռ�
    i = 0;//��ʼ��ѭ��������
    p2 = p1 = head;


    while(p2->next!=p2)
    {
        i++;
        if(i==3)//������һ
        {
            i=0;
            p1 = p1->next;
            p2->next = p1->next;
            free(p1);
        }
        p1 = p2 = p2->next;
    }//while

    head = p2;
    head->next = NULL;
    printf("%d\n",head->num);
    return 0;
}
