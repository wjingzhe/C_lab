#include <stdio.h>
#include <math.h>

/* ��������Ƿ�Ϊ���� */
int Leap(int year)
{
	if(((year%4==0)&&(year%100!=0))||(year%400==0))
		return 1;
	else
		return 0;
}

int Day(int y,int m,int d)//-1��ݲ�����-2�·ݲ�����-3���ڲ�����
{
    int day_tab[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int k = Leap(y);
	if(y<=0||y>9999) return -1;//���ÿ�����������ж�------------���Բ������
	else if(m>12||m<=0) return -2;//���ÿ�����������ж�------------���Բ������
	else if(m==2&&d>day_tab[m-1]+k) return -3;
	else if((d>day_tab[m-1]&&m!=2)||d<=0) return -3;

	int i = 0,n=1; /* �������ݣ���2010�꣩1��1�������ڼ� */
	for(i=1;i<y;i++)
	{
		if(Leap(i))
			n = (n+366)%7;
		else
			n = (n+365)%7;
	}//for

	/* ������·�1�������ڼ� */
	for(i=1;i<m;i++)
	{
		switch(i)
		{
		case 2:
			if(k)
			{
				n = (n+29)%7;
			}
			else
			{
				n = (n+28)%7;
			}
			break;

		case 4:
		case 6:
		case 9:
		case 11:
			n = (n+30)%7;
			break;

		default:
            n = (n+31)%7;
		} //swtich(i)

	}//for
	/* ��󣬼�����һ�������ڼ� */
	n = (n+d-1)%7;
	return n;
}//Day


int main()
{
	int year = 1,month = 1,day = 1;//����˼��ʼ��
	int i=0,j = 0,k=1,t = 0;//kΪ��������tΪ�������ж�
	int count = 0;//����λ��ʹ��
	char ch;
	char data[15];
//	char *p = data;
	FILE *fp;
	/*
	�ļ���ʽҪ��
	1����ĩ������Ϊ�س�����
	2����ĩ�в��ý���������Ĭ�Ͻ�����������
    3����������ΪX/XX/XX����/��/�գ�
	*/
	if((fp=fopen("test.txt","r"))==NULL)
	{
		printf("cannot open the file\n");
		return 0;
	}


loopwhile:while((ch=fgetc(fp))!=EOF)
	{
	//	fread(data,1,8,fp);
	//	ch=fgetc(fp);
		 year = 0;
		 month = 0;
		 day = 0;
		 i = 0;
		 j = 0;
		 t = 0;
		 count = 0;

//��ȡһ������������:���1-4λ���·ݡ��շ���Ϊ1-2λ��
		for(i = 0;(ch!='\n')&&(ch!='\r')&&(ch!=EOF)&&i<15;i++)
		{
			if((ch<'0'||ch>'9')&&i<=14&&ch!='/')//���ַ���������
			{
				while((ch!='\n')&&(ch!='\r')&&(ch!=EOF))
				{
					data[i] = ch;
					ch = fgetc(fp);
				}
				data[i] = '\0';
				printf("����%d������������(%s)���з������ַ�\n",k++,data);
				goto loopwhile;//������ѭ�������¸�����
			}//if
			else if(ch=='/')//��ȡ����
			{
				switch(t)
				{
				case 0:
					while(j<i)
					{
						year = year*10+(data[j++]-48);
					}
					count = (j>4)?j:count;
					t++;
					data[i] = ch;
					ch = fgetc(fp);
					break;

				case 1:
					for(j = 1;data[i-j]!='/';j++)
					{
						month += (data[i-j]-48)*(int)pow(10,j-1);
					}
					count = (j>3)?j:count;
					t++;
					data[i] = ch;
					ch = fgetc(fp);
				}//switch(t)��ȡ����

			}//if_elseif_else
			else//�������ֱ�Ӵ��
			{
				data[i] = ch;//������ȡ����
				ch=fgetc(fp);
				if(((ch =='\n')||(ch=='\r')||(ch==EOF)||(i==14))&&(t==2))//��ȡ�շ�
				{
					for(j = 1,day = data[i]-48;data[i-j]!='/';j++)
					{
						day = day+(data[i-j]-48)*10;
					}
					count = (j>2)?j:count;
					t=0;
				}
			}


		}//for��ȡһ������


			data[i] = '\0';//�ַ������������

			if(count>0)
				i = -4;
			else
				i = Day(year,month,day);//��������Ϊһ�����ڵڼ���

			switch(i)
			{
			case 0:
				printf("����%d������%s��������\n",k++,data);
				break;

			case 1:
				printf("����%d������%s������һ\n",k++,data);
				break;

			case 2:
				printf("����%d������%s�����ڶ�\n",k++,data);
				break;

			case 3:
				printf("����%d������%s��������\n",k++,data);
				break;

			case 4:
				printf("����%d������%s��������\n",k++,data);
				break;

			case 5:
				printf("����%d������%s��������\n",k++,data);
				break;

			case 6:
				printf("����%d������%s��������\n",k++,data);
				break;

			case -1:
				printf("����%d������%s��ݲ��ں���Χ\n",k++,data);
				break;

			case -2:
				printf("����%d������%s�·ݲ��ں���Χ\n",k++,data);
				break;

			case -3:
				printf("����%d������(%s)�շݲ��ں���Χ\n",k++,data);
				break;

			case -4:
				printf("����%d������(%s)������λ��������Χ\n",k++,data);
			}//switch(i)
	}//while

	fclose(fp);
	return 0;
}
