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

//取第i个元素
int Getelem (linklist L,int i,  ElemType &e)
{
	int j;
	linklist p;
	p=L->next;
	j=1;
	while(p!=NULL &&j<i)
	{
		p=p->next;
		++j;
	}
	if(p==NULL||j>i)
		return 0;
	e=p->data;
	return 1;
}

//在第i个结点插入元素
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
	s->data =e;
	s->next =p->next;
	p->next =s;
	return 1;
}

//删除第i个位置的元素,并用e带回
int listdelete(linklist &L,int i,ElemType &e)
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
	s=p->next;
	p->next=s->next;
	e=s->data;
	free(s);
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



int main()
{
	//初始化
	int i;
	ElemType e;
	linklist L;
	creatlist(L);
	printf("初始化后为:");
	print(L);

	//取第6个数
	i=6;
	Getelem (L,i,e);
	printf("第%d个元素为: %d",i,e);
	printf("\n");

	//在第4位插入34
	i=4;
	e=34;
	listinsert( L, i, e);
	printf("插入第%d位，插入元素为%d，插入后的序列为：",i,e);
	print(L);

	//删除第7位
	i=7;
	listdelete( L, i, e);
	printf("删除第%d位，删除的元素为%d，删除后的序列为：",i,e);
	print(L);
	return 0;
}

