#include<iostream>
#include<windows.h>
#include<malloc.h>
#include"AVLTree.h" 
using namespace std;


#define INCREASEMENT 5;
void main()
{
	int i = 0;//�ڼ�����
	int k = 0;//ѭ��������
	int num = 0;//������������
	float *temp;//float�����������ݴ�
	float *BSTData;//float������洢��ƽ��������ж�ȡ��ϵ��
	float key;//float�͵��������ݴ�
	BSTree p;
	bool runCreate = true;
	bool runSearch = true;
	bool runInsert = true;
	bool runDelete = true;
	bool runMerge = true;
	bool runDisp = true;
	bool taller = false;
	bool lower = false;

	int treeMAX = 5;//������������������ʼֵΪ5
	bool *treeFlag = (bool *)malloc(sizeof(bool)*treeMAX);
	int treeCount = 0;
	BSTree *T = (BSTree *)malloc(sizeof(BSTree)*treeMAX);
	for(k = 0;k<treeMAX;k++)
	{
		T[k] = NULL;
		treeFlag[k] = false;
	}
	k = 0;
	
	char ch,c;//ch��Ϊ��ת������,cΪ�鿴��ʱ�����Ļ��������
	bool runMain = true;
	cout<<"---------------���ݽṹ��ƽ�����������ʾ---------------"<<endl;
	cout<<"********************************************************"<<endl;
	cout<<"*****           Press enter to continue         *****"<<endl;
	cout<<"********************************************************"<<endl;
	getchar();
	cout<<"Loading..."<<endl;
	Sleep(1000);
	CreateAVL(T[0]);       //Ĭ�Ϲ���һ�ÿ���
	treeFlag[0] = true;
	treeCount++;

	for(;ch!=12&&ch!=27&&runMain;)
	{
		system("cls");
		cout<<"---------------���ݽṹ��ƽ�����������ʾ---------------"<<endl;
		cout<<"********************************************************"<<endl;
		cout<<endl<<"\t\t0����ʼ��"<<endl;
		cout<<"\t\t1�����ұ���"<<endl;
		cout<<"\t\t2������"<<endl;
		cout<<"\t\t3��ɾ��"<<endl;
		cout<<"\t\t4���ϲ����"<<endl;
		cout<<"\t\t5����ʾ��"<<endl;
		cout<<"\t\t6���˳�"<<endl;
		cout<<endl<<"********************************************************"<<endl;
		cout<<"������Ҫѡ��Ĳ�����";
		cin>>ch;           //����ѡ��

		if('0'<=ch&&ch<='6')//������ȷ����
		{
			switch(ch)
			{
			case '0'://��ʼ��
				runCreate = true;
				for(;runCreate;)
				{//for
					system("cls");
					cout<<"---------------    ƽ�����������ʼ��    ---------------"<<endl;
					cout<<"********************************************************"<<endl;
					cout<<endl;
					cout<<"\t\t1��Ĭ�ϳ�ʼ�����ÿ�����"<<endl;
					cout<<"\t\t2���½�����"<<endl;
					cout<<"\t\t3����λ��������n�����Ԫ�ص�ƽ��������������Ƿǿ�ƽ���������"<<endl;
					cout<<"\t\t4������n��Ԫ�ز��½���ƽ�������"<<endl;
					cout<<"\t\t5��ѡ��Ҫ��������"<<endl;
					cout<<"\t\t6������"<<endl;
					cout<<endl;
					cout<<"********************************************************"<<endl;
					cout<<"������Ҫѡ��Ĳ�����";
					cin>>ch;           //����ѡ��

					if('1'<=ch&&ch<='6')//������ȷ����
					{
						switch(ch)
						{
						case '1'://Ĭ�ϳ�ʼ�����ÿ�����
							if(IsAVL(T[i])&&treeFlag[i])//�ÿ�
							{
								ClearTree(T[i]);
							}
							else 
							{
								treeFlag[i] = true;
								treeCount++;
								ClearTree(T[i]);
							}
							cout<<"��T["<<i<<"]��ʼ���ɹ�"<<endl;
							break;
						case '2'://�½�����
							for(i = 0;treeFlag[i]&&i<treeMAX;i++);//�ҵ���λ��
							if(i>=treeMAX)//�ڴ��������ٴ������ڴ�
							{
								treeMAX+=INCREASEMENT;
								T = (BSTree *)realloc(T,treeMAX);
								treeFlag = (bool *)realloc(treeFlag,treeMAX);
								for(k = i;k<treeMAX;k++)
								{
									T[k] = NULL;
									treeFlag[k] = false;
								}
								k = 0;
							}
							if(CreateAVL(T[i]))
							{
								treeCount++;
								treeFlag[i] = true;
								cout<<"ƽ�������T["<<i<<"]"<<"��ʼ���ɹ�"<<endl;//Ĭ�ϳɹ�
							}
							else
							{
								cout<<"ƽ�������T["<<i<<"]"<<"��ʼ��ʧ��"<<endl;//��T[i]��������ʱ����ʾ�Ƿ�����ؽ����˹�����ʵ�ð汾��ʵ��
								i--;
							}
							Sleep(2000);
							break;

						case '3'://����������ƽ��������Ҳ��ǿض�������ԭ�ؽ�����n�����Ԫ�ص�ƽ�������
							if(!treeFlag[i]||IsAVL(T[i])||IsEmptyTree(T[i]))//�������ƽ������������ʼ����ǰ��Ϊ���������������λ�ý���
							{
								ClearTree(T[i]);
							}
							else //�¸�λ�ý���
							{
								for(i = 0;treeFlag[i]&&i<treeMAX;i++);//�ҵ���λ��
								if(i>=treeMAX)//�ڴ��������ٴ������ڴ�
								{
									treeMAX+=INCREASEMENT;
									T = (BSTree *)realloc(T,treeMAX);
									treeFlag = (bool*)realloc(treeFlag,treeMAX);
									for(k = i;k<treeMAX;k++)
									{
										T[k] = NULL;
										treeFlag[k] = false;
									}//for
									k = 0;
								}//if
							}//if_else

							cout<<"����Ҫ�������ж��ٸ�Ԫ�صĶ�����(n):";
							cin>>num;
							if(CreateAVL(T[i],num))
							{
								treeFlag[i] = true;
								cout<<"ƽ�������T["<<i<<"]"<<"��ʼ���ɹ�"<<endl;//Ĭ�ϳɹ�
							}
							else
							{
								cout<<"ƽ�������T["<<i<<"]"<<"��ʼ��ʧ��"<<endl;//��T[i]��������ʱ����ʾ�Ƿ�����ؽ����˹�����ʵ�ð汾��ʵ��
							}//if_else
							num = 0;//����
							Sleep(2000);
							break;

						case '4'://����n��Ԫ�ز��½���ƽ�������
							for(i = 0;treeFlag[i]&&i<treeMAX;i++);//�ҵ���λ��
							if(i>=treeMAX)//�ڴ��������ٴ������ڴ�
							{
								treeMAX+=INCREASEMENT;
								T = (BSTree *)realloc(T,treeMAX);
								treeFlag = (bool*)realloc(treeFlag,treeMAX);
								for(k = i;k<treeMAX;k++)
								{
									T[k] = NULL;
									treeFlag[k] = false;
								}
								k = 0;
							}//if
							cout<<"����Ҫ�������ж��ٸ�Ԫ�صĶ�����(n):";
							cin>>num;
							temp = (float*)malloc(sizeof(float)*num);
							for(k = 0;k<num;k++)
							{
								cout<<"�������"<<k<<"��Ԫ��:";
								cin>>temp[k];
							}//for
							if(CreateAVL(T[i],temp,num))
							{
								treeCount++;
								treeFlag[i] = true;
								cout<<"ƽ�������T["<<i<<"]"<<"��ʼ���ɹ�"<<endl;//Ĭ�ϳɹ�
							}
							else
							{
								treeCount++;
								treeFlag[i] = true;
								cout<<"ƽ�������T["<<i<<"]"<<"���������ͬԪ��"<<endl;//��T[i]��������ʱ����ʾ�Ƿ�����ؽ����˹�����ʵ�ð汾��ʵ��
							}
							free(temp);//����
							k = 0;
							num = 0;
							Sleep(4000);
							break;

						case '5'://ѡ��Ҫ��������
							cout<<"�ڴ������ܹ���"<<treeCount<<"�ã��������£�"<<endl;
							for(k = 0;k<treeMAX&&treeFlag[k];k++)
							{
								cout<<"�±�Ϊ"<<k<<"������"<<endl;
								TraverseAVL(T[k]);
								cout<<endl;
							}
							cout<<"��ѡ��:";
							cin>>i;
							if(!IsAVL(T[i])||!treeFlag[i])
							{
								cout<<"T["<<i<<"]����һ��ƽ�����������ǵ��ȳ�ʼ��"<<endl;
							}
							else
								cout<<"ѡ��ɹ�����ǰ������ΪT["<<i<<"]"<<endl;
							k = 0;
							Sleep(2000);
							break;
								
						default: //�˳�
							runCreate = false;
						}//switch_��ʼ��
					}//if
					else //������ȷ����
					{
						cout<<"��ѡ����ȷ�Ĳ�������"<<endl;
						Sleep(2000);
					}//if_else

				}//for_runCreate
				break;//switch_ch_runMain

			case '1':            //���ұ���
				if(!IsAVL(T[i])||!treeFlag[i]) 
				{
					cout<<"T["<<i<<"]����һ��ƽ������������ȳ�ʼ��"<<endl;
					Sleep(2000);
					runSearch = false;
					break;
				}
				else
					runSearch = true;

				for(;runSearch;)
				{
					system("cls");
					cout<<"---------------    ƽ������������ұ���  ---------------"<<endl;
					cout<<"********************************************************"<<endl;
					cout<<endl;
					cout<<"\t\t1������"<<endl;
					cout<<"\t\t2���������"<<endl;
					cout<<"\t\t3���������"<<endl;
					cout<<"\t\t4���������"<<endl;
					cout<<"\t\t5������"<<endl;
					cout<<endl;
					cout<<"********************************************************"<<endl;
					cout<<"������Ҫѡ��Ĳ�����";
					cin>>ch;           //����ѡ��

					if('1'<=ch&&ch<='5')//������ȷ����
					{
						switch(ch)
						{
						case '1'://����
							cout<<"������Ҫ���ҵ�Ԫ��:";
							cin>>key;
							if(SearchAVL(T[i],key,T[i],p))
							{
								cout<<"Ԫ��"<<p->data<<"�ĵ�ַ�ǣ�"<<p<<endl;
							}
							else 
							{
								if(p->data>key)
									cout<<"Ԫ��"<<key<<"Ӧ�ò���Ϊ"<<p->data<<"���Һ���"<<endl;
								else 
									cout<<"Ԫ��"<<key<<"Ӧ�ò���Ϊ"<<p->data<<"������"<<endl;
							}
							key = NULL;
							cout<<"Enter a key to continue:";
							cin>>c;;
							break;

						case '2'://�������
							cout<<"��T["<<i<<"]���£�"<<endl;
							TraverseAVL(T[i]);//��״��ʾ
							num = 0;
							BSTData = PreOrderTraverseAVL(T[i],num);
							cout<<"������������"<<endl;
							for(k = 0;k<num-1;k++)
							{
								cout<<BSTData[k]<<"-";
							}
							cout<<BSTData[num-1]<<endl;
							//����
							k = 0;
							num =0;
							free(BSTData);
							BSTData = NULL;
							cout<<"Enter a key to continue:";
							cin>>c;
							break;

						case '3'://�������
							cout<<"��T["<<i<<"]���£�"<<endl;
							TraverseAVL(T[i]);//��״��ʾ��
							num = 0;
							BSTData = InOrderTraverseAVL(T[i],num);
							cout<<"������������"<<endl;
							for(k = 0;k<num-1;k++)
							{
								cout<<BSTData[k]<<"-";
							}
							cout<<BSTData[num-1]<<endl;
							k = 0;//����
							num = 0;
							free(BSTData);
							BSTData = NULL;
							cout<<"Enter a key to continue:";
							cin>>c;
							break;

						case '4'://�������
							cout<<"��T["<<i<<"]���£�"<<endl;
							TraverseAVL(T[i]);//��״��ʾ��
							num = 0;
							BSTData = PostOrderTraverseAVL(T[i],num);
							cout<<"������������"<<endl;
							for(k = 0;k<num-1;k++)
							{
								cout<<BSTData[k]<<"-";
							}
							cout<<BSTData[num-1]<<endl;
							k = 0;//����
							num = 0;
							free(BSTData);
							BSTData = NULL;
							cout<<"Enter a key to continue:";
							cin>>c;
							break;

						default: //�˳�
							runSearch = false;
						}//switch_Search
					}//if
					else //������ȷ����
					{
						cout<<"��ѡ����ȷ�Ĳ�������"<<endl;
						Sleep(2000);
					}//if_else

				}//for_runSearch

				break;//switch_ch_runMain

			case '2'://����
				if(!IsAVL(T[i])||!treeFlag[i])
				{
					cout<<"T["<<i<<"]����һ��ƽ������������ȳ�ʼ��"<<endl;
					Sleep(2000);
					runInsert = false;
					break;
				}
				else
					runInsert = true;
				for(;runInsert;)
				{
					system("cls");
					cout<<"---------------    ƽ�������������      ---------------"<<endl;
					cout<<"********************************************************"<<endl;
					cout<<endl;
					cout<<"\t\t1�����뵥��Ԫ��"<<endl;
					cout<<"\t\t2��������Ԫ��(¼��)"<<endl;
					cout<<"\t\t3��������Ԫ��(���)"<<endl;
					cout<<"\t\t4������"<<endl;
					cout<<endl;
					cout<<"********************************************************"<<endl;
					cout<<"������Ҫѡ��Ĳ�����";
					cin>>ch;           //����ѡ��

					if('1'<=ch&&ch<='4')//������ȷ����
					{
						switch(ch)
						{
						case '1'://���뵥��Ԫ��
							taller = false;
							cout<<"������Ҫ�����Ԫ��:";
							cin>>key;
							if(InsertAVL(T[i],key,taller))
								cout<<"����ɹ�"<<endl;
							else
								cout<<"�Ѵ�����ͬԪ��"<<endl;
							key = NULL;//����
							taller = false;
							Sleep(2000);
							break;

						case '2'://������Ԫ�أ�¼�룩
							cout<<"������Ҫ�����Ԫ�ظ���:";
							cin>>num;
							temp = (float*)malloc(sizeof(float)*num);
							for(k = 0;k<num;k++)
							{
								taller = false;
								cout<<"�������"<<k<<"��Ԫ��:";
								cin>>temp[k];
								if(InsertAVL(T[i],temp[k],taller))
									cout<<"Ԫ��"<<temp[k]<<"����ɹ�"<<endl;
								else
									cout<<"�Ѵ�����ͬԪ��"<<temp[k]<<endl;
							}
						    //����
							k = 0;
							num = 0;
							taller = false;
							free(temp);
							temp = NULL;
							Sleep(2000);
							break;

						case '3'://������Ԫ�أ������
							cout<<"������Ҫ�����Ԫ�ظ���:";
							cin>>num;
							temp = (float*)malloc(sizeof(float)*num);
							for(k = 0;k<num;k++)
							{
								taller = false;
								temp[k] = rand()%100;
								if(InsertAVL(T[i],temp[k],taller))
									cout<<"Ԫ��:"<<temp[k]<<"����ɹ�"<<endl;
								else
									cout<<"�Ѵ�����ͬԪ��:"<<temp[k]<<endl;
							}
							k = 0;
							num = 0;//����
							taller = false;
							free(temp);
							temp = NULL;
							Sleep(2000);
							break;

						default: //�˳�
							runInsert = false;
						}//switch_Insert
					}//if
					else //������ȷ����
					{
						cout<<"��ѡ����ȷ�Ĳ�������"<<endl;
						Sleep(2000);
					}//if_else

				}//for_runInsert

				break;//switch_ch_runMain

			case '3'://ɾ��
				runDelete = true;
				for(;runDelete;)
				{
					system("cls");
					cout<<"---------------    ƽ���������ɾ��      ---------------"<<endl;
					cout<<"********************************************************"<<endl;
					cout<<endl;
					cout<<"\t\t1��ɾ������Ԫ��"<<endl;
					cout<<"\t\t2��ɾ�����Ԫ��"<<endl;
					cout<<"\t\t3�������"<<endl;
					cout<<"\t\t4��������"<<endl;
					cout<<"\t\t5������"<<endl;
					cout<<endl;
					cout<<"********************************************************"<<endl;
					cout<<"������Ҫѡ��Ĳ�����";
					cin>>ch;           //����ѡ��

					if('1'<=ch&&ch<='5')//������ȷ����
					{
						switch(ch)
						{
						case '1'://ɾ������Ԫ��
							if(!IsAVL(T[i])||!treeFlag[i]) 
							{
								cout<<"T["<<i<<"]����һ��ƽ������������ȳ�ʼ��"<<endl;
								Sleep(2000);
								runDelete = false;
								break;
							}
							cout<<"Ŀǰ��T["<<i<<"]���£�"<<endl;
							TraverseAVL(T[i]);//��״��ʾ��
							lower = false;
							cout<<"������Ҫɾ����Ԫ��:";
							cin>>key;
							if(DeleteAVL(T[i],key,lower))
								cout<<"ɾ���ɹ�"<<endl;
							else
								cout<<"��������ͬ��Ԫ��"<<key<<endl;
							key = NULL;//����
							lower = false;
							Sleep(2000);
							break;

						case '2'://ɾ�����Ԫ��
							if(!IsAVL(T[i])||!treeFlag[i]) 
							{
								cout<<"T["<<i<<"]����һ��ƽ������������ȳ�ʼ��"<<endl;
								Sleep(2000);
								runDelete = false;
								break;
							}
							cout<<"Ŀǰ��T["<<i<<"]���£�"<<endl;
							TraverseAVL(T[i]);//��״��ʾ��
							lower = false;
							cout<<"������Ҫɾ����Ԫ�ظ���:";
							cin>>num;
							temp = (float*)malloc(sizeof(float)*num);
							for(k = 0;k<num;k++)
							{
								cout<<"�������"<<k<<"��Ԫ��";
								cin>>temp[k];
								if(DeleteAVL(T[i],temp[k],taller))
									cout<<"Ԫ��"<<temp[k]<<"ɾ���ɹ�"<<endl;
								else
									cout<<"��������ͬԪ��"<<temp[k]<<endl;
							}
							lower = false;//����
							num = 0;
							k = 0;
							free(temp);
							temp = NULL;
							Sleep(2000);
							break;

						case '3'://�����
							cout<<"�ڴ��������£�"<<endl;
							for(k = 0;k<treeMAX&&treeFlag[k];k++)
							{
								cout<<"�±�Ϊ"<<k<<"������"<<endl;
								TraverseAVL(T[k]);
								cout<<endl;
							}
							cout<<"������Ҫ��յ������±꣨��0��ʼ��:";
							cin>>k;
							for(;!IsAVL(T[k])||!treeFlag[k];)
							{
								cout<<"T["<<k<<"]����һ��ƽ��������������������±꣨��0��ʼ��:";
								cin>>k;
							}
							ClearTree(T[k]);//�����
							k = 0;
							cout<<"��ճɹ�"<<endl;
							Sleep(2000);
							break;

						case '4'://������
							cout<<"�ڴ��������£�"<<endl;
							for(k = 0;k<treeMAX&&treeFlag[k];k++)
							{
								cout<<"�±�Ϊ"<<k<<"������"<<endl;
								TraverseAVL(T[k]);
								cout<<endl;
							}
							cout<<"������Ҫ���ٵ������±꣨��0��ʼ��:";
							cin>>k;
							for(;!IsAVL(T[k])||!treeFlag[k];)
							{
								cout<<"T["<<k<<"]����һ��ƽ��������������������±꣨��0��ʼ��:";
								cin>>k;
							}
							ClearTree(T[k]);//�����
							treeFlag[k] = false;
							treeCount--;
							k = 0;
							cout<<"���ٳɹ�"<<endl;
							Sleep(2000);
							break;

						default: //�˳�
							runDelete = false;
						}//switch_Delete
					}//if
					else //������ȷ����
					{
						cout<<"��ѡ����ȷ�Ĳ�������"<<endl;
						Sleep(2000);
					}//if_else

				}//for_runDelete

				break;//switch_ch_runMain

			case '4'://�ϲ����
				runMerge = true;
				for(;runMerge;)
				{
					system("cls");
					cout<<"---------------    ƽ����������ϲ����    ---------------"<<endl;
					cout<<"********************************************************"<<endl;
					cout<<endl;
					cout<<"\t\t1���ϲ�����"<<endl;
					cout<<"\t\t2���ϲ��ڴ��е��ض���������"<<endl;
					cout<<"\t\t3�������"<<endl;
					cout<<"\t\t4������"<<endl;
					cout<<endl;
					cout<<"********************************************************"<<endl;
					cout<<"������Ҫѡ��Ĳ�����";
					cin>>ch;           //����ѡ��

					if('1'<=ch&&ch<='4')//������ȷ����
					{
						switch(ch)
						{
						case '1'://�ϲ����� 
							//��ʾ�ڴ������е���
							cout<<"�ڴ��������£�"<<endl;
							for(k = 0;k<treeMAX&&treeFlag[k];k++)
							{
								cout<<"�±�Ϊ"<<k<<"������"<<endl;
								TraverseAVL(T[k]);
								cout<<endl;
							}
							if(!treeFlag[i]||!IsAVL(T[i]))//�������ƽ������������ʼ����ǰ��Ϊ����������Ѱ�ҿ�λ�ý���
							{
								ClearTree(T[i]);
							}
							else //�¸�λ�ý���
							{
								for(i = 0;treeFlag[i]&&i<treeMAX;i++);//�ҵ���λ��
								if(i>=treeMAX)//�ڴ��������ٴ������ڴ�
								{
									treeMAX+=INCREASEMENT;
									T = (BSTree *)realloc(T,treeMAX);
									treeFlag = (bool*)realloc(treeFlag,treeMAX);
									for(k = i;k<treeMAX;k++)
									{
										T[k] = NULL;
										treeFlag[k] = false;
									}
									k = 0;
								}
							}//if_else
							cout<<"������������Ԫ�ظ���:";
							cin>>num;
							temp = (float*)malloc(sizeof(float)*num);
							for(k = 0;k<num;k++)
							{
								taller = false;
								cout<<"�������"<<k<<"��Ԫ��:";
								cin>>temp[k];
								if(InsertAVL(T[i],temp[k],taller))
									cout<<"Ԫ��"<<temp[k]<<"����ɹ�"<<endl;
								else
									cout<<"�Ѵ�����ͬԪ��"<<temp[k]<<endl;
							}
							cout<<"���������ɹ�"<<endl;
							cout<<"����������Ҫ���������±꣨��0��ʼ��:";
							cin>>k;
							for(;!IsAVL(T[k])||!treeFlag[k];)
							{
								cout<<"T["<<k<<"]����һ��ƽ����������������������±꣨��0��ʼ��:";
								cin>>k;
							}
							MergeAVL(T[k],T[i]);//�ϲ���
							//����
							ClearTree(T[i]);
							k = 0;
							num = 0;
							free(temp);
							temp = NULL;
							cout<<"�ϲ��ɹ�"<<endl;
							Sleep(2000);
							break;

						case '2'://�ϲ��ڴ��е��ض���������
							//��ʾ�ڴ������е���
							cout<<"�ڴ��������£�"<<endl;
							for(k = 0;k<treeMAX&&treeFlag[k];k++)
							{
								cout<<"�±�Ϊ"<<k<<"������"<<endl;
								TraverseAVL(T[k]);
								cout<<endl;
							}

							cout<<"�������������±꣨��0��ʼ��:";
							cin>>k;
							for(;!IsAVL(T[k])||!treeFlag[k];)
							{
								cout<<"T["<<i<<"]����һ��ƽ����������������������±꣨��0��ʼ��:";
								cin>>k;
							}

							cout<<"������������±꣨��0��ʼ��:";
							cin>>num;
							for(;!IsAVL(T[num])||!treeFlag[num];)
							{
								cout<<"T["<<num<<"]����һ��ƽ���������������������±꣨��0��ʼ��:";
								cin>>num;
							}
							MergeAVL(T[k],T[num]);//�ϲ���
							treeFlag[num] = false;
							treeCount--;
							k = 0;//����
							num = 0;
							cout<<"�ϲ��ɹ�"<<endl;
							Sleep(2000);
							break;

						case '3'://�����
							//��ʾ�ڴ������е���
							cout<<"�ڴ��������£�"<<endl;
							for(k = 0;k<treeMAX&&treeFlag[k];k++)
							{
								cout<<"�±�Ϊ"<<k<<"������"<<endl;
								TraverseAVL(T[k]);
								cout<<endl;
							}
							if(!treeFlag[i]||!IsAVL(T[i]))//�������ƽ������������ʼ����ǰ��Ϊ����������������λ�ý���
							{
								ClearTree(T[i]);
							}
							else //�¸�λ�ý���
							{
								for(i = 0;treeFlag[i]&&i<treeMAX;i++);//�ҵ���λ��
								if(i>=treeMAX)//�ڴ��������ٴ������ڴ�
								{
									treeMAX+=INCREASEMENT;
									T = (BSTree *)realloc(T,treeMAX);
									treeFlag = (bool*)realloc(treeFlag,treeMAX);
									for(k = i;k<treeMAX;k++)
									{
										T[k] = NULL;
										treeFlag[k] = false;
									}
									k = 0;
								}
							}//if_else
							cout<<"������Ҫ��ֵ������±꣨��0��ʼ��:";
							cin>>k;
							for(;!IsAVL(T[k])||!treeFlag[k];)
							{
								cout<<"T["<<k<<"]����һ��ƽ��������������������±꣨��0��ʼ��:";
								cin>>k;
							}		
							if(!IsEmptyTree(T[k]))//�ֲ���,ԭ�����������ҽ�Ϊ����ԭ�����ݲ��뵽�������У�����Ϊ����������	
							{
								DistributeAVL(T[k],T[i]);
								treeFlag[i] = true;
								treeCount++;
								cout<<"��ֳɹ�"<<endl;
							}
							else
							{
								cout<<"���ʧ�ܣ����ܲ�ֿ���"<<endl;
							}
							k = 0;
							Sleep(2000);
							break;


						default: //�˳�
							runMerge = false;
						}//switch_Merge
					}//if
					else //������ȷ����
					{
						cout<<"��ѡ����ȷ�Ĳ�������"<<endl;
						Sleep(2000);
					}//if_else

				}//for_runMerge

				break;//switch_ch_runMain

			case '5'://��ʾ��	
				runDisp = true;
				for(;runDisp;)
				{
					system("cls");
					cout<<"---------------    ƽ�����������ʾ      ---------------"<<endl;
					cout<<"********************************************************"<<endl;
					cout<<endl;
					cout<<"\t\t1����ʾ����"<<endl;
					cout<<"\t\t2����ʾ������"<<endl;
					cout<<"\t\t3������"<<endl;
					cout<<endl;
					cout<<"********************************************************"<<endl;
					cout<<"������Ҫѡ��Ĳ�����";
					cin>>ch;           //����ѡ��

					if('0'<=ch&&ch<='3')//������ȷ����
					{
						switch(ch)
						{
						case '1'://��ʾ����			
							cout<<"��ѡ��Ҫ��ʾ�����±�(";
							for(k = 0;!treeFlag[k];k++) ;
							cout<<k;
							for(k++;k<treeMAX&&treeFlag[k];k++)
							{
								cout<<","<<k;
							}
							cout<<"):";

							cout<<"������Ҫ��ʾ�������±꣨��0��ʼ��:";
							cin>>k;
							for(;!IsAVL(T[k])||!treeFlag[k];)
							{
								cout<<"T["<<k<<"]����һ��ƽ����������������������±꣨��0��ʼ��:";
								cin>>k;
							}
							cout<<"��"<<k<<"������"<<endl;
							TraverseAVL(T[k]);
							cout<<endl;
							k = 0;
							num = 0;
							cout<<"Enter a key to continue:";
							cin>>c;
						//	getchar();
							break;

						case '2'://��ʾ������
							//��ʾ�ڴ������е���
							cout<<"�ڴ������ܹ���"<<treeCount<<"�ã��������£�"<<endl;
							for(k = 0;k<treeMAX&&treeFlag[k];k++)
							{
								cout<<"�±�Ϊ"<<k<<"������"<<endl;
								TraverseAVL(T[k]);
								cout<<endl;
							}
							k = 0;
							cout<<"Enter a key to continue:";
							cin>>c;
						//	getchar();
							break;

						default: //�˳�
							runDisp = false;
						}//switch_Disp
					}//if
					else //������ȷ����
					{
						cout<<"��ѡ����ȷ�Ĳ�������"<<endl;
						Sleep(2000);
					}//if_else
				}//for_runDisp
				break;//switch_ch_runMain

			default://�˳�
				runMain = false;
			}//switch_ch_runMain

		}//if
		else //������ȷ����
		{
			cout<<"��ѡ����ȷ�Ĳ�������"<<endl;
			Sleep(2000);
		}//if_else

	}//for_runMain
}//main