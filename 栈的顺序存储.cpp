#include<stdio.h>
#define MAXSIZE 20
typedef int SElemType;

//顺序栈的定义
typedef struct{
	SElemType data[MAXSIZE]; 
	int top;//栈顶指针
}SqStack;

//插入元素
int push(SqStack &S,SElemType e)
{
	if(S.top ==MAXSIZE-1)
	return 0;
	S.data[++S.top]=e;
	return 1;
} 
//删除元素,并用e返回其值 
int pop(SqStack &S,SElemType &e)
{
	if(S.top == -1)
	return 0;
	e=S.data[S.top--];
	return 1;
}

//打印出栈的元素
void print(SqStack S)
{
	int i;
	if(S.top == -1)
	return ;
	for(i=0;i<=S.top;i++)
	printf("%d ",S.data[i]);
	printf("\n");
 } 
//初始化一个栈
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
	
	//测试初始化 
	init(S);
	print(S);
	
	//测试插入
	push(S,5);
	print(S);
	
	//测试删除;
	pop(S,e);
	print(S); 
	
	return 0;
}

























































 
