#include<stdio.h>
#include<stdlib.h>
#define bit_max 500
#define value_max 10000
#define Leaf_num_max 5        //�˴��޸�Ҷ�ӽڵ����� 
#define Node_num_max Leaf_num_max*2-1
#define Bit_max 100

char* leaf=(char*)malloc(sizeof(char)*Leaf_num_max);//Ҷ�ӽ�� 
int* leafweight=(int*)malloc(sizeof(int)*Leaf_num_max);//Ҷ�ӽ��Ȩֵ

//����������
typedef struct{
	int bit[bit_max];
	int length;
}HCodeType;

//���
typedef struct{
	int weight;
	int parent;
	int lchild;
	int rchild; 
}HNodeType;

int n=Leaf_num_max;
HCodeType HuffCode[Leaf_num_max];//�����Զ���ʼ�� 
HNodeType HuffNode[Node_num_max];

//�������Լ���Ȩֵ
void initput ()
{
	printf("��������Ϊ: %d\n",Leaf_num_max);
	printf("���ֱ���:");
	for(int i=0;i<Leaf_num_max;i++)
	{
		scanf("%c",leaf+i);
		if(*(leaf+i)==' ')
		{
		scanf("%c",leaf+i);
		}
		else
		continue;
	}
	printf("\n");

	
	printf("���Ȩֵ�ֱ��ǣ�");
	for(int i=0;i<Leaf_num_max;i++)
	{
		scanf("%d",&leafweight[i]);	
	} 
} 


//����������� 
void MakeHuffTree()
{
	int m1, m2;//m1,m2Ϊ�������������ͬ������������СȨֵ����Ȩֵ
	int Index_1, Index_2;//Index_1,Index_2Ϊ�������������ͬ������������СȨֵ����������е����	
	
	//��ʼ��Ҷ�ӽڵ�
	for(int i=0;i<2*n-1;i++)
	{
		HuffNode[i].parent=-1;
		HuffNode[i].rchild=-1;
		HuffNode[i].lchild=-1;
		HuffNode[i].weight=0;
	} 
	
	//����Ȩֵ
	for(int i=0;i<n;i++)
	{
		HuffNode[i].weight=leafweight[i];
	} 
	
	//����������
	for(int i=0;i<n-1;i++)//n����㣬����n-1��
	{
		m1 = m2 = value_max;
		Index_1 = Index_2 = 0;
		for(int j=0;j<n+i;j++)//��0��ʼ�������ҵ�Ϊ0��n+i������Ԫ�أ��µ������±�Ϊn+i
		{
			//�涨����Ϊ1���Һ���Ϊ2
			//����ȨֵС���Һ���
			//m1�������ӵ���ţ�m2�����Һ��ӵ���� 
			if(HuffNode[j].weight<m1&&HuffNode[j].parent==-1)
			{
				m2=m1;
				Index_2=Index_1;
				//���1Ҫ�е�Ŀǰ��Ϊ��С��Ԫ�أ�����2������1�����2�е��ڶ�С��Ԫ��	
				m1=HuffNode[j].weight;
				Index_1=j; 
			}	
			else if(HuffNode[j].weight<m2&&HuffNode[j].parent==-1)
			{
				m2=HuffNode[j].weight;
				Index_2=j;
			}
		}
		HuffNode[n+i].weight=HuffNode[Index_1].weight+HuffNode[Index_2].weight;
		HuffNode[n+i].lchild=Index_1;
		HuffNode[n+i].rchild=Index_2;
		HuffNode[Index_1].parent=n+i;
		HuffNode[Index_2].parent=n+i;	
	} 	
} 
//��Ϊ��֪�������ж೤���������¶��ϱ��룬startΪ��ʼ�ı���λ�ã�ĩβΪn-1 
typedef struct{
	int bit[Bit_max];
	int start;
}HuffmanCodeType;

HuffmanCodeType code;

void MakeHuffCode()
{
	int c,p;
	for(int i=0;i<n;i++)
	{
		code.start=n-1;
		c=i;
		p=HuffNode[c].parent;
		while(p!=-1)//c���Ǹ����                             //�٣�������whileһ����ѭ����������if 
		{
			if(HuffNode[p].lchild==c)
			code.bit[code.start]=0;//����Ϊ0 
			else
			code.bit[code.start]=1;//�Һ���Ϊ1
			 
			code.start--;
			c=p;
			p=HuffNode[c].parent;	
		}
		int cnt=0;
		for(int j=code.start+1;j<n;j++)
		{
			HuffCode[i].bit[cnt++]=code.bit[j];	
		} 
		HuffCode[i].length=cnt;	
	}
	
	//��ӡ����������
	for(int i=0;i<n;i++)
	{
		printf("%c�Ĺ���������Ϊ��",leaf[i]);
		for (int j = 0 ; j <HuffCode[i].length ; j++)
		{
            printf("%d", HuffCode[i].bit[j]); 
	 	}
		 printf("\n");
	}
}

int main()
{
	initput ();
	MakeHuffTree();
	MakeHuffCode();
	return 0;
 } 



 

