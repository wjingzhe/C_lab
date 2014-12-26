#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 /****************************************************
  copyright��Personal Telphone
  Filename��  MyContact.cpp
  Version: C++6.0
  Date: 2012.12.19
  Description: ���ڶ����������ĸ���ͨѶ¼
  Function List:
               initdata()  ��ʼ����������
               insert()    �����ϵ��
               find()      ������ϵ��
               change()    �޸���ϵ����Ϣ
               del()       ɾ����ϵ��
               destory()   �ͷſռ�
 *******************************************************/

 int current = 0;          //���ͨѶ¼����
 int flag;                        //���ҽ�����

 typedef struct student
 {
     char name[20];
     char number[11];
     char bir[10];
     char tel[15];
 }student;                   //�����������ṹ��

 student myClass[50];

 typedef struct tree
 {
     struct student *people;
     struct tree *left;
     struct tree *right;
 }tree;                       //������

 tree *root = NULL;       //���ڵ��ʼ��Ϊ��

 void initdata()                      //���õ���ϵ�˵ĳ�ʼ��
 {
     strcpy( myClass[current].name,"·�˼�");
     strcpy( myClass[current].bir,"19900101");
     strcpy( myClass[current].tel,"11111111111");
     strcpy( myClass[current].number,"311100001");
     current++;
     strcpy( myClass[current].name,"��Ա��");
     strcpy( myClass[current].bir,"19900202");
     strcpy( myClass[current].tel,"22222222222");
     strcpy( myClass[current].number,"311100002");
     current++;
     strcpy( myClass[current].name,"���ݱ�");
     strcpy( myClass[current].bir,"19900303");
     strcpy( myClass[current].tel,"3333333333");
     strcpy( myClass[current].number,"311100003");
     current++;
     strcpy( myClass[current].name,"���Ƕ�");
     strcpy( myClass[current].bir,"19900404");
     strcpy( myClass[current].tel,"88888888888");
     strcpy( myClass[current].number,"311100008");
     root = (tree *)malloc(sizeof(tree));
     root->people = &myClass[0];
     root->left = NULL;
     root->right = NULL;
 }


 void insert(tree * root,student *q)              //�����������ѧ�ŵݹ����
 {
     flag = 0;
    if(strcmp(root->people->number,q->number) == 0)
     {
         printf("���벻�ɹ�,��ͬѧ�ŵ����Ѵ���\n");
		 flag = 1;
         return;
     }//if

    else if(strcmp(root->people->number,q->number) > 0 )
    {
         if(root->left == NULL)
		{
         tree *p = (tree *)malloc(sizeof(tree));
         p->people = q;
         p->left = NULL;
         p->right = NULL;
         root->left = p;
		}
		else
		 {
			insert(root->left,q);
		 }
    }//if
    else
     {
        if( root->right == NULL)
		 {
			 tree *p = (tree *)malloc(sizeof(tree));
			 p->people= q;
			 p->left = NULL;
			 p->right = NULL;
			 root->right = p;
		 }
		else
		{
			insert(root->right,q);
		}
	}//if_else_if
}//insert

 int find(tree *root,char *p)                    //�ȸ���������
  {
      int flag;
      if( root!= NULL )
      {
         if( strcmp(root->people->name,p) == 0)
		 {
			 printf("���ҵ�����ϵ��:\n");
             printf("����:%s      ѧ��:%s      ����:%s      �绰:%s\n",root->people->name,root->people->number,root->people->bir,root->people->tel);
             return 1;                                  //���ҳɹ����
		 }
		flag = find(root->left,p);
		if(flag>0)
		{
          return 1;
		}
		flag = find(root->right,p);
	    if(flag > 0)
		{
			  return 1;
		}
     }
      return 0;
 }//find

 int change(tree *root,char *p)          //�ȸ����������ҵ����޸�
 {
    int flag;
    if(root != NULL)
     {
        if( strcmp(root->people->name,p) == 0)
		{
          int accept = 0;
          char buff[20];
          while(1)
		  {
              if(accept == 5)
               {
				  system("cls");
				  break;
			  }
			  printf("����:%s      ѧ��:%s      ����:%s      �绰:%s\n",root->people->name,root->people->number,root->people->bir,root->people->tel);
			  printf("������Ҫ�޸ĵ�ѡ��:\n");
			  printf("1 �޸�����\n");
			  printf("2 �޸�ѧ��\n");
			  printf("3 �޸�����\n");
			  printf("4 �޸ĵ绰\n");
			  printf("5 �˳�\n");
			  printf("������:");
			  scanf("%d",&accept);
			 switch(accept)
			  {
              case 1:
              {
                   system("cls");
                   printf("����������޸�Ϊ:");
                   scanf("%s",buff);
                   strcpy(root->people->name,buff);
                   printf("�޸ĳɹ�\n");
                   break;
                }
              case 2:
              {
                    system("cls");
                    printf("�����ѧ���޸�Ϊ(9λ31110��ͷ):");
                    scanf("%s",buff);
                    strcpy(root->people->number,buff);
                    printf("�޸ĳɹ�\n");
                    break;
               }
              case 3:
               {

                    system("cls");
                    printf("�������հ��޸�Ϊ:");
                   scanf("%s",buff);
                    strcpy(root->people->bir,buff);
                    printf("�޸ĳɹ�\n");
                    break;
               }
               case 4:
               {
                    system("cls");
                    printf("����ѵ绰�޸�Ϊ(11λ):");
                    scanf("%s",buff);
                    strcpy(root->people->tel,buff);
                    printf("�޸ĳɹ�\n");
                    break;
               }
               case 5:
               {
                    break;
               }
               default:
               {
                    printf("������������������\n");
                    break;
               }

			}//switch

		 }//while
          return 1;
    }//if

     flag = change(root->left,p);
     if(flag >0 )
     {
        return 1;
     }
    flag = change(root->right,p);
     if(flag >0)
     {
         return 1;
     }
   }//if
     return 0;
}//change

 void print(tree *root)
 {
     if(root != NULL)
    {
        printf("\n����:%s      ѧ��:%s      ����:%s      �绰:%s",root->people->name,root->people->number,root->people->bir,root->people->tel);
        print(root->left);
		putchar('\n');
        print(root->right);
     }
 }

 tree * findparent(char *p,tree *root,tree *parent)               //��Ѱ��ɾ�����ĸ�ĸ���
  {
    if( root != NULL)
     {
         if( strcmp(root->people->name,p) == 0 )
    {
         return parent;                                 //�ͷ��ؽ�����ڲ������
     }
         parent = findparent(p,root->left,root);
     if(parent != NULL)
     {
         return parent;
     }
    parent = findparent(p,root->right,root);
     if(parent != NULL)
     {
        return parent;
     }
     }
     return NULL;
 }

 void my_remove(tree *parent,tree *child)                 //ɾ�����
 {
     if(child->left == NULL && child->right == NULL)       //Ҷ�ӽڵ�
     {
         tree *temp = child;
     if(temp == root)                        //ɾ�����Ǹ�
     {
        root = NULL;
         free(temp);
         return;
     }
     if(parent->left == child)                 //�ж��Ǹ�ĸ�����ӻ����Һ���
    {
         parent->left = NULL;
     }
     else
     {
         parent->right = NULL;
     }
        free(temp);
     }
     else
    {
         if( child->left != NULL && child->right == NULL)          //1�Ƚ��
     {
         if(parent == NULL)                             //ɾ�����Ǹ����
         {
             root = root->left;
               free(child);
         return;
         }
        if( parent->left == child)                    //�ж����Һ��ӣ����丸ĸ����
         {
            parent->left = child->left;
         }
         else
         {
             parent->right = child->left;
         }
         free(child);
     }
     else
     if( child->left == NULL && child->right != NULL)
     {
         if(parent == NULL)
         {
             root = root->right;
                 free(child);
         return;
         }
         if( parent->left == child)
        {
             parent->left = child->right;
         }
        else
         {
             parent->right = child->right;
         }
        free(child);
     }
     else                                               //���Ƚ��
     {
         tree *temp,*temppar;
         temp = child->right;
         temppar = child;
         while(temp->left != NULL)                //�����и������µĺ�̽��
         {
             temppar = temp;
             temp = temp->left;
        }
         strcpy(child->people->name,temp->people->name);
         strcpy(child->people->bir,temp->people->bir);
         strcpy(child->people->tel,temp->people->tel);
         strcpy(child->people->number,temp->people->number);
         if( temppar == child)                              //��̽��Ϊ��ɾ������Һ���
         {                                                  //ע���������
             temppar->right = temp->right;
         }
         else
         {
             temppar->left = temp->right;
        }
         free(temp);
     }
     }
 }

 void del(char *q)
 {
     tree *parent;
     parent = findparent(q,root,NULL);
     if( parent == NULL && ( strcmp( root->people->name,q) != 0 ))
     {
         printf("ͨѶ¼��û�д���ϵ��,ɾ��ʧ��\n");
    return;
     }
     if( parent == NULL)                                //ɾ�������������ҵ��丸ĸ��㣬��
     {                                                  //�����ɾ��
         my_remove(parent,root);
    }
      else
     {
         if(  parent->left != NULL && (strcmp(parent->left->people->name,q) == 0 ) )
     {
        my_remove(parent,parent->left);
     }
     else
     {
         my_remove(parent,parent->right);
     }
     }
 }

void destory(tree *root)
{
    if(root != NULL)                    //�ͷſռ�
    {
        destory(root->left);
        destory(root->right);
        free(root);
     }
 }

 void disp()
 {
     int fun;
     char accept[20];
     while(1)
     {
		  fun = 5;
		  printf("������ϵ�����£�\n");//���������
		  print(root);
		  printf("         ������Ҫѡ��Ĺ���\n");
		  printf("/************************************/\n");
		  printf("         1.�����ϵ��\n");
		  printf("         2.�޸���ϵ����Ϣ\n");
		  printf("         3.������ϵ��\n");
		  printf("         4.ɾ����ϵ��\n");
		  printf("         5.�˳�\n");
		  printf("/************************************/\n");
		  printf("������:");
		  scanf("%d",&fun);
		  if(fun=='1'||fun=='2'||fun=='3'||fun=='4'||fun=='5')
		  {
			  switch(fun)
			  {
				 case 1:
				{
					 system("cls");
					  if(root == NULL)
					   {
						  current++;
						  root = (tree *)malloc(sizeof(tree));
						  printf("������Ҫ��ӵ���ϵ������\n");
						  scanf("%s",accept);
						  strcpy(myClass[current].name,accept);

						  printf("������Ҫ�����ϵ��ѧ��(9λ:31110��ͷ)\n");
						  scanf("%s",accept);
						  strcpy(myClass[current].number,accept);

						  printf("������Ҫ��ӵ���ϵ������\n");
						  scanf("%s",accept);
						  strcpy(myClass[current].bir,accept);

						  printf("������Ҫ��ӵ���ϵ�˵绰(11λ)\n");
						  scanf("%s",accept);
						  strcpy(myClass[current].tel,accept);

						 root->people = &myClass[current];
						 root->left = NULL;
						 root->right = NULL;
						 printf("������\n");
						 break;
					 }//if
					  current++;
					  printf("������Ҫ��ӵ���ϵ������\n");
					  scanf("%s",accept);
					  strcpy(myClass[current].name,accept);

					  printf("������Ҫ��ӵ���ϵ��ѧ��(9λ:31110��ͷ)\n");
					  scanf("%s",accept);
					  strcpy(myClass[current].number,accept);

					  printf("������Ҫ��ӵ���ϵ������\n");
					  scanf("%s",accept);
					  strcpy(myClass[current].bir,accept);

					  printf("������Ҫ��ӵ���ϵ�˵绰(11λ)\n");
					  scanf("%s",accept);
					  strcpy(myClass[current].tel,accept);

					  insert(root,&myClass[current]);

					  if(flag == 1)
					  {
						  break;
					  }
					  printf("������\n");
					  break;
				}//case1

				case 2:
				  {
				   system("cls");
				   if(root == NULL)
				   {
					   printf("ͨѶ¼Ϊ��\n");
					   break;
				   }
				   printf("������Ҫ�޸ĵ���ϵ������:\n");
				   scanf("%s",accept);
				   fun = change(root,accept);
				   if(fun == 0)
				   {
					   printf("û����Ҫ��ϵ��\n");
				   }
				   break;
				}//case2

				case 3:
				 {
				   system("cls");
				   if(root == NULL)
				   {
					   printf("ͨѶ¼Ϊ��\n");
				   break;
						  }
				   printf("������Ҫ���ҵ���ϵ������:\n");
				   scanf("%s",accept);
				  fun = find(root,accept);
				   if(fun == 0)
				   {
					  printf("��ϵ��δ�ҵ�\n");
				   }
				   break;
				}//case3

				case 4:
				{
				  system("cls");
				 if( root == NULL)
				  {
					 printf("ͨѶ¼Ϊ��\n");
					 break;
					}
				   printf("������Ҫɾ������ϵ������:");
				   scanf("%s",accept);
				   del(accept);
				   break;
				 }//case4

				 case 5:
				 {
				   system("cls");
				   printf("�����������\n");
				   destory(root);
				   printf("��лʹ�ñ�ͨѶ¼!\n");
				   exit(0);
				 }//case5

				 default:
				 {
				   system("cls");
				   printf("������������������!\n");
				   break;
				 }//default

			}//switch
		}//if
		else continue;
     }//while
 }//disp

  int main()
  {
     int i;
     printf("���ڳ�ʼ��ϵͳ\n");
     initdata();
     for(i = 1;i <= current;i++)
     {
         insert(root,&myClass[i]);
     }
     disp();
     return 0;
 }
