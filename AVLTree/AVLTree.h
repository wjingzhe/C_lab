#define LH +1 //���
#define EH 0  //�ȸ�
#define RH -1 //�Ҹ�
#define NULL 0 //��Ϊ0
#define MAXSIZE 20
#define INCREAMENT 10
typedef int Status;
typedef struct BSTNode
{
	float data;
	int bf;
	struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;
void R_Rotate(BSTree &p);
void L_Rotate(BSTree &p);
void LeftBalance(BSTree &T);
void RightBalance(BSTree &T);

void ClearTree(BSTree &T);//����T��Ϊ�գ�������T

bool InsertAVL(BSTree &T,float e,bool &taller);
	//����ƽ��Ķ���������T�в����ں�e����ͬ�ؼ��ֵĽ�㣬�����һ������Ԫ��
	//Ϊe���½ڵ㣬������1�����򷵻�0.��������ʹ����������ʧȥƽ�⣬����ƽ����ת����
	//��������taller��ӳT�������

bool SearchAVL(BSTree T,float key,BSTree f,BSTree &p);
//����ƽ�����������key��ȵ�Ԫ�ؽ��,���ҳɹ��򷵻�1��pΪ��λ��ָ�룬���򷵻�0��pΪ��Ӧ�ùҽӵ�λ��

int GetDepthAVL(BSTree T);//��ƽ������������,���ظ߶�

int DeleteAVL(BSTree &T,float key,bool &lower);
//ɾ��ƽ�����������key��ȵ�Ԫ�ؽ�㣬ɾ���ɹ�����1�����ɹ�����0

int TraverseAVL(BSTree T); //�������������ƽ�������T����������״��ʾ������ɹ�����1

int DispAVL(BSTree T,int i); //�԰�͹������������������������ʽ����ӡ��ʾ�ǿ�ƽ����������ɹ�����1

bool IsEmptyTree(BSTree T); //��TΪ�������򷵻�true�����򷵻�false

bool IsAVL(BSTree T);//�ж��Ƿ�Ϊһ��ƽ�������,���򷵻�true�����򷵻�false

void ClearTree(BSTree &T); //���һ��������ɿ�����������true

bool CreateAVL(BSTree &T); // ֻ������T��Ϊ���������ԭ��
bool CreateAVL(BSTree &T,int n); // ���ԭ�����������һ�ú���n����Ч���ݵ�AVL��������ʾ
bool CreateAVL(BSTree &T,float *a,int n);   //�����������������������鳤�ȣ�����һ��AVL��,ȫ��Ԫ�ؾ�Ϊ�����򷵻�false

bool InOrderAVL(BSTree T,bool (*Visit)(float e),float *BSTData,int &i);
//�������ʷ���true��������ĳ���ڵ����ʧ���򷵻�false������ֹ���ʡ�
float* InOrderTraverseAVL(BSTree T,bool (*Visit)(float e)); //����������������ʷ���һ��float�����飬����ӡƽ��������������С�
float* InOrderTraverseAVL(BSTree T,int &i); //����������������ʷ���һ��float�����飬���鳤�ȡ�

bool PreOrderAVL(BSTree T,bool (*Visit)(float e),float *BSTData,int &i);
//�������ʷ���true��������ĳ���ڵ����ʧ���򷵻�false������ֹ���ʡ�

float* PreOrderTraverseAVL(BSTree T,bool (*Visit)(float e)); //ǰ��������������ʷ���һ��float�����飬��ӡ��ʾƽ�������������Ԫ��
float* PreOrderTraverseAVL(BSTree T,int &i);  //ǰ��������������ʷ���һ��float�����飬���鳤��

bool PostOrderAVL(BSTree T,bool (*Visit)(float e),float *BSTData,int &i);
//�������ʷ���true��������ĳ���ڵ����ʧ���򷵻�false������ֹ���ʡ�

float* PostOrderTraverseAVL(BSTree T,bool (*Visit)(float e)); //����������������ʷ���float���飬����ӡƽ��������������С�
float* PostOrderTraverseAVL(BSTree T,int &i);   //����������������ʷ���float���飬�Լ����鳤��


BSTree MergeAVL(BSTree &p,BSTree &q); // �ϲ�����ƽ�������,��������p
bool DistributeAVL(BSTree &p,BSTree &q); //���Ѻ�ĵ�ɭ����������������ƽ���������ԭ����Ԫ�ز���ԭ������������ԭ��ָ������������ԭ������������Ϊ���������

bool PrintfBST(float e);//���ʸýڵ㣬�����������a�У�����true���ڴ�����ʧ���򷵻�false
bool Nothing(float e); //�շ��ʣ�return true;