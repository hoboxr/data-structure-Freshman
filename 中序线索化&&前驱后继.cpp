#include<stdio.h>
#include<stdlib.h>
typedef char TElemType;
typedef struct BiThrNode
{
	TElemType data;
	struct BiThrNode *lchild, *rchild;
	bool Rtag; 
	bool Ltag;
}BiThrNode,*BiThrtree;
BiThrtree pre=NULL;

void initTree(BiThrtree &T)
{
	T=NULL;
}

void CreatBiTree(BiThrtree &T)
{
	TElemType ch;
	if((ch=getchar())!='\n')
	{
		T=(BiThrtree)malloc(sizeof(BiThrNode));
		if(!T)return;
		T->data=ch;
		CreatBiTree(T->lchild);
		CreatBiTree(T->rchild);
	}
	else
		T=NULL;
}
 
void CreateInOrderThrTree(BiThrtree &Root)
{
	static BiThrtree pre=NULL;
	if(Root==NULL)return;
	CreateInOrderThrTree(Root->lchild);
	if(Root->lchild==NULL)
	{
		Root->lchild=pre;
		Root->Ltag=1;
	}
	if(pre!=NULL&&pre->rchild==NULL)
	{
		pre->rchild=Root;
		pre->Rtag=1;
	}
	pre=Root;
	CreateInOrderThrTree(Root->rchild);
}

TElemType FindQQ( BiThrtree p)
{
	if(p==NULL)return -1;
	if(p->Ltag==1)
		pre=p->lchild;
	else
	{
		BiThrtree q=p->lchild;
		while(q!=NULL&&q->Rtag==0)
			q=q->rchild;
		pre=q;
	}
	if(pre)	
		return pre->data;
	else
		return 0;
}
TElemType FindHJ(BiThrtree p)
{
	BiThrtree next=NULL;
	if(p==NULL)return -1;
	if(p->Rtag==1)
		next=p->rchild;
	else
	{
		BiThrtree q=p->rchild;
		while(q!=NULL&&q->Ltag==0)
			q=q->lchild;
		next=q;
	}
	if(next)
		return next->data;
	else
		return 0;
}

int main()
{
	BiThrtree T,p;
	initTree(T);
	CreatBiTree(T);
	CreateInOrderThrTree(T);
	p=T->lchild->lchild;//样例
	if(FindQQ(p))
		printf("前驱为：%c\n", FindQQ(p));
	else
		printf("该结点为中序遍历的首结点，无前驱\n");
	if(FindHJ(p))
		printf("后继为：%c\n", FindHJ(p));
	else
		printf("该结点为中序遍历的尾结点，无后继\n");
	return 0;
}
