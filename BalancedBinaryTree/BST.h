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
void ClearTree(BSTree &T)//����T��Ϊ�գ�������T
bool InsertAVL(BSTree &T,float e,bool &taller);
	//����ƽ��Ķ���������T�в����ں�e����ͬ�ؼ��ֵĽ�㣬�����һ������Ԫ��
	//Ϊe���½ڵ㣬������1�����򷵻�0.��������ʹ����������ʧȥƽ�⣬����ƽ����ת����
	//��������taller��ӳT�������

bool SearchAVL(BSTree T,float key,BSTree f,BSTree &p);
//����ƽ�����������key��ȵ�Ԫ�ؽ��,���ҳɹ��򷵻�1��pΪ��λ��ָ�룬���򷵻�0��pΪ��Ӧ�ùҽӵ�λ��

int GetHeightAVL(BSTree T);//��ƽ������������,���ظ߶�

int DeleteAVL(BSTree &T,float key,bool &lower);//ɾ��ƽ�����������key��ȵ�Ԫ�ؽ�㣬ɾ���ɹ�����1�����ɹ�����0

int TraverseAVL(BSTree T,int i); //�������������ƽ�������T����������״��ʾ������ɹ�����1

int DispAVL(BSTree T,int i); //�԰�͹������������������������ʽ����ӡ��ʾ�ǿ�ƽ����������ɹ�����1

bool AVLEmpty(BSTree T); //��TΪ�������򷵻�true�����򷵻�false

bool IsaAVL(BSTree T);//�ж��Ƿ�Ϊһ��ƽ�������,���򷵻�true�����򷵻�false

bool ClearTree(BSTree &T); //���һ��������ɿ�����������true

bool CreateAVL(BSTree &T); // ���ԭ��������ʾ
bool CreateAVL(BSTree &T,int n)//ֻ������T��Ϊ����,���������һ�ú���n����Ч���ݵ�AVL��������ʾ������true
bool CreateAVL(BSTree &T,float *a,int n);   //�����������������������鳤�ȣ�����һ��AVL��,ȫ��Ԫ�ؾ�Ϊ�����򷵻�false

bool InOrderTraverseAVL(BSTree T,bool (*Visit)(float e),float *BSTData,int &i);
//�������ʷ���true��������ĳ���ڵ����ʧ���򷵻�false������ֹ���ʡ�
float* InOrderAVL(BSTree T,bool (*Visit)(float e),int &n); //����������������ʷ���һ��float�����飬����ӡƽ��������������С�
float* InOrderAVL(BSTree T,int &n); //����������������ʷ���һ��float�����飬���鳤�ȡ�

bool PreOrderTraverseAVL(BSTree T,bool (*Visit)(float e),float *BSTData,int &i);
//�������ʷ���true��������ĳ���ڵ����ʧ���򷵻�false������ֹ���ʡ�

float* PreOrderAVL(BSTree T,bool (*Visit)(float e),int &n); //ǰ��������������ʷ���һ��float�����飬��ӡ��ʾƽ�������������Ԫ��
float* PreOrderAVL(BSTree T,int &n);  //ǰ��������������ʷ���һ��float�����飬���鳤��

bool PostOrderTraverseAVL(BSTree T,bool (*Visit)(float e),float *BSTData,int &i);
//�������ʷ���true��������ĳ���ڵ����ʧ���򷵻�false������ֹ���ʡ�

float* PostOrderAVL(BSTree T,bool (*Visit)(float e),int &n); //����������������ʷ���float���飬����ӡƽ��������������С�
float* PostOrderAVL(BSTree T,int &n);   //����������������ʷ���float���飬�Լ����鳤��


BSTree MergeAVL(BSTree &p,BSTree &q); // �ϲ�����ƽ�������,��������p
BSTree DistributeAVL(BSTree &p); //���Ѻ�ĵ�ɭ����������������ƽ���������ԭ����ָ��ԭ������������ԭ������������Ϊ����ֵ

bool PrintfBST(float e);//���ʸýڵ㣬�����������a�У�����true���ڴ�����ʧ���򷵻�false
bool Nothing(float e); //�շ��ʣ�return true;