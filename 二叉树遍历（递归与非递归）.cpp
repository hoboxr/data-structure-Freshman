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
	int front; //ͷָ�� 
	int rear; //βָ�� 
}SqQueue;

//��ʼ��һ���ն���
int InitQueue(SqQueue &Q)
{
	Q.base=(QElemType*)malloc(MAXSIZE *sizeof(QElemType));
	if(!Q.base)
	return 0;
	Q.front=0;
	Q.rear=0;
	return 1;	
} 
//�п�
int QueueEmpty(SqQueue Q)
{
	if(Q.front==Q.rear)
		return 1;
	else
		return 0;
}
//����
int EnQueue(SqQueue &Q,BiTree e)
{
 
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXSIZE;//���������ת������ͷ�� 
	return 1; 
} 

//ɾ��
int DeQueue(SqQueue &Q,BiTree &e) 
{
	if(Q.front==Q.rear)//�п�
	return 0;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXSIZE;
	return 1; 
}
 
//˳��ջ�Ķ���
typedef struct{
	BiTree data[MAXSIZE]; 
	int top;//ջ��ָ��
}SqStack;

//����Ԫ��
int push(SqStack &S,BiTree e)
{
	if(S.top ==MAXSIZE-1)
	return 0;
	S.data[++S.top]=e;
	return 1;
} 
//ɾ��Ԫ��,����e������ֵ 
int pop(SqStack &S, BiTree &e)
{
	if(S.top == -1)
	return 0;
	e=S.data[S.top--];
	return 1;
}

//��ʼ��һ��ջ
void init(SqStack &S)
{
	S.top=-1;
	for(int i=0;i<MAXSIZE;i++)
		S.data[i]=0;
} 
//�п�
int StackEmpty(SqStack S)
{
	if(S.top==-1)
		return 1;
	return 0;
}

//ȡջ��
BiTree GetTop(SqStack S)
{
	return S.data[S.top];
 } 
int visit(TElemType e)
{
	printf("%c",e);
	return 1;
}
 

//����ն�����
int InitBiTree(BiTree &T)
{
	T=NULL;
	return 1;
} 


//��ʼ����
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


// ǰ������ݹ�
void PreOrderTraverse(BiTree T)
{
	if(T==NULL)
	return ;
	putchar(T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

//ǰ������ǵݹ�
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


//�������
void InOrderTraverse(BiTree T)
{
	if(T==NULL)
	return ;
	InOrderTraverse(T->lchild);
	printf("%c",T->data);
	InOrderTraverse(T->rchild);
 } 
 //����ǵݹ�
void middlebianli(BiTree T)
{
	if(T==NULL) return ;
	SqStack S;
	init(S);
	while(T||!StackEmpty(S))
	{
		if(T)//������Ƚ��� 
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
//��������ݹ�
//�����ȱ�����
//��������꣬��û�л����������ӡ��ǰ
//������������ұ����� 
void PostOrder(BiTree T)
{
	if(T==NULL)
	return ;
	PostOrder(T->lchild);
	PostOrder(T->rchild);
	printf("%c",T->data);	
}  
//��������ǵݹ�
void lastbianli(BiTree T)
{
	if(T==NULL) return ;
	SqStack S;
	init(S);
	BiTree r=NULL;//��¼�����ʹ��Ľ��
	while(T||!StackEmpty(S))
	{
		while(T)//�ߵ������ �������ȥ�� 
		{
			push(S,T);
			T=T->lchild;
		}
		T=GetTop(S);  
		if(T->rchild!=NULL&&T->rchild!=r)//�˽ڵ����Һ��Ӳ����Һ���û�б����ʹ� 
			 T=T->rchild; //�����Һ��� 
		else
		{
			pop(S,T); 
			visit(T->data);//���ʸý�� 
			r=T;//��¼������ʵĽ�� 
			T=NULL;//�ѵ���������ָ�� 
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
	printf("�ݹ�ǰ�����Ϊ");
	PreOrderTraverse(T);
	printf("\n");
	printf("�ǵݹ�ǰ�����Ϊ");
	PreOrderTraverse(T);
	printf("\n");
	printf("�ݹ��������Ϊ");
	InOrderTraverse(T);
	printf("\n");
	printf("�ǵݹ��������Ϊ");
	middlebianli(T);
	printf("\n");
	printf("�ݹ��������Ϊ");
	PostOrder(T);
	printf("\n");
	printf("�ݹ�������Ϊ");
	PostOrder(T);
	printf("\n");
	printf("�ǵݹ�������Ϊ");
	lastbianli(T);
	printf("\n");
	printf("����������Ϊ");
	hxOrder(T);
	printf("\n");
	printf("�������Ϊ"); 
	LevelOrder(T);
	printf("\n"); 
	return 0;
}

