#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE  100 
//1代表成功运行，0，-1代表失败 
typedef int ElemType; //ElemType 据情况而定，这里假设为int 
typedef struct{
	int *elem;//数组，存储元素 
	int length;//表长 
	int listsize;//最大的容纳量 
}SqList;
 
void InitList(SqList &L)
//构造一个空的线性表L
{
	L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));//动态分配空间
	L.length=0;//初始不放入数据，表长为0 
	L.listsize=LIST_INIT_SIZE;
}

void Destroy(SqList &L)
//销毁线性表L
{
	free(L.elem);
	L.elem=NULL; 
}
void ClearList(SqList &L)
//清空线性表
{
	L.length=0;
}

int GetElem(SqList L,int i,int &e)
//用e返回L中第i个元素
{
	if(i<1||i>L.length)
		return 0;
	if(!L.elem)
		return -1;
//判断i是否合法 		
	e=L.elem[i-1];
	return 1;
}

int listdelete(SqList &L,int i,int &e)
//删除第i个元素，并用e带回
{
	int j;
	if(i<1||i>L.length)
		return 0;
	if(!L.elem)
		return -1;
	//判断i是否合法 
	e=L.elem[i-1];	
	for(j=i-1;j<L.length-1;j++)     //从第i个元素到倒数第个元素 
	L.elem[j]=L.elem[j+1];          //依次获得其后一个位置的元素值 
	L.length--;//表长随之减少 
	return 1;
}

int listsert(SqList &L,int i,int e)
//在第i个位置插入新的元素e
{
	int j;
	if(i<1||i>L.length+1)
		return 0;
	if(!L.elem)
		return -1;
		//判断i是否合法 
	for(j=L.length-1;j>=i-1;j--)
		L.elem[j+1]=L.elem[j];      //从最后一个元素到第i个元素依次 向后排，空出第i个位置 
		L.elem[i-1]=e;              //在第i个位子上插入e 
	L.length++;                     //表长增加1 
	return 1;
}

void print(SqList L)
//输出表中所有元素 
{
	int i;
	for(i=0;i<L.length;i++)
	printf("%d ",L.elem[i]); 
}

int main()
{
//初始化 	
	SqList L;
	ElemType e=0,i=1,j=1,k=0;
	InitList(L);                           
	printf("初始化L后：L.length=%d\n",L.length);
	
//对表中元素进行初始插入赋值	
	for(i=1,j=1;j<=5,i<=5;i++,j++)
	listsert(L,i,j);                    
	printf("表中数据依次是："); 
	print(L);
	printf("插入数据后：L.length=%d\n",L.length);
	
//测试在第4个位置插入8 
	listsert(L,4,8);                  
	printf("表中数据依次是：");
	print(L);
	printf("插入数据后：L.length=%d\n",L.length);
	
//测试取出第5个位置的数字	
	GetElem(L,5,e);
	printf("第5个数字是:%d\n",e); 
	
//测试删除第2个位置上的元素	
	listdelete(L,2,e);
	printf("删除第2个元素值为：%d ",e);
	printf("表中数据依次是：");
	print(L);
	printf("删除数据后：L.length=%d\n",L.length);
	
//清空表
	ClearList(L);
	printf("清空表后：L.length=%d\n",L.length); 
	
//销毁表
 	Destroy(L);
	if(!L.elem) printf("表已经被销毁");
	else printf("表未被销毁"); 
	return 0;
} 



























