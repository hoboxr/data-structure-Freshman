#include<stdio.h>
#include<stdlib.h>
#define STACKINITSIZE 100
#define	STACKINCREMENT  10
typedef  char SElemType; 
typedef struct{
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;
//������ջ
int initstack(SqStack &S)
{
	S.base=(SElemType*)malloc(STACKINITSIZE*sizeof(SElemType));
	if(!S.base)
	return 0;
	S.top=S.base;
	S.stacksize=STACKINITSIZE;
	return 1;
}
//ȡջ��Ԫ��
int Gettop(SqStack S,SElemType &e)
{
	if(S.top==S.base)//ջΪ��
		return 0;
	e=*(S.top-1);
	return 1;
}
//����ջ��Ԫ��
int push(SqStack &S,SElemType e)
{
	if(S.top-S.base>=S.stacksize)
	{
		S.base=(SElemType*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
	if(!S.base)
		return 0;
	S.top=S.base+S.stacksize;//
	S.stacksize+=STACKINCREMENT;
	}//ջ����׷�ӿռ�
	*S.top++=e;
	return 1;
}
//ɾ��ջ��Ԫ��
int pop(SqStack &S,SElemType &e)
	{
		if(S.top==S.base)
			return 0;
		e=*--S.top;
		return 1;
	}
//����ջ
int DestroyStack(SqStack &S)
	{	
		if(!S.base)
		return 0;
		free(&S);
		S.top=S.base=NULL;
		S.stacksize=0;
		return 1;
	}
//�ÿ�ջ
int ClearStack(SqStack &S)
	{
		if(!S.base)
		return 0;
		S.top=S.base;
		return 1;
	}
//�п�ջ
int StackEmpty(SqStack S)
	{
		if(!S.base)
		return 0;
		if(S.top==S.base)
			return 1;
		else
			return 0;
	}

int main()
	{
		int i=0;
		char e1,e2; 
		SqStack S;
		initstack(S);
		char b[100];
		gets(b);
		while(b[i]!='\0')
		{
			if(b[i]=='('||b[i]=='<'||b[i]=='[')
				push(S,b[i]);
			if(b[i]==')')
			{
				 Gettop(S, e1);
				 if(e1=='(')
					 pop(S,	e2);
				 else
					 break;
			}
			if(b[i]=='>')
			{
				 Gettop(S, e1);
				 if(e1=='<')
					 pop(S,	e2);
				 else
					 break;
			}
			if(b[i]==']')
			{
				 Gettop(S, e1);
				 if(e1=='[')
					 pop(S,	e2);
				 else
					 break;
			}
			i++;
		}
		if(StackEmpty(S))
			printf("������ȷƥ��");
		else
			printf("����ƥ��ʧ��");
		return 0;
	}

