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
//½¨Á¢¿ÕÕ»
int initstack(SqStack &S)
{
	S.base=(SElemType*)malloc(STACKINITSIZE*sizeof(SElemType));
	if(!S.base)
	return 0;
	S.top=S.base;
	S.stacksize=STACKINITSIZE;
	return 1;
}
//È¡Õ»¶¥ÔªËØ
int Gettop(SqStack S,SElemType &e)
{
	if(S.top==S.base)//Õ»Îª¿Õ
		return 0;
	e=*(S.top-1);
	return 1;
}
//²åÈëÕ»¶¥ÔªËØ
int push(SqStack &S,SElemType e)
{
	if(S.top-S.base>=S.stacksize)
	{
		S.base=(SElemType*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
	if(!S.base)
		return 0;
	S.top=S.base+S.stacksize;//
	S.stacksize+=STACKINCREMENT;
	}//Õ»Âú£¬×·¼Ó¿Õ¼ä
	*S.top++=e;
	return 1;
}
//É¾³ýÕ»¶¥ÔªËØ
int pop(SqStack &S,SElemType &e)
	{
		if(S.top==S.base)
			return 0;
		e=*--S.top;
		return 1;
	}
//Ïú»ÙÕ»
int DestroyStack(SqStack &S)
	{	
		if(!S.base)
		return 0;
		free(&S);
		S.top=S.base=NULL;
		S.stacksize=0;
		return 1;
	}
//ÖÃ¿ÕÕ»
int ClearStack(SqStack &S)
	{
		if(!S.base)
		return 0;
		S.top=S.base;
		return 1;
	}
//ÅÐ¿ÕÕ»
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
			printf("À¨ºÅÕýÈ·Æ¥Åä");
		else
			printf("À¨ºÅÆ¥ÅäÊ§°Ü");
		return 0;
	}

