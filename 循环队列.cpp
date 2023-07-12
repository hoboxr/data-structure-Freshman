#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
typedef int QElemType;
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
//销毁队列
int DestroyQueue(SqQueue &Q)
{
	if(Q.base)
	{
		free(Q.base);
	Q.base=NULL;
	Q.front=Q.rear=0;
	}
	return 1;
}

//清空队列
int ClearQueue(SqQueue Q)
{
	Q.rear=Q.front;
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

//求长度
int QueueLength(SqQueue Q)
{
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
} 

//求队头元素
int GetTop(SqQueue Q,int &e)
{
	e=Q.base[Q.front];
	return 1;
}

//插入
int EnQueue(SqQueue &Q,int e)
{
	if((Q.rear+1)%MAXSIZE==Q.front)//判断是否栈满 
	{
	Q.base=(QElemType*)malloc(MAXSIZE*2*sizeof(QElemType));
	for(int i=0;i<=QueueLength(Q);i++)
	{
		
		Q.base[i]=Q.base[Q.front];
		Q.front=(Q.front+1)%MAXSIZE;
	}
	Q.rear=Q.front;
	Q.front=0; 
	}//扩充队列 
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXSIZE;//若到最后则转到数组头部 
	return 1; 
} 

//删除
int DeQueue(SqQueue &Q,int &e) 
{
	if(Q.front==Q.rear)//判空
	return 0;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXSIZE;
	return 1; 
}
 

int main()
{
	SqQueue Q;
	int e;
	InitQueue(Q);
	EnQueue(Q,1);
	EnQueue(Q,2);
	EnQueue(Q,4);
	EnQueue(Q,3);
	DeQueue(Q,e);
	printf("删除的是%d\n",e);
	printf("队头元素是%d\n",Q.base[Q.front]); 
	GetTop(Q,e);
	printf("队头元素是%d\n",e ); 
	printf("队尾元素是%d\n",Q.base[Q.rear-1]); 
	printf("队列有%d个元素\n", QueueLength(Q)); 
	if( QueueEmpty(Q))
		printf("队列为空\n");
	else
		printf("队列不为空\n");
	DestroyQueue(Q);
		if(!Q.base)
			printf("队列已销毁\n");
		else
			printf("队列未销毁\n");
	return 0;
}































