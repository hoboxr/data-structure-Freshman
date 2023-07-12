#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode
{
	int data;
	struct BiTNode *rchild,*lchild;
}*BiTree,BiTNode;

void zxbl(BiTree T)
{
	if(T!=NULL)
	{
	zxbl(T->lchild);
	printf("%d ",T->data);
	zxbl(T->rchild);
	}
	return;
}

int BSTsearch(BiTree T,int key)
{
	if(!T)
		return 0;
	else if(T->data==key)
		return 1;
	else if(T->data<key)
		return BSTsearch(T->rchild,key);
	else
		return BSTsearch(T->lchild,key);
}

int BSTinsert(BiTree &T,int key)
{
	if(!T)
	{
		T=(BiTree)malloc(sizeof(BiTNode));
		T->data=key;
		T->lchild=T->rchild=NULL;
		return 1;
	}
	else if(T->data==key)
		return 0;
	else if(T->data<key)
		return BSTinsert(T->rchild,key);
	else
		return BSTinsert(T->lchild,key);
}
int main()
{
	BiTree T;
	T=NULL;
	int s;
	int a[10]={34,45,6,23,5,76,12,76,44,34};
	for(int i=0;i<10;i++)
	{
		BSTinsert(T,a[i]);
	}
	printf("请输入需要查询的数字：\n");
	scanf("%d",&s);
	if(BSTsearch(T,s))
		printf("找到了\n");
	else
		printf("未找到\n");
	printf("递增序列为：");
	zxbl(T);
	return 0;
}

