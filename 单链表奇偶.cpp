#include<stdio.h>
#include<stdlib.h>
typedef  int ElemType;
typedef struct Node{
	 ElemType data;
	 struct Node *next;
}Node ,*linklist;

void creatlist(linklist &L)
{
	linklist p;
	int i;
	L =(linklist)malloc(sizeof(Node));
	L->next=NULL;
	//初始一个1到10的单链表
	for(i=1;i<=10;i++)
	{
		p = (linklist)malloc(sizeof(Node));//生成一个新结点
		p->data =i;//赋初值
		p->next =L->next;
		L->next =p;//插到表头
	}
}

 
//在第i个位置插入元素
int listinsert(linklist &L,int i,ElemType e)
{
	int j;
	linklist p,s;
	p=L ;
	j=1;
	while(p!=NULL &&j<i)
	{
		p=p->next;
		++j;
	}
	if(p==NULL||j>i)
		return 0;
	s = (linklist)malloc(sizeof(Node));
	s->data=e;
	s->next =p->next;
	p->next =s;
	return 1;
}

//打印出单链表的元素
void print(linklist L)
{
	linklist p;
	p=L->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
void sort(linklist &L)
{
	int t=1;
	linklist p,q;
	q=p=L->next;
	L->next=NULL;//这句话十分重要，相当于把L置空 
	while(p)
	{
		if(p->data%2==1)
		{
			listinsert(L,t,p->data);
			t++;
		}
		p=p->next;
	}
	 while(q)
	{
		if(q->data%2==0)
		{
			listinsert(L,t,q->data);
			t++;
		}
		q=q->next;
	}
	 


	
}
int main()
{
	linklist L;
	creatlist(L);
	print(L);
	sort(L);
	print(L);
	return 0;
}
