#include<stdio.h>
#define MAXSIZE 20
typedef int SElemType;

//˳��ջ�Ķ���
typedef struct{
	SElemType data[MAXSIZE]; 
	int top;//ջ��ָ��
}SqStack;

//����Ԫ��
int push(SqStack &S,SElemType e)
{
	if(S.top ==MAXSIZE-1)
	return 0;
	S.data[++S.top]=e;
	return 1;
} 
//ɾ��Ԫ��,����e������ֵ 
int pop(SqStack &S,SElemType &e)
{
	if(S.top == -1)
	return 0;
	e=S.data[S.top--];
	return 1;
}

//��ӡ��ջ��Ԫ��
void print(SqStack S)
{
	int i;
	if(S.top == -1)
	return ;
	for(i=0;i<=S.top;i++)
	printf("%d ",S.data[i]);
	printf("\n");
 } 
//��ʼ��һ��ջ
void init(SqStack &S)
{
	S.top=-1;
	for(int i=0;i<4;i++)
	S.data[i]=i+1;
	S.top=3;
} 
int main()
{
	SqStack S;
	SElemType e;
	
	//���Գ�ʼ�� 
	init(S);
	print(S);
	
	//���Բ���
	push(S,5);
	print(S);
	
	//����ɾ��;
	pop(S,e);
	print(S); 
	
	return 0;
}

























































 
