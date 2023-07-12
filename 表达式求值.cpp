#include<stdio.h>
#include<stdlib.h>
#define STACKINITSIZE 100
#define	STACKINCREMENT  10
typedef  char SElemType1; 
typedef  double SElemType2; 
typedef struct{
	SElemType1 *base;
	SElemType1 *top;
	int stacksize;
}SqStack1;

typedef struct{
	SElemType2 *base;
	SElemType2 *top;
	int stacksize;
}SqStack2;
//建立空栈
int initstack1(SqStack1 &S)
{
	S.base=(SElemType1*)malloc(STACKINITSIZE*sizeof(SElemType1));
	if(!S.base)
	return 0;
	S.top=S.base;
	S.stacksize=STACKINITSIZE;
	return 1;
}
int initstack2(SqStack2 &S)
{
	S.base=(SElemType2*)malloc(STACKINITSIZE*sizeof(SElemType2));
	if(!S.base)
	return 0;
	S.top=S.base;
	S.stacksize=STACKINITSIZE;
	return 1;
}
//取栈顶元素
char Gettop1(SqStack1 S)
{
	SElemType1 e;
	if(S.top==S.base)//栈为空
		return 0;
	e=*(S.top-1);
	return e;
}
SElemType2 Gettop2(SqStack2 S)
{
	SElemType2 e;
	if(S.top==S.base)//栈为空
		return 0;
	e=*(S.top-1);
	return e;
}
//插入栈顶元素
int push1(SqStack1 &S,SElemType1 e)
{
	if(S.top-S.base>=S.stacksize)
	{
		S.base=(SElemType1*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType1));
	if(!S.base)
		return 0;
	S.top=S.base+S.stacksize;//
	S.stacksize+=STACKINCREMENT;
	}//栈满，追加空间
	*S.top++=e;
	return 1;
}
int push2(SqStack2 &S,SElemType2 e)
{
	if(S.top-S.base>=S.stacksize)
	{
		S.base=(SElemType2*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType2));
	if(!S.base)
		return 0;
	S.top=S.base+S.stacksize;//
	S.stacksize+=STACKINCREMENT;
	}//栈满，追加空间
	*S.top++=e;
	return 1;
}
//删除栈顶元素
int pop1(SqStack1 &S,SElemType1 &e)
	{
		if(S.top==S.base)
			return 0;
		e=*--S.top;
		return 1;
	}
int pop2(SqStack2 &S,SElemType2 &e)
	{
		if(S.top==S.base)
			return 0;
		e=*--S.top;
		return 1;
	}
 
//判空栈
int StackEmpty1(SqStack1 S)
	{
		if(!S.base)
		return 0;
		if(S.top==S.base)
			return 1;
		else
			return 0;
	}
int StackEmpty2(SqStack2 S)
	{
		if(!S.base)
		return 0;
		if(S.top==S.base)
			return 1;
		else
			return 0;
	}
int In(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='('||c==')'||c=='#')
		return 1;
	else
		return 0;
}
char precede(char a,char b) 
{
	char result;
	if(a=='+'||a=='-')
	{
		if(b=='+'||b=='-'||b==')'||b=='#')
			result='>';
		else if(b=='*'||b=='/'||b=='(')
			result='<';
	}
	
	else if(a=='*'||a=='/')
	{
		if(b=='+'||b=='-'||b=='*'||b=='/'||b==')'||b=='#')
			result='>';
		else if(b=='(')
			result='<';
	} 
	
	else if(a=='(')
	{
			if(b=='+'||b=='-'||b=='*'||b=='/'||b=='(')
			result='<';
		else if(b==')')
			result='=';	
	}
	
	else if(a==')')
	{
		if(b=='+'||b=='-'||b=='*'||b=='/'||b==')'||b=='#')
			result='>';	
	}
	
	else if(a=='#')
	{
		if(b=='+'||b=='-'||b=='*'||b=='/'||b=='(')
			result='<';	
		else if(b=='#')
			result='=';
	}
	return result;
 } 
SElemType2 operate(SElemType2 a,char theta,SElemType2 b)
{
	SElemType2 c;
	switch(theta){
		case'+': c=a+b;break;
		case'-': c=a-b;break;
		case'/': c=a/b;break;
		case'*': c=a*b;break; 
	}
	return c;
}

double EvaluateExpression()
{
	char c,theta,x;
	SElemType2 a,b;
	SqStack1 OPTR;
	SqStack2 OPND;
	initstack1(OPTR);  push1(OPTR, '#');
	initstack2(OPND);  c=getchar();
	while(c!='#'||Gettop1(OPTR)!='#')
	{
		if(!In(c))
		{
			c=c-'0';
			push2(OPND,c);
			c=getchar();
		}
		else
			switch(precede(Gettop1(OPTR),c)){
			case'<':push1(OPTR,c);
					c=getchar();
					break;
			case'=':pop1(OPTR,x);
					c=getchar();
					break;
			case'>':pop1(OPTR,theta);
					pop2(OPND,b);
					pop2(OPND,a);
					push2(OPND,operate(a,theta,b));
					break;
		}
	}
return Gettop2(OPND);
}

int main()
{
	printf("请输入表达式：\n");
	printf("计算结果为：%lf",EvaluateExpression());
	return 0;
}

