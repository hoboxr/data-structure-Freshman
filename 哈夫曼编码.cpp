#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define Bit_max 100
#define Value_max 10000
#define Leaf_number_max 5 //叶节点的数量，即要编码的字符的数量(可以修改)
#define Node_number_max Leaf_number_max*2-1 //哈夫曼树总的节点的数量
using namespace std; 
 
char* leaf=(char *)malloc(sizeof(char)*Leaf_number_max);//叶子节点 
int* leafweight=(int *)malloc(sizeof(int)*Leaf_number_max);//叶子节点的权值 
 
typedef struct{
    int bit[Bit_max];//字符的哈弗曼编码
    int length;//字符的哈弗曼编码长度
}HCodeType;
/*
	因采用自底向上的编码方式，
    所以事先不知道编码的长度，就统一地设为n-1，
    从后向前填写编码，start表示编码开始的位置
*/
typedef struct{
    int bit[Bit_max];
    int start;
}tmpHCodeType;
 
typedef struct{
    int weight;
    int parent;
    int lchild;
    int rchild;
}HNodeType;
 
int n=Leaf_number_max;
HNodeType HuffNode[Node_number_max];//定义全局变量和数组自动初始化
HCodeType HuffCode[Leaf_number_max];
tmpHCodeType cd;
 
void Init_Input(){
	printf("The number of Leaves are : %d\n",Leaf_number_max);
	puts("The Leaves are : ");
    for(int i=0;i<Leaf_number_max;++i){
		scanf("%c",leaf+i);
		if(*(leaf+i)==' '){
			scanf("%c",leaf+i);
		}else{
			continue;
		}
    }
    puts("The weight of Leaves are : ");
	for(int i=0;i<Leaf_number_max;++i){
		scanf("%d",leafweight+i);
    }
}
void Make_HuffmanTree(){
    int m1, m2;//m1,m2为构造哈夫曼树不同过程中两个最小权值结点的权值
	int Index_1, Index_2;//Index_1,Index_2为构造哈夫曼树不同过程中两个最小权值结点在数组中的序号
    
    //初始化存放哈夫曼数组的结点
    for (int i = 0; i < 2 * n - 1; i++){
        HuffNode[i].weight = 0;
        HuffNode[i].parent = -1;
        HuffNode[i].lchild = -1;
        HuffNode[i].rchild = -1;
    }
 
    //初始化叶子节点的权值
    for (int i = 0; i < n; i++){
      HuffNode[i].weight=leafweight[i];
    }
 
    //循环构造哈夫曼树，n个叶子结点需要n-1次构建（将两棵树合并为一棵树）
    for (int i = 0; i < n - 1; i++){
        m1 = m2 = Value_max;
        Index_1 = Index_2 = 0;
        //新建立的节点的下标是原来的叶子总结点数+i即n+i
        for (int j = 0; j < n + i; j++){
            //规定左儿子的权值比右儿子小
            //1为最小，2为其次 
            if (HuffNode[j].weight < m1&&HuffNode[j].parent == -1){
                m2 = m1;
                Index_2 = Index_1;
                //因为找到目前看来最小的一个数，故用1保存，1原本存储的为第二小的数，用2保存 
                m1 = HuffNode[j].weight;
                Index_1 = j;
            } else if (HuffNode[j].weight < m2&&HuffNode[j].parent == -1){
                m2 = HuffNode[j].weight;
                Index_2 = j;
            }
        }
        HuffNode[Index_1].parent = n + i;
        HuffNode[Index_2].parent = n + i;
        HuffNode[n + i].weight = HuffNode[Index_1].weight + HuffNode[Index_2].weight;
        HuffNode[n + i].lchild = Index_1;
        HuffNode[n + i].rchild = Index_2;
    }
}
 
//采用自底向上的编码方式，该节点若是左儿子，则为0，若为右儿子则为1
void HuffmanCode(){
    int c, p;
    for (int i = 0; i < n; i++){
        cd.start = n - 1;//刚开始无法确定该字符的编码长度，因此统一设为n-1
        c = i;//当前节点
        p = HuffNode[c].parent;//当前节点的父节点
        while (p != -1){
            if (HuffNode[p].lchild == c){
                cd.bit[cd.start] = 0;//如果该节点是左儿子
            }else{
                cd.bit[cd.start] = 1;//如果该节点是右儿子
            }
            --cd.start;
            c = p;
            p = HuffNode[c].parent;
        }
        int cnt=0;
        for (int j = cd.start + 1; j <= n-1; j++){
            HuffCode[i].bit[cnt++] = cd.bit[j];
        }
        HuffCode[i].length = cnt;
    }
    //打印各个字符的哈弗曼编码
    for (int i = 0; i < n; i++){
        printf("The Huffman code of \"%c\" is : ", leaf[i]);
        for (int j = 0 ; j <HuffCode[i].length ; j++){
            printf("%d", HuffCode[i].bit[j]);
        }
       putchar('\n'); 
    }
}
int main(){
	Init_Input();
    Make_HuffmanTree();
    HuffmanCode();
    return 0;
}
