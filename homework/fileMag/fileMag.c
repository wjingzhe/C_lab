#include "stdio.h"
#define getpch(type,num) (type*)malloc(sizeof(type)*num)

struct ufd{ /* �û��ļ�Ŀ¼ */
    char filename[10];/*�ļ���*/ 
    char procode[3];/*������*/
    int length;
    }*p;

typedef struct ufd UFD;

struct mdf{ /* ��Ŀ¼MDF */
    char name[10]; 
    struct UFD* directory; /*��һ�����̿��ƿ�ĵ�ַ */
    }maindir[10];

typedef struct mdf MDF;

int usernum;
int filenum[10];

main()
{
    int i,j,tmp;
    FILE *fp;
    printf("=====���¿�ʼ����Ŀ¼=====\n");
    printf("������Ҫ������û���:");
    scanf("%d",&usernum);
    for(i=0;i<usernum;i++)
    {
        printf("�������%dҪ������û���:",i+1);
        scanf("%s",maindir[i].name);
    }
    printf("�û����������!\n");
    for(i=0;i<usernum;i++)
    {
        printf("�������%d���û���:%sҪ������ļ���(С��10):",i+1,maindir[i].name);
        scanf("%d",&filenum[i]);
        p=getpch(UFD,10);
        maindir[i].directory=p;
        printf("==����Ϊ��%d���û��Ĺ����ļ�==\n",i+1);
        for(j=0;j<filenum[i];j++)
        {
            printf("������Ҫ������ļ���:");
            scanf("%s",p[j].filename);
            printf("������Ҫ�������ļ�������(����3λ������,��Ӧ:��,д,ִ��.):");
            scanf("%s",p[j].procode);
            printf("������Ҫ������ļ��ĳ���:");
            scanf("%d",&p[j].length);
        }
        printf("������ɣ�");
    }

    fp=fopen("dat","wb");
    fwrite(&usernum,sizeof(int),1,fp);
    for(i=0;i<usernum;i++)
    {
        fwrite(maindir[i].name,sizeof(char)*10,1,fp);
    }
    for(i=0;i<usernum;i++)
    {
        fwrite(&filenum[i],sizeof(int),1,fp);
        p=maindir[i].directory;
        fwrite(p,sizeof(UFD),10,fp);
    }
    fclose(fp);
        printf("usernum:%d\n",usernum);
    for(i=0;i<usernum;i++)
    {
        printf("%s\n",maindir[i].name);
        p=maindir[i].directory;
        for(j=0;j<filenum[i];j++)
    	{
            printf("name:%s\n",p[j].filename);
            printf("code:%d\n",p[j].procode);
            printf("length:%d\n",p[j].length);
    	}
    }

}
