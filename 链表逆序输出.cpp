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


                   /*ÄæĞòÊä³öµİ¹é·½Ê½*/ 
void reverse1(linklist L)
{
	 if(L->next!=NULL)
	 reverse1(L->next);
	 printf("%d ",L->data); 
}
void rprint(linklist L)
{
	if(L->next!=NULL)
	reverse1(L->next);
	printf("\n");
}
                /******************************/ 

				/*¾ÍµØÄæÖÃ£¬¿Õ¼ä¸´ÔÓ¶ÈÎªO1*/
void reverse2(linklist &L)
{
	linklist p,r;
	p=L->next;
	L->next=NULL;
	while(p!=NULL)
	{
		r=p->next;//ÓÃrÔİ´æp£¬·ÀÖ¹Á´¶Ïµô
		p->next=L->next;
		L->next=p;
		p=r	;
	}	
} 
                /******************************/ 
 int main()
{
	int e;
	linklist L;
	creatlinklist(L);
	listinsert(L,1,1);
	listinsert(L,2,2);
	listinsert(L,3,3);
	listinsert(L,4,4);
	listdelete(L,4,e);
	print(L);
	rprint(L);
	reverse2(L);
	print(L);
	return 0;
}











