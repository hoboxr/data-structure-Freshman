#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define Bit_max 100
#define Value_max 10000
#define Leaf_number_max 5 //Ҷ�ڵ����������Ҫ������ַ�������(�����޸�)
#define Node_number_max Leaf_number_max*2-1 //���������ܵĽڵ������
using namespace std; 
 
char* leaf=(char *)malloc(sizeof(char)*Leaf_number_max);//Ҷ�ӽڵ� 
int* leafweight=(int *)malloc(sizeof(int)*Leaf_number_max);//Ҷ�ӽڵ��Ȩֵ 
 
typedef struct{
    int bit[Bit_max];//�ַ��Ĺ���������
    int length;//�ַ��Ĺ��������볤��
}HCodeType;
/*
	������Ե����ϵı��뷽ʽ��
    �������Ȳ�֪������ĳ��ȣ���ͳһ����Ϊn-1��
    �Ӻ���ǰ��д���룬start��ʾ���뿪ʼ��λ��
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
HNodeType HuffNode[Node_number_max];//����ȫ�ֱ����������Զ���ʼ��
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
    int m1, m2;//m1,m2Ϊ�������������ͬ������������СȨֵ����Ȩֵ
	int Index_1, Index_2;//Index_1,Index_2Ϊ�������������ͬ������������СȨֵ����������е����
    
    //��ʼ����Ź���������Ľ��
    for (int i = 0; i < 2 * n - 1; i++){
        HuffNode[i].weight = 0;
        HuffNode[i].parent = -1;
        HuffNode[i].lchild = -1;
        HuffNode[i].rchild = -1;
    }
 
    //��ʼ��Ҷ�ӽڵ��Ȩֵ
    for (int i = 0; i < n; i++){
      HuffNode[i].weight=leafweight[i];
    }
 
    //ѭ���������������n��Ҷ�ӽ����Ҫn-1�ι��������������ϲ�Ϊһ������
    for (int i = 0; i < n - 1; i++){
        m1 = m2 = Value_max;
        Index_1 = Index_2 = 0;
        //�½����Ľڵ���±���ԭ����Ҷ���ܽ����+i��n+i
        for (int j = 0; j < n + i; j++){
            //�涨����ӵ�Ȩֵ���Ҷ���С
            //1Ϊ��С��2Ϊ��� 
            if (HuffNode[j].weight < m1&&HuffNode[j].parent == -1){
                m2 = m1;
                Index_2 = Index_1;
                //��Ϊ�ҵ�Ŀǰ������С��һ����������1���棬1ԭ���洢��Ϊ�ڶ�С��������2���� 
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
 
//�����Ե����ϵı��뷽ʽ���ýڵ���������ӣ���Ϊ0����Ϊ�Ҷ�����Ϊ1
void HuffmanCode(){
    int c, p;
    for (int i = 0; i < n; i++){
        cd.start = n - 1;//�տ�ʼ�޷�ȷ�����ַ��ı��볤�ȣ����ͳһ��Ϊn-1
        c = i;//��ǰ�ڵ�
        p = HuffNode[c].parent;//��ǰ�ڵ�ĸ��ڵ�
        while (p != -1){
            if (HuffNode[p].lchild == c){
                cd.bit[cd.start] = 0;//����ýڵ��������
            }else{
                cd.bit[cd.start] = 1;//����ýڵ����Ҷ���
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
    //��ӡ�����ַ��Ĺ���������
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
