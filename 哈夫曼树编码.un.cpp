#include<stdio.h>
#include<stdlib.h>
#define bit_max 500
#define value_max 10000
#define Leaf_num_max 5        //此处修改叶子节点数量 
#define Node_num_max Leaf_num_max*2-1
#define Bit_max 100

char* leaf=(char*)malloc(sizeof(char)*Leaf_num_max);//叶子结点 
int* leafweight=(int*)malloc(sizeof(int)*Leaf_num_max);//叶子结点权值

//哈夫曼编码
typedef struct{
	int bit[bit_max];
	int length;
}HCodeType;

//结点
typedef struct{
	int weight;
	int parent;
	int lchild;
	int rchild; 
}HNodeType;

int n=Leaf_num_max;
HCodeType HuffCode[Leaf_num_max];//变量自动初始化 
HNodeType HuffNode[Node_num_max];

//输入结点以及其权值
void initput ()
{
	printf("结点的数量为: %d\n",Leaf_num_max);
	printf("结点分别是:");
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

	
	printf("结点权值分别是：");
	for(int i=0;i<Leaf_num_max;i++)
	{
		scanf("%d",&leafweight[i]);	
	} 
} 


//构造哈夫曼树 
void MakeHuffTree()
{
	int m1, m2;//m1,m2为构造哈夫曼树不同过程中两个最小权值结点的权值
	int Index_1, Index_2;//Index_1,Index_2为构造哈夫曼树不同过程中两个最小权值结点在数组中的序号	
	
	//初始化叶子节点
	for(int i=0;i<2*n-1;i++)
	{
		HuffNode[i].parent=-1;
		HuffNode[i].rchild=-1;
		HuffNode[i].lchild=-1;
		HuffNode[i].weight=0;
	} 
	
	//输入权值
	for(int i=0;i<n;i++)
	{
		HuffNode[i].weight=leafweight[i];
	} 
	
	//结点连结成树
	for(int i=0;i<n-1;i++)//n个结点，构建n-1次
	{
		m1 = m2 = value_max;
		Index_1 = Index_2 = 0;
		for(int j=0;j<n+i;j++)//从0开始，所查找的为0到n+i的所有元素；新的数组下标为n+i
		{
			//规定左孩子为1，右孩子为2
			//左孩子权值小于右孩子
			//m1代表左孩子的序号，m2代表右孩子的序号 
			if(HuffNode[j].weight<m1&&HuffNode[j].parent==-1)
			{
				m2=m1;
				Index_2=Index_1;
				//序号1要承担目前认为最小的元素，故用2来接替1，序号2承担第二小的元素	
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
//因为不知道编码有多长，采用自下而上编码，start为开始的编码位置，末尾为n-1 
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
		while(p!=-1)//c不是根结点                             //操，这里是while一个劲循环，不能是if 
		{
			if(HuffNode[p].lchild==c)
			code.bit[code.start]=0;//左孩子为0 
			else
			code.bit[code.start]=1;//右孩子为1
			 
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
	
	//打印哈夫曼编码
	for(int i=0;i<n;i++)
	{
		printf("%c的哈夫曼编码为：",leaf[i]);
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



 

