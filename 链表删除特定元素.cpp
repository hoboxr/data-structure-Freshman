#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node* next; 
}node,*linklist;

int creatlinklist(linklist &L)
{
	L=(linklist)malloc(sizeof(node));
	L->next=NULL;
	return 1;
} 

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

int listdelete(linklist &L,int i,int &e)
{
	linklist p;
	p=L;
	int j=1;
	while(p!=NULL&&j<i)
	{
		p=p->next;
		j++;
	}
	if(p==NULL||j>i)
	return 0;
	linklist s;
	s=p->next;
	e=s->data;
	p->next=s->next;
	free(s); 
	return 1;
}

int listinsert(linklist &L,int i,int e)
{
	linklist p=L;
	int j=1;
	while(p!=NULL&&j<i)
	{
		p=p->next;
		j++; 
	}
	if(p==NULL||j>i)
	return 0;
	linklist s;
	s=(linklist)malloc(sizeof(node));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return 1;
}
 
int main()
{
	int e;
	linklist L;
	creatlinklist(L);
	listinsert(L,1,1);
	listinsert(L,2,3);
	listinsert(L,3,3);
	listinsert(L,4,3);
	listdelete(L,4,e);
	print(L);
	linklist p;
	p=L->next;
	int j=1;
	print(L);
	while(p!=NULL)
	{
		if(p->data==3)
		{
			listdelete(L,j,e);
			j--;//删除一个元素，数量上少一个，即该位的元素被删除 
		}
		p=p->next;
		j++;
	}
	print(L);
	return 0;
}














