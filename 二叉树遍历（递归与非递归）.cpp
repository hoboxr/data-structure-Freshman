#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
#define BMAXSIZE 100
typedef char SElemType;
typedef char TElemType;
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild,*rchild;	
}BiTNode,*BiTree;
typedef BiTree QElemType;
typedef struct
{
	QElemType *base;
	int front; //头指针 
	int rear; //尾指针 
}SqQueue;

//初始化一个空队列
int InitQueue(SqQueue &Q)
{
	Q.base=(QElemType*)malloc(MAXSIZE *sizeof(QElemType));
	if(!Q.base)
	return 0;
	Q.front=0;
	Q.rear=0;
	return 1;	
} 
//判空
int QueueEmpty(SqQueue Q)
{
	if(Q.front==Q.rear)
		return 1;
	else
		return 0;
}
//插入
int EnQueue(SqQueue &Q,BiTree e)
{
 
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXSIZE;//若到最后则转到数组头部 
	return 1; 
} 

//删除
int DeQueue(SqQueue &Q,BiTree &e) 
{
	if(Q.front==Q.rear)//判空
	return 0;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXSIZE;
	return 1; 
}
 
//顺序栈的定义
typedef struct{
	BiTree data[MAXSIZE]; 
	int top;//栈顶指针
}SqStack;

//插入元素
int push(SqStack &S,BiTree e)
{
	if(S.top ==MAXSIZE-1)
	return 0;
	S.data[++S.top]=e;
	return 1;
} 
//删除元素,并用e返回其值 
int pop(SqStack &S, BiTree &e)
{
	if(S.top == -1)
	return 0;
	e=S.data[S.top--];
	return 1;
}

//初始化一个栈
void init(SqStack &S)
{
	S.top=-1;
	for(int i=0;i<MAXSIZE;i++)
		S.data[i]=0;
} 
//判空
int StackEmpty(SqStack S)
{
	if(S.top==-1)
		return 1;
	return 0;
}

//取栈顶
BiTree GetTop(SqStack S)
{
	return S.data[S.top];
 } 
int visit(TElemType e)
{
	printf("%c",e);
	return 1;
}
 

//构造空二叉树
int InitBiTree(BiTree &T)
{
	T=NULL;
	return 1;
} 


//初始化树
void CreatBiTree(BiTree &T)
{
	TElemType ch;
	if((ch=getchar())!='\n')

	{
		T=(BiTree)malloc(sizeof(BiTNode));
		if(!T)
		return ;
		T->data=ch;
		CreatBiTree(T->lchild);
		CreatBiTree(T->rchild);
	}
	else
		T=NULL;
		
} 


// 前序遍历递归
void PreOrderTraverse(BiTree T)
{
	if(T==NULL)
	return ;
	putchar(T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

//前序遍历非递归
void fisrtbianli(BiTree T)
{
	if(T==NULL) return ;
	SqStack S;
	init(S);
	while(T||!StackEmpty(S))
	{
		if(T)
		{
			visit(T->data);
			push(S,T);
			T=T->lchild;
		}
		else
		{
		pop(S,T); 
		T=T->rchild;
		}
	}
}


//中序遍历
void InOrderTraverse(BiTree T)
{
	if(T==NULL)
	return ;
	InOrderTraverse(T->lchild);
	printf("%c",T->data);
	InOrderTraverse(T->rchild);
 } 
 //中序非递归
void middlebianli(BiTree T)
{
	if(T==NULL) return ;
	SqStack S;
	init(S);
	while(T||!StackEmpty(S))
	{
		if(T)//有左就先进左 
		{
			push(S,T);
			T=T->lchild;
		}
		else
		{
		pop(S,T); 
		visit(T->data);
		T=T->rchild;
		}
	}
}
//后序遍历递归
//是左先遍历左
//当左遍历完，右没有或遍历过，打印当前
//左遍历过，有右遍历右 
void PostOrder(BiTree T)
{
	if(T==NULL)
	return ;
	PostOrder(T->lchild);
	PostOrder(T->rchild);
	printf("%c",T->data);	
}  
//后序遍历非递归
void lastbianli(BiTree T)
{
	if(T==NULL) return ;
	SqStack S;
	init(S);
	BiTree r=NULL;//记录被访问过的结点
	while(T||!StackEmpty(S))
	{
		while(T)//走到最左边 ，有左就去左 
		{
			push(S,T);
			T=T->lchild;
		}
		T=GetTop(S);  
		if(T->rchild!=NULL&&T->rchild!=r)//此节点有右孩子并且右孩子没有被访问过 
			 T=T->rchild; //访问右孩子 
		else
		{
			pop(S,T); 
			visit(T->data);//访问该结点 
			r=T;//记录最近访问的结点 
			T=NULL;//已弹出，重置指针 
		}
	}	
} 
void hxOrder (BiTree T)
{
	if(T==NULL) return ;
	SqStack S,P;
	init(S);
	init(P);
	while(T||!StackEmpty(S))
	{
		if(T)
		{
			push(P,T);
			push(S,T);
			T=T->rchild;
		}
		else
		{
		pop(S,T); 
		T=T->lchild;
		}
	}
	while(!StackEmpty(P))
	{
		pop(P,T);
		visit(T->data);	
	}	 	
}
void LevelOrder(BiTree T)
{
	SqQueue Q;
	InitQueue(Q);
	BiTree p;
	EnQueue(Q,T);
	while(!QueueEmpty(Q))
	{
		DeQueue(Q,p);
		visit(p->data);
		if(p->lchild!=NULL)
		EnQueue(Q,p->lchild);
		if(p->rchild!=NULL)
		EnQueue(Q,p->rchild);
	}		
} 
int main()
{
	BiTree T;
	InitBiTree(T);
	CreatBiTree(T);
	printf("递归前序遍历为");
	PreOrderTraverse(T);
	printf("\n");
	printf("非递归前序遍历为");
	PreOrderTraverse(T);
	printf("\n");
	printf("递归中序遍历为");
	InOrderTraverse(T);
	printf("\n");
	printf("非递归中序遍历为");
	middlebianli(T);
	printf("\n");
	printf("递归中序遍历为");
	PostOrder(T);
	printf("\n");
	printf("递归后序遍历为");
	PostOrder(T);
	printf("\n");
	printf("非递归后序遍历为");
	lastbianli(T);
	printf("\n");
	printf("逆序后序遍历为");
	hxOrder(T);
	printf("\n");
	printf("层序遍历为"); 
	LevelOrder(T);
	printf("\n"); 
	return 0;
}

