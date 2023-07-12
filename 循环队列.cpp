#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
typedef int QElemType;
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
//���ٶ���
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

//��ն���
int ClearQueue(SqQueue Q)
{
	Q.rear=Q.front;
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

//�󳤶�
int QueueLength(SqQueue Q)
{
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
} 

//���ͷԪ��
int GetTop(SqQueue Q,int &e)
{
	e=Q.base[Q.front];
	return 1;
}

//����
int EnQueue(SqQueue &Q,int e)
{
	if((Q.rear+1)%MAXSIZE==Q.front)//�ж��Ƿ�ջ�� 
	{
	Q.base=(QElemType*)malloc(MAXSIZE*2*sizeof(QElemType));
	for(int i=0;i<=QueueLength(Q);i++)
	{
		
		Q.base[i]=Q.base[Q.front];
		Q.front=(Q.front+1)%MAXSIZE;
	}
	Q.rear=Q.front;
	Q.front=0; 
	}//������� 
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXSIZE;//���������ת������ͷ�� 
	return 1; 
} 

//ɾ��
int DeQueue(SqQueue &Q,int &e) 
{
	if(Q.front==Q.rear)//�п�
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
	printf("ɾ������%d\n",e);
	printf("��ͷԪ����%d\n",Q.base[Q.front]); 
	GetTop(Q,e);
	printf("��ͷԪ����%d\n",e ); 
	printf("��βԪ����%d\n",Q.base[Q.rear-1]); 
	printf("������%d��Ԫ��\n", QueueLength(Q)); 
	if( QueueEmpty(Q))
		printf("����Ϊ��\n");
	else
		printf("���в�Ϊ��\n");
	DestroyQueue(Q);
		if(!Q.base)
			printf("����������\n");
		else
			printf("����δ����\n");
	return 0;
}































